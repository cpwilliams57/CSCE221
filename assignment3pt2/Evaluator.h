#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"

class Evaluator {
private: // exception
    class DivisionByZero : public RuntimeException {
    public: DivisionByZero() :
        RuntimeException("Division by zero") {} };
    Parser *parser; // pointer to the current parser
    LinkedStack<double> valStack; // value stack
    int eval(int v1, int v2, Parser::EnumTokens token)
    throw(DivisionByZero); // two-argument evaluator
    int eval(int v1, Parser::EnumTokens token); // one-arg eval
    bool isOperator(Parser::EnumTokens token);
public: //constructor
    Evaluator (Parser *par) : parser(par), valStack() { }
    int getValue(); // get a value of the expression
};

#endif
