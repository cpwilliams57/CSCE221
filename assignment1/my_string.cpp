//
//  my_string.cpp
//  assignment1
//
//  Created by Cody Williams on 1/19/17.
//  Copyright © 2017 Cody Williams. All rights reserved.
//

#include "my_string.h"
#include <iostream>


using namespace std;

int my_string::size() const {
    return sz;
}

int my_string::capacity() const{
    return cap;
}

bool my_string::empty() const {
    if(this->size() == 0){
        return true;
    }
    else{
        return false;
    }
}

char my_string::at(int i) const{
    
    if ((i < 0) || (i > sz -1)){
        throw out_of_range("i is out of range");
    }
    return ptr[i];//return character at the index i
}

void my_string::doubleCap(){
    cap = cap * 2;
}

//operators
char my_string::operator[](const int i){
    return ptr[i];
}

my_string my_string::operator+=(const my_string &q){
    if (cap == 0){ //check to see if the capacity is zero
        cap = cap + 1;
    }
    while(cap < sz + q.size()){
        this->doubleCap(); // double capacity until it can support added size
    }
    char * temp = new char[cap];
    for(int i = 0; i < this->sz; ++i){
        temp[i] = ptr[i];//copy old values into new array
    }
    for(int i = 0; i < q.size(); ++i){
        temp[sz + i] = q.at(i);//put new values into new array
    }
    sz = sz + q.size();//update size
    delete[] ptr;//delete old array
    ptr = temp;
    return *this;
}

my_string my_string::operator+=(const char &c){
    if (cap == 0){//check to see if capacity is zero
        cap = cap + 1;
    }
    if (cap < sz +1){//double capacity until it can support needed size
        this->doubleCap();
    }
    char * temp = new char[cap];//create array with greater capacity
    for(int i = 0; i < sz; ++i){//copy values into new array
        temp [i] = ptr[i];
    }
    temp[sz] = c;//add char to end of array
    sz = sz + 1;//update size
    delete[] ptr;//delete old array
    ptr = temp;
    return *this;
}

//constructors
//default constructor
my_string::my_string(){
    ptr = nullptr;
    cap = 0;
    sz = 0;
}


my_string::my_string(int n){
    ptr = new char[n];
    cap = n;
    sz = 0;
}

//copy constructor
my_string::my_string(const my_string &obj){
    sz = obj.size();//initialize member variables
    cap = obj.capacity();
    ptr = new char[cap];//create new array and allocate memory
    for(int i =0; i < obj.size(); ++i){//copy values from obj into array
        ptr[i] = obj.at(i);
    }
}

//destructor
my_string::~my_string(){
    delete[] ptr;
}

//C-string constructor
my_string::my_string(const char* string){
    int s = 0;
    while(string[s]!= '\0'){//find size of the c string
        s = s + 1;
    }
    sz = s;////innitialize member variables
    cap = s;
    ptr = new char[cap];//create array and allocate memory
    for(int i = 0; i < sz;++i){//copy characters from c string
        ptr[i] = string[i];
    }
}

//copy assignment operator
my_string& my_string::operator=(const my_string &obj ){
    delete ptr;
    sz = obj.size();
    cap = obj.capacity();
    ptr = new char[cap];
    for(int i = 0; i < sz; ++i){
        ptr[i] = obj.at(i);
    }
    return *this;
}

//overloaded output operator
std::ostream& operator<<(std::ostream& os, const my_string& obj){
    for(int i = 0; i < obj.size(); ++i){
        os << obj.at(i);
    }
    return os;
}

//overloaded input operator
std::istream& operator>> (std::istream& is, my_string& obj){
    char c;
    while((is.get(c)) && (c != ' ') && (c != '\n')){
        obj+= c;
    }
    return is;
}
