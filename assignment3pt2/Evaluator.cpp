#include "Evaluator.h"
#include <cmath> // used for pow
#include <cctype>
#include <sstream>
#include "Evaluator.h"
#include "RuntimeException.h"
using namespace std;

int Evaluator::eval(int v1, int v2, Parser::EnumTokens token)
throw(DivisionByZero)
{ if (token == Parser::EXP)
    return static_cast<int>(pow(static_cast<double>(v1), v2));
else if (token == Parser::PLUS) {cout << v1 << "+" << v2 << "="; v1 = v1 + v2; cout << v1 << endl; return v1;}
else if (token == Parser::MINUS) {cout << v1 << "-" << v2 << "="; v1 = v1 - v2; cout << v1 << endl; return v1;}
else if (token == Parser::MULT) {cout << v1 << "*" << v2 << "="; v1 = v1 * v2; cout << v1 << endl; return v1;}
else if (token == Parser::DIV)
    if (v2 != 0) {cout << v1 << "/" << v2 << "="; v1 = v1 / v2; cout << v1 << endl; return v1;}
    else throw DivisionByZero();
    return 0;
}

int Evaluator::eval(int v1, Parser::EnumTokens token) {
    if (token == Parser::UNARY_MINUS) return -v1;
    return 0;
}

bool Evaluator::isOperator(Parser::EnumTokens token) {
    return token == Parser::EXP || token == Parser::DIV ||
    token == Parser::MULT || token == Parser::PLUS ||
    token == Parser::MINUS || token == Parser::UNARY_MINUS;
}

int Evaluator::getValue() {
    Parser::EnumTokens token;
    int v1, v2;
    LinkedQueue<string> postfix = parser->getPostfix(); // alias
    while (! postfix.isEmpty()) {
        try { // prevToken is not used here
            if(postfix.first().size() == 1){
            token = parser->getToken(postfix.dequeue().at(0));
            }
        } catch(...) {
            cerr << "postfix queue error " << endl;
        }
        if (isOperator(token)) { // operator
            try {
                if (token == Parser::UNARY_MINUS) {
                    v1 = valStack.pop();
                    valStack.push(eval(v1, token));
                } else {
                    v2 = valStack.pop();
                    v1 = valStack.pop();
                    valStack.push(eval(v1, v2, token));
                }
            } catch(DivisionByZero& e) {
                cerr << e << endl;
                return 0;
            } catch (...) {
                cerr << " " << endl;
                return 0;
            }
        } else if (token != Parser::END) // operand
            try {
                int val = stoi(parser->getCurVal());
//                if (! isdigit(val)) // only digits are accepted
//                    throw RuntimeException("Value is not an integer");
               // val = val - '0'; // replace char with an int value
                valStack.push(val);
            } catch(...) {
                cerr << " " << parser->getCurVal()<< endl;
            }
    } // end while loop
    try {
        return valStack.pop(); // return the final value
    } catch (...) { cerr << "Wrong expression" << endl; }
    return 0;
}
