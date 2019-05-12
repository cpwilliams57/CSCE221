#include "Parser.h"
#include <string>
#include <iostream>

using namespace std;

//initialize constants, delimiters and precedence table
const char * Parser::delimiters = "+-*/^() ";
const char Parser::opTable[] = {
    '\0', '$', '(', ')', '^', '*', '/', '+', '-', '~' };
const Parser::Precedence Parser::precTable[] = {
    Precedence(0, -1), //END
    Precedence(0, 0), //VALUE
    Precedence(100, 0), //LPAREN
    Precedence(0, 99), //RPAREN
    Precedence(6, 5), //EXP
    Precedence(3, 4), //MULT
    Precedence(3, 4), //DIV
    Precedence(1, 2), //PLUS
    Precedence(1, 2), //MINUS
    Precedence(8, 7) //UNARY_MINUS
};

Parser::EnumTokens Parser::getToken(char c, EnumTokens prevToken)
{ if (c == '\0') return END;
    // token is a delimiter
    if (c == '^') return EXP;
    else if (c == '/') return DIV;
    else if (c == '*') return MULT;
    else if (c == '(') return LPAREN;
    else if (c == ')') return RPAREN;
    else if (c == '+') return PLUS;
    else if (c == '~') return UNARY_MINUS;
    else if (c == '-') {
        if (prevToken == VALUE || prevToken == RPAREN)
            return MINUS;
        else return UNARY_MINUS; //?
    }
    curVal = c; // token is a variable or number
    return VALUE;
}

void Parser::printPostfix() {
    LinkedQueue<string> newpost;
    string item; //?
    while (! postfix.isEmpty()) {
        item = static_cast<string>(postfix.dequeue()); //?
        newpost.enqueue(item);
        cout << item;
    }
    cout << endl;
    postfix = newpost;
}

void Parser::toPostfix( ) {
    int op; char c;
    EnumTokens newToken = END;
    int tokenIndex = 0;
    do { //do-while loop
        c = tokens[tokenIndex++];
        while (c == ' ') c = tokens[tokenIndex++];
        newToken = getToken(c, newToken);
        switch(newToken) {
            case VALUE:
                postfix.enqueue(curVal);
                break;
            case RPAREN: op = opStack.top();
                while (op != LPAREN) {
                    string s(&opTable[op]);
                
                    postfix.enqueue(s.substr(0,1));
                    opStack.pop();
                    op = opStack.top();
                }
                opStack.pop(); //remove LPAREN
                break;
            case END:
                while (! opStack.isEmpty() ) {
                    op = opStack.top();
                    string s(&opTable[op]);
                    postfix.enqueue(s.substr(0,1));
                    opStack.pop();
                }
                break;
            case LPAREN:
                opStack.push(newToken); break;
            case EXP: case DIV:
            case MULT: case PLUS:
            case MINUS: case UNARY_MINUS:
                op = opStack.top();
                while (precTable[newToken].input <=
                       precTable[op].stack) {
                    string s(&opTable[op]);
                    postfix.enqueue(s.substr(0,1));
                    opStack.pop();
                    op = opStack.top();
                }
                opStack.push(newToken); break;
            default:
                cerr << "Invalid token: " << newToken << endl;
                newToken = END;
        }
    } while (newToken != END);
}
