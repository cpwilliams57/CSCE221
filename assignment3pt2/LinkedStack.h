// LinkedStack.h

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
    
template<typename T>
class LinkedStack
{
private:
  /* declare member variables here */
    DoublyLinkedList<T> ll; //T ll?
  
public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };
   
   /* declare rest of functions */
    LinkedStack<T>() {} //default constructor
    bool isEmpty() const {return ll.isEmpty();}
    void push (const T elem) {ll.insertFirst(elem);} //add element to top
    T pop() throw(StackEmptyException);//take element from the top
    T top() const throw (StackEmptyException); //view top element
      
};

/* describe rest of the functions here */

template <typename T>
T LinkedStack<T>::pop() throw(StackEmptyException) {
    if (ll.isEmpty())
        throw StackEmptyException();
    return ll.removeFirst();
}

template <typename T>
T LinkedStack<T>::top() const throw(StackEmptyException) {
    if (ll.isEmpty())
        throw StackEmptyException();
    return ll.first();
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
  //create a copy of the stack, print current element then pop it.
    LinkedStack<T> tempStack = stack;
    while(!tempStack.isEmpty()){
        out << tempStack.top() << " ";
        tempStack.pop();
    }
   return out;
}

#endif
