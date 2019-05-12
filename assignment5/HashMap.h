#ifndef HashMap_h
#define HashMap_h

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

//indivudual student
class student{
private:
    string key;
    string value;
    student *next, *prev;
    friend class LinkedList;
public:
    //constructor
    student(string key, string value){
        this->key = key;
        this->value = value;
    }
};

//list of students
class LinkedList{
protected: student *head, *tail;
    friend class HashMap;
public:
    //default constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    //inserts into back of linked list
    void insertLast(string key ,string value) {
        student* newStudent = new student(key,value);
        if (tail){			// If the list is non-empty
            tail->next = newStudent;
            newStudent->prev = tail;
            tail = newStudent;
        }
        else
            head = tail = newStudent;
    }
    //finds a score based on key
    string findScore(string key) {
        student* Iter = head;
        while ( Iter != NULL ) {
            if (Iter->key == key)
                break;
            Iter = Iter->next;
        }
        return Iter->value;
    }
};


//vector of linked lists 
class HashTable
{
private:
    
    //array storing doubly linked lists
    
    LinkedList* AR;
    
    //Length of the array
    int length;
    
    
    
public:
    
    //constructor
    HashTable(int TableLength = 100);
    //Default length fo the array is 100
    
    //Return array location for corresponding key
    int hash(string key);
    
    //Function declarations
    void InsertItem(string key, string value);
    string Search(string key);
    
    
    //destructor
    ~HashTable();
    
};

//Constructor
HashTable::HashTable(int TableLength)
{
    AR = new LinkedList[TableLength];
    length = TableLength;
}

//Insert item into hash table
void HashTable::InsertItem(string key, string value)
{
    //create hash index from UIN
    int index = hash(key);
    
    //Add line from input.csv to the end of the doubly linked list
    AR[index].insertLast(key,value);
    
    cout << key <<" " << value << endl;
}

//Create hash index from UIN
int HashTable::hash(string UIN)
{
    int index = stoi(UIN) % length;
    
    return index;
}

//Search for item from hash table by key
string HashTable::Search(string key)
{
    int index = hash(key);
    string Item = AR[index].findScore(key);
    if(Item != "null")
        return Item;
    else
        return "NOTFOUND";
}
//destructor
HashTable::~HashTable()
{
    delete [] AR;
}


#endif /* HashMap_h */
