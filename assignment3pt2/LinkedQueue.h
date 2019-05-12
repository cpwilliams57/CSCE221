// LinkedQueue.h

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <iostream>
#include "RuntimeException.h"
#include "TemplatedDoublyLinkedList.h"

template<typename T> class LinkedQueue;

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template<typename T>
class LinkedQueue {
private:
   /* declare member variables here */
    DoublyLinkedList<T> ll;
public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

   /* declare rest of functions */
    LinkedQueue<T>(){} // constructor
    ~LinkedQueue() { } //destructor
    bool isEmpty() const {return ll.isEmpty();}
    T first() throw(QueueEmptyException);
    void enqueue(const T elem){ll.insertLast(elem);}
    T dequeue() throw(QueueEmptyException);
};

/* describe rest of the functions here */
template <typename T>
T LinkedQueue<T>::first( ) throw(QueueEmptyException)
{
    if ( isEmpty() )
        throw QueueEmptyException();
    return ll.first();
}

template <typename T>
T LinkedQueue<T>::dequeue( ) throw(QueueEmptyException)
{ if ( isEmpty() )
    throw QueueEmptyException();
return ll.removeFirst();
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue)
{
  //create a copy of the stack, print current element then pop it.
    LinkedQueue<T> tempQueue = queue;
    while(!tempQueue.isEmpty()){
        out << tempQueue.first() << " ";
        tempQueue.dequeue();
    }
   return out;
}

#endif
