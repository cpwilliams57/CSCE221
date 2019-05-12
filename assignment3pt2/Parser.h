#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <iostream>
#include <string>

class Parser {
    friend class Evaluator;
    
public:
    enum EnumTokens { END, VALUE, LPAREN, RPAREN, EXP,
        MULT, DIV, PLUS, MINUS, UNARY_MINUS };
    
    private: // enum constants
        static const char* delimiters;
        LinkedStack<char> opStack; // operator stack
        LinkedQueue<string> postfix; // postfix queue
        string curVal; // current value
        const char *tokens; // array of tokens
        class Precedence {
        public: int input, stack;
            Precedence(int i=0, int s=0) : input(i), stack(s) {}

   };
static const Precedence precTable[]; //precedence table
static const char opTable[]; // conversion table
    
private:
    EnumTokens getToken(char c,EnumTokens prevToken=VALUE);

public:
    Parser(string s) : opStack(), postfix() {
        // constructor
        tokens = s.c_str(); // convert to a C string
        opStack.push(END); // initialize opStack
    }
    LinkedQueue<string> getPostfix() {return postfix;}
    string getCurVal(){return curVal;}
    void printPostfix();
    void toPostfix();
};

#endif
