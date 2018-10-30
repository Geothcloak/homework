#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
    //overloaded functions
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    private:

    //variables
    double realPart;
    double imaginaryPart;
    public:

    //constructors
    Complex(double = 0, double = 0);

    //methods
    //setters and getters
    void setComplex(double, double);
    void getComplex(double&, double&)const;
    void setRealPart(double);
    double getRealPart()const;
    void setImaginaryPart(double);
    double getImaginaryPart()const;
    //operator overload
    Complex operator+(const Complex&) const;
    Complex operator*(const Complex&) const;
    bool operator==(const Complex&) const;



};
#endif
