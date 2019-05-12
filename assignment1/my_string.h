//
//  my_string.hpp
//  assignment1
//
//  Created by Cody Williams on 1/19/17.
//  Copyright © 2017 Cody Williams. All rights reserved.
//

#ifndef my_string_h
#define my_string_h

#include <stdio.h>
#include <iostream>

using namespace std;

class my_string{
  
private:
    
    char* ptr;
    int sz;
    int cap;
    void doubleCap();//funstion used to double capacity
    
public:
    
    int size() const;
    int capacity() const;
    bool empty() const;
    char at(int i)const;
    
    char operator[](const int i);
    my_string operator+=(const my_string &obj);
    my_string operator+=(const char &c);
    
    my_string(); // default constructor
    my_string(int n);
    my_string( const my_string &obj); // copy constructor
    ~my_string(); // destructor
    my_string(const char* string);//c-string constructor
    
    my_string& operator = (const my_string&); // copy assignment operator
};

std::ostream& operator<<(std::ostream& os,  const my_string& obj);
std::istream& operator>> (std::istream& is, my_string& obj);

#endif /* my_string_hpp */
