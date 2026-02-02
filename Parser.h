/*
Autor:  Pawel  Pastusiak
Indeks: 248829
Grupa:  PT/N 13:15
Temat:  Kalkulator wyrazen matematycznych i pochodnych
Data:  	02.02.2026
*/

#pragma once
#include <string>
#include "Expression.h"

class Parser
{
public:
    Parser(const std::string& text);
    ~Parser() {}

    Expression* parse();
    static Expression* parseString(const std::string& text);

private:
    std::string text;
    size_t pos;

    enum TokenType { TOK_END, TOK_NUMBER, TOK_VARIABLE, TOK_IDENTIFIER, TOK_ADD, TOK_SUB, TOK_MUL, TOK_DIV, TOK_POW, TOK_LEFT, TOK_RIGHT };
    TokenType tok;
    double numberValue;
    std::string identName;

    void skipWhitespace();
    void nextToken();

    // Gramatyka z priorytetami:
    // expression := term (('+'|'-') term)*
    // term       := power (('*'|'/') power)*
    // power      := factor ('^' power)?    // prawostronna lacznosc
    // factor     := ('+'|'-') factor | number | variable | function | '(' expression ')'
    Expression* parseExpression();
    Expression* parseTerm();
    Expression* parsePower();
    Expression* parseFactor();
};

