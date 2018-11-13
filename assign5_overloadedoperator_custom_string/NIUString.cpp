/***************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER:Justin Roesner 
LOGON ID:  z1858242 
DUE DATE:  10/30/18 

FUNCTION:  this is the definition class NIUString.cpp 
 *********************************************************************/ 
#include "NIUString.h"
#include <cstring>
using namespace std;

//constructor
//default
NIUString::NIUString(){
    stringSize = 0;
    stringCapacity = 0;
    stringArrayPointer = nullptr;	
}
//constructor with char* passed in
NIUString::NIUString(const char* other){
    stringSize = strlen(other);

    stringCapacity = stringSize;

    if (stringCapacity == 0){
        stringArrayPointer = nullptr;
    }
    else{
        stringArrayPointer = new char[stringCapacity];

        for(int i = 0; i < stringCapacity; i++){
            stringArrayPointer[i] = other[i];	
        }
    }
}
//constructor with NIUString& passed in
NIUString::NIUString(const NIUString& other){
    stringSize = other.size();
    stringCapacity = stringSize;

    if (stringCapacity == 0){
        stringArrayPointer = nullptr;
    }
    else{
        stringArrayPointer = new char[stringCapacity];

        for(int i = 0; i < stringCapacity; i++){
            stringArrayPointer[i] = other[i];	
        }
    }
}
//overloaded = operator to assign one object to another 
NIUString& NIUString::operator=(const NIUString& other){
    if (this == &other){
        return *this;
    }
    stringArrayPointer = nullptr;
    stringSize = other.size();
    stringCapacity = other.capacity();
    if (stringCapacity == 0){
        stringArrayPointer = nullptr;
    }
    else{
        stringArrayPointer = new char[stringCapacity];

        for(int i = 0; i < stringCapacity; i++){
            stringArrayPointer[i] = other[i];	
        }
    }
    return *this;
}
//overloaded = operator to assign a c string to an NIUString object 
NIUString& NIUString::operator=(const char* other){
    stringArrayPointer = nullptr;
    stringSize = strlen(other);
    stringCapacity = stringSize;
    if (stringCapacity == 0){
        stringArrayPointer = nullptr;
    }
    else{
        stringArrayPointer = new char[stringCapacity];
        for(int i = 0; i < stringCapacity; i++){
            stringArrayPointer[i] = other[i];	
        }
    }
    return *this;	
}
//return string capacity
size_t NIUString::capacity() const{
    return stringCapacity;
}
//return string size
size_t NIUString::size() const{
    return stringSize;
}
//check if array is empty
bool NIUString::empty() const{
    if (stringSize == 0){
        return true;
    }
    return false;
}
//clear object
void NIUString::clear(){
    stringSize = 0;
    stringCapacity = 0;
    delete[] stringArrayPointer;
    stringArrayPointer = nullptr;
}
//change string capacity without chaning contents
void NIUString::reserve(size_t n){
    if (n < stringSize || n == stringCapacity){
        return; 
    }
    stringCapacity = n;
    char * tempArrayPointer;
    if (stringCapacity == 0){
        tempArrayPointer = nullptr;
    }
    char* tempArray = new char[stringCapacity];

    for(int i = 0; i < stringCapacity; i++){
        tempArray[i] = stringArrayPointer[i];
    }
    delete[] stringArrayPointer;
    stringArrayPointer = tempArray;
}
//return true if arrays are the same
bool NIUString::operator==(const NIUString& rhs) const{
    if (stringSize != rhs.size()){
        return false;
    }
    for(int i = 0; i < stringSize; i++){
        if (stringArrayPointer[i] != rhs[i]){
            return false;
        }
    }
    return true;
}
//return true if array and c string are the same
bool NIUString::operator==(const char* rhs) const{
    int count=0;
    count = strlen(rhs);	

    if (stringSize != count){
        return false;
    }
    for(int i = 0; i < stringSize; i++){
        if (stringArrayPointer[i] != rhs[i]){
            return false;
        }
    }
    return true;

}
//return pos of string array
const char& NIUString::operator[](size_t pos) const{
    return stringArrayPointer[pos];
}
//return pos of string array
char& NIUString::operator[](size_t pos){
    return stringArrayPointer[pos];
}
//return an ostream of array contents
ostream& operator<<(ostream& lhs, const NIUString& rhs){
    //return formatted ostream
    for (int i=0; i<rhs.size(); i++){
        lhs << rhs[i];
    }
    return lhs;
}
//return true if array and c string are the same
bool operator==(const char* lhs, const NIUString& rhs){
    if (strlen(lhs) != rhs.size()){
        return false;
    }
    for(int i = 0; i < rhs.size(); i++){
        if (lhs[i] != rhs[i]){
            return false;
        }
    }
    return true;

}
