/*
Autor:  Pawe³  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#include "Parser.h"
#include <cctype>
#include <stdexcept>
#include <string>
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Exponent.h"
#include "Constant.h"
#include "Variable.h"
#include "Sin.h"
#include "Cos.h"
#include "Tan.h"
#include "Ctg.h"
#include "Ln.h"

Parser::Parser(const std::string& t)
{
    text = t;
    pos = 0;
    tok = TOK_END;
    numberValue = 0;
    identName = "";
    nextToken();
}

Expression* Parser::parseString(const std::string& text)
{
    Parser p(text);
    return p.parse();
}

void Parser::skipWhitespace()
{
    while (pos < text.size() && std::isspace(static_cast<unsigned char>(text[pos])))
        ++pos;
}

void Parser::nextToken()
{
    skipWhitespace();
    if (pos >= text.size()) { tok = TOK_END; return; }

    char c = text[pos];

    // funkcja / zmienna (ciag liter)
    if (std::isalpha(static_cast<unsigned char>(c)))
    {
        size_t start = pos;
        while (pos < text.size() && std::isalpha(static_cast<unsigned char>(text[pos])))
            ++pos;
        identName = text.substr(start, pos - start);
        for (char &ch : identName) ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));

        if (identName.size() == 1 && (identName[0] == 'x'))
        {
            tok = TOK_VARIABLE;
        }
        else
        {
            tok = TOK_IDENTIFIER;
        }
        return;
    }

    // liczba
    if (std::isdigit(static_cast<unsigned char>(c)) || (c == '.' && pos + 1 < text.size() && std::isdigit(static_cast<unsigned char>(text[pos+1]))))
    {
        size_t start = pos;
        bool hasDot = false;
        if (text[pos] == '.') { hasDot = true; ++pos; }
        while (pos < text.size() && (std::isdigit(static_cast<unsigned char>(text[pos])) || (!hasDot && text[pos] == '.')))
        {
            if (text[pos] == '.') hasDot = true;
            ++pos;
        }
        std::string numStr = text.substr(start, pos - start);
        try {
            numberValue = std::stod(numStr);
        } catch (...) {
            throw std::runtime_error("Blad parsowania liczby: " + numStr);
        }
        tok = TOK_NUMBER;
        return;
    }

    // pojedyncze znaki
    ++pos;
    switch (c)
    {
    case '+': tok = TOK_ADD; break;
    case '-': tok = TOK_SUB; break;
    case '*': tok = TOK_MUL; break;
    case '/': tok = TOK_DIV; break;
    case '^': tok = TOK_POW; break;
    case '(': tok = TOK_LEFT; break;
    case ')': tok = TOK_RIGHT; break;
    default:
        throw std::runtime_error(std::string("Nieznany znak: ") + c);
    }
}

Expression* Parser::parse()
{
    Expression* expr = parseExpression();
    if (tok != TOK_END)
        throw std::runtime_error("Nieoczekiwany token po zakonczeniu parsowania");
    return expr;
}

Expression* Parser::parseExpression()
{
    Expression* left = parseTerm();
    while (tok == TOK_ADD || tok == TOK_SUB)
    {
        if (tok == TOK_ADD)
        {
            nextToken();
            Expression* right = parseTerm();
            left = new Add(left, right);
        }
        else
        {
            nextToken();
            Expression* right = parseTerm();
            left = new Subtract(left, right);
        }
    }
    return left;
}

Expression* Parser::parseTerm()
{
    Expression* left = parsePower();
    while (tok == TOK_MUL || tok == TOK_DIV)
    {
        if (tok == TOK_MUL)
        {
            nextToken();
            Expression* right = parsePower();
            left = new Multiply(left, right);
        }
        else
        {
            nextToken();
            Expression* right = parsePower();
            left = new Divide(left, right);
        }
    }
    return left;
}

Expression* Parser::parsePower()
{
    Expression* left = parseFactor();
    // prawostronna lacznosc
    if (tok == TOK_POW)
    {
        nextToken();
        Expression* right = parsePower();
        left = new Exponent(left, right);
    }
    return left;
}

Expression* Parser::parseFactor()
{
    if (tok == TOK_ADD)
    {
        nextToken();
        return parseFactor(); // unarny plus
    }
    if (tok == TOK_SUB)
    {
        nextToken();
        Expression* f = parseFactor();
        return new Subtract(new Constant(0), f); // unarny minus jako 0 - f
    }
    if (tok == TOK_NUMBER)
    {
        double v = numberValue;
        nextToken();
        return new Constant(v);
    }
    if (tok == TOK_VARIABLE)
    {
        nextToken();
        return new Variable();
    }
    if (tok == TOK_IDENTIFIER)
    {
        std::string name = identName;
        nextToken(); // consume identifier
        if (tok != TOK_LEFT)
            throw std::runtime_error("Oczekiwano '(' po nazwie funkcji");
        nextToken(); // consume '('
        Expression* arg = parseExpression();
        if (tok != TOK_RIGHT)
            throw std::runtime_error("Oczekiwano ')'");
        nextToken(); // consume ')'

        if (name == "sin")                  return new Sin(arg);
        if (name == "cos")                  return new Cos(arg);
        if (name == "tan" || name == "tg")  return new Tan(arg);
        if (name == "ctg" || name == "cot") return new Ctg(arg);
        if (name == "ln"  || name == "log") return new Ln(arg);

        throw std::runtime_error("Nieznana funkcja: " + name);
    }
    if (tok == TOK_LEFT)
    {
        nextToken(); // consume '('
        Expression* inner = parseExpression();
        if (tok != TOK_RIGHT)
            throw std::runtime_error("Oczekiwano ')'");
        nextToken(); // consume ')'
        return inner;
    }

    throw std::runtime_error("Nieoczekiwany token: oczekiwano liczby, zmiennej, funkcji lub nawiasu");
}
