//CSCI 340
//JUSTIN ROESNER
//z1858242
//ASSIGNMENT 4 DRIVER FILE
//DUE 2-26-19

#include <iostream>
#include "assignment4.h"
#include <iomanip>

using namespace std;


//make sure both s1 and s2 are empty
bool Queue::empty() const{	
    //if s1 and s2 are both empty return true 'empty'
    //else return false 'not empty'
    if (s1.empty() && s2.empty()){
        return true;
    }
    else{
        return false;
    }
}

//count the number of elements in s1 and s2
int Queue::size() const{
    int total = 0;
    //add the size of s1 and s2 and return it to find total size
    total = s1.size() + s2.size();
    return total;
}

//return the front of the queue
int Queue::front(){
    //if s2 is empty move all elements from s1 to s2.
    if (s2.empty()){
        while ( !s1.empty() ){
          s2.push(s1.top());
          s1.pop();
        }
    }

    return s2.top();
}

//return the back of the queue
int Queue::back(){
    //return the top element of s1
    //if s1 is empty and some exist in s2 move all elements from s2 to s1 and then check again
    if (s1.empty()){
        s1.swap(s2);
    }
    return s1.top();
}

//add the element to s1
void Queue::push(const int& val){
    s1.push(val);
}

//remove the oldest element 
void Queue::pop(){
     //if s2 is empty move all elements from s1 to s2.
    if (s2.empty()){
        s1.swap(s2);
    }
    s2.pop();
}

int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        if ( q.size() > 0 )
            cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
        else
            cout << setw(3) << q.size() << endl;

        cin >> op;
    }

    while ( !q.empty() )
        q.pop();

    return 0;
}
