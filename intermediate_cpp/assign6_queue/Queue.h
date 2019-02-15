/******************************************
 * PROGRAM	CSCI 241 Assignment 6
 * PROGRAMMER	Justin Roesner
 * Logon ID	z1858242
 * Due date	11/13/2018
 ******************************************/

#ifndef Queue_H
#define Queue_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Queue;

template<class T>
ostream& operator <<(ostream&, const Queue<T>&);

template<class T>
class Queue
{
    friend ostream& operator << <>(ostream&, const Queue<T>&);
    //variables
    private:
    T* queueArray = nullptr;
    size_t queueSize = 0;
    size_t queueCapacity = 0;
    int queueFront = 0;
    int queueBack = -1;


    //constructor
    public:    
    Queue();
    ~Queue();
    Queue(const Queue<T>&);

    //overloaded operators

    //methods
    void clear();
    size_t size()const;
    size_t capacity()const;
    bool empty() const;
    const T& front()const;
    const T& back()const ;
    void push(T&);
    void pop();
    void reserve(size_t);

};
/////////////
//Method Definitions
/////////////

//default constructor
    template <class T>
Queue<T>::Queue()
{
    // empty default since variables are initialized already.
}

//deconstructor
    template <class T>
Queue<T>::~Queue()
{
    delete[] queueArray;
}

//copy constructor
    template <class T>
Queue<T>::Queue(const Queue<T>& other)
{ 

    queueSize = other.size();
    queueCapacity = other.capacity();

    if (queueCapacity == 0)
    {
        queueArray = nullptr;
    }
    else
    {
        queueArray = new T[queueCapacity];

        for(int i=0; i < other.capacity(); i++){
            queueArray[i] = other.queueArray[i];
        }


    }
}

//overloaded << operator for queue object
    template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
    size_t current, i;
    for (current = rhs.queueFront, i = 0; i < rhs.queueSize; ++i)
    {
        lhs << rhs.queueArray[current] << ' ';
        current = (current + 1) % rhs.queueCapacity;
    }
    return lhs;
}

//clear method
template <class T>
void Queue<T>::clear(){
    queueSize = 0;
    queueFront = 0;
    queueBack = queueCapacity -1;
}

//get size of queue
template <class T>
size_t Queue<T>::size() const{
    return queueSize;
}

//get capacity of queue
template <class T>
size_t Queue<T>::capacity()const {
    return queueCapacity;
}

//check if queue is empty
template <class T>
bool Queue<T>::empty() const{
    if (queueSize == 0)
    {
        return true;
    }
    return false;
}

//get the queueFront
template <class T>
const T& Queue<T>::front() const{
    if (queueSize == 0)
    {
        throw underflow_error("stack underflow on call to front()");
    }
    return queueArray[queueFront]; 
}

//get the queueBack
template <class T>
const T& Queue<T>::back() const{
    if (queueSize == 0)
    {
        throw underflow_error("stack underflow on call to back()");
    }
    return queueArray[queueBack]; 
}

//push a thing onto the queue
template <class T>
void Queue<T>::push(T& val){
    if (queueSize == queueCapacity)
    {
        if (queueCapacity == 0)
            reserve(1);
        else
            reserve(queueCapacity * 2);
    }
    queueBack = (queueBack + 1) % queueCapacity;
    queueArray[queueBack] = val;
    ++queueSize;
}

//pop a thing off of the queue
template <class T>
void Queue<T>::pop(){
    if (queueSize == 0){
        throw underflow_error("stack underflow on call to pop()");
    }
    queueFront = (queueFront + 1) % queueCapacity;
    --queueSize;
}

//increase the capacity of the queue
template <class T>
void Queue<T>::reserve(size_t n){
    if (n < queueSize || n == queueCapacity)
        return;

    T* tempQueueArray = new T[queueCapacity];

    int current = queueFront;
    for (size_t i = 0; i < queueSize; i++)
    {
        tempQueueArray[i] = queueArray[current];
        current = (current + 1) % queueCapacity;
    }

    queueCapacity = n;
    queueFront = 0;
    queueBack = queueSize - 1;

    delete[] queueArray;
    queueArray = tempQueueArray;
}

#endif





















