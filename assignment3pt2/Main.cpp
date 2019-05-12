#include "Parser.h"
#include "Evaluator.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    
    //calculate with variables
    cout << "Does your infix expression include variables? (Y/N)" << endl;
    char ans;
    cin >> ans;
    while(ans != 'Y' && ans != 'N'){
        cout << "invalid answer, please enter Y or N: " << endl;
        cin >> ans;
    }
    
    //get variable value from user
    if( ans == 'Y'){
        char a;
        cout << "enter a value for variable 'a': " << endl;
        cin >> a;
        
        string str;
        cout << "Enter an infix expression: ";
        cin >> str;
        
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == 'a'){
                str[i] = a;
            }
        }
        
        //check if the parenthesis are balanced correctly
        cout << "2) check if parentheis are balanced: " << endl;
        for(int i = 0; i < str.size()-1; ++i){
            if(str[i] == ')' && str[i+1] == '('){
                throw runtime_error("unbalanced parenthesis");
            }
        }
        
        //display correct infix expression
        cout << "3) Display Infix expression: " << str << endl;
        Parser par(str); // new parser
        par.toPostfix(); // convert to postfix form
        
        //display correct postfix expression
        cout << "4) Display Postfix expression: ";
        par.printPostfix(); // print
        
        //Evaluste postfix expression
        cout << "5) Evaluate Postfix expression: ";
        Evaluator e(&par);
        cout << e.getValue();
    }
    
    else{
        //Read an infix expression from the keyboard
        string str;
        cout << "1) Enter an infix expression: ";
        cin >> str;
        
        //check if the parenthesis are balanced correctly
        cout << "2) check if parentheis are balanced: " << endl;
        for(int i = 0; i < str.size()-1; ++i){
            if(str[i] == ')' && str[i+1] == '('){
                throw runtime_error("unbalanced parenthesis");
            }
        }
        
        
        //display correct infix expression
        cout << "3) Display Infix expression: " << str << endl;
        Parser par(str); // new parser
        par.toPostfix(); // convert to postfix form
        
        //display correct postfix expression
        cout << "4) Display Postfix expression: ";
        par.printPostfix(); // print
       
        //Evaluste postfix expression
        cout << "5) Evaluate Postfix expression: ";
        Evaluator e(&par);
        cout << e.getValue();
    }
    

return 0;
}

