/*******************************************
  PROGRAM	CSCI 241 Assignment 5
  PROGRAMMER	Justin Roesner
  LOGON ID 	z1858242
  DUEDATE	10/30/18

  FUNCTION NIUString.h is the header file for NIUString
 *******************************************/


#ifndef NIUString_H
#define NIUString_H
#include<iostream>
using namespace std;
class NIUString
{
    //stand alone functions
    friend ostream& operator<<(ostream& lhs, const NIUString& rhs);
    friend bool operator==(const char* lhs, const NIUString& rhs);	

    //variables
    private:
    char * stringArrayPointer;
    unsigned int stringCapacity;
    unsigned int stringSize;

    public:
    //constructors
    NIUString();
    NIUString(const char* other);
    NIUString(const NIUString& other);
    //~NIUString();

    //overloaded operators
    NIUString& operator=(const NIUString& other);
    NIUString& operator=(const char* other);
    bool operator==(const NIUString& rhs) const; 
    bool operator==(const char* rhs) const; 
    const char& operator[](size_t pos) const;
    char& operator[](size_t pos);

    //methods
    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    void clear();
    void reserve(size_t n);
};

#endif
