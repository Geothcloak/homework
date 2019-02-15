/******************************************
  PROGRAM   CSCI 241 Assignment 6
  PROGRAMMER   Justin Roesner
  Logon ID  z1858242
  Due date 11/13/2018
 ******************************************/
#ifndef Stack_H
#define Stack_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
using namespace std;

//forward declaration of stack class
template <class T>
class Stack;

//declare struct node
template <class T>
struct Node
{
    T item;
    Node<T>* next;
    Node(const T& = T(), Node<T>* next = nullptr);
};

//forward declaration for << operator
template <class T>
ostream& operator <<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
    //friend declaration for << operator
    friend ostream& operator<< <>(ostream&, const Stack<T>&);

    //structures
    private:
        size_t stackSize;
        Node<T>* stkTop;

    public:
        //constructors
        Stack();
        ~Stack();
        Stack(const Stack<T>&);
        //methods
        size_t size() const;
        bool empty() const;
        void push(const T&);
        void copyList(const Stack<T>& other);
        void clear();
        void pop();
        const T& top() const;
        //overload operators
        Stack<T>& operator=(const Stack<T>&);

};

///////
//METHOD DEFINITIONS
///////
//default constructor for stack
template <class T>
Stack<T>::Stack()
{
    stkTop = nullptr;
    stackSize = 0;
}

//deconstructor for stack class
template <class T>
Stack<T>::~Stack()
{
    clear();        
}

//copy constructor for stack
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    stkTop = nullptr;
    copyList(other);
    stackSize = other.stackSize;
}

//copy linked list from other to this object.
template <class T>
void Stack<T>::copyList(const Stack<T>& other)
{
    Node<T>* ptr, * newNode, * last = nullptr;
    for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
    {
        newNode = new Node<T>(ptr->item);

        if (last == nullptr)
            stkTop = newNode;
        else
            last->next = newNode;

        last = newNode;
    }
}

//constructor for a new node
template <class T>
Node<T>::Node(const T& item, Node<T>* next)
{
    this->item = item;
    this->next = next;
}
//getter for stackSize
template <class T>
size_t Stack<T>::size() const
{
    return stackSize;
}

//overload << operator for the entire stack class
template <class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
Node<T>* ptr;
    
for (ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
   lhs << ptr->item << ' ';
       
return lhs;
}

//check if stack is empty
template <class T>
bool Stack<T>::empty() const
{
    if(size() == 0)
        return true;
    
    return false;
}

//push new item at top of stack
template <class T>
void Stack<T>::push(const T& item)
{
    Node<T>* newNode = new Node<T>(item, stkTop);

    stkTop = newNode;
    ++stackSize;
}

//pop until stack is empty
template <class T>
void Stack<T>::clear()
{
    while(empty()==false)
    {
        pop();
    }
}

//pop top node off of linked list
template <class T>
void Stack<T>::pop()
{
   if(empty())
       throw runtime_error("cant pop is empty. line 167");

   Node<T>* delNode = stkTop;
   stkTop = stkTop->next;

   delete delNode;
   --stackSize;
}

//overload = operator
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if(this != &other)
    {
        clear();
        copyList(other);
        stackSize = other.stackSize;
    }
    return *this;
}

//return the top of the stack
template <class T>
const T& Stack<T>::top() const
{
   if(empty())
       throw runtime_error("cant get top is empty. line 194");

   return stkTop->item; 
}

#endif
