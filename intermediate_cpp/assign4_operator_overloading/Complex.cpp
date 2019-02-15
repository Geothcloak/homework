
#include "Complex.h"
using namespace std;
//constructor
//constructor for Complex numbers
Complex::Complex(double realPart, double imaginaryPart){
    this->realPart = realPart;
    this->imaginaryPart = imaginaryPart;	
}

//setters getters
//set the real and imaginary part of the complex number
void Complex::setComplex(double realPart, double imaginaryPart){
    this->realPart = realPart;
    this->imaginaryPart = imaginaryPart;	
}
//set the passed in doubles to the parts of this complex number
void Complex::getComplex(double& realPart, double& imaginaryPart)const{
    realPart = this->realPart;
    imaginaryPart = this->imaginaryPart;	
}
//set the real part of this complex number
void Complex::setRealPart(double realPart){
    this->realPart = realPart;
}
//return the real part of this complex number
double Complex::getRealPart()const{
    return this->realPart;
}
//set imaginary part of this complex number
void Complex::setImaginaryPart(double imaginaryPart){
    this->imaginaryPart = imaginaryPart;	
}
//return the imaginary part of this complex number
double Complex::getImaginaryPart()const{
    return this->imaginaryPart;
}

//operator overload
// + operator for complex numbers
Complex Complex::operator+(const Complex& c1)const{
    double temp;
    Complex tempComplex;	

    //add this realpart of current object with the passed in object
    temp = realPart + c1.getRealPart();
    tempComplex.setRealPart(temp);
    
    //add this imaginary part of the current object with the passed in object
    temp = imaginaryPart + c1.getImaginaryPart();
    tempComplex.setImaginaryPart(temp);

    return tempComplex;	
}
// * operator for complex numbers
Complex Complex::operator*(const Complex& c1)const{
    double temp1;
    double temp2;
    double temp3;
    double temp4;
    Complex tempComplex;	
    
    //foil the two complex numbers
    temp1 = this->realPart * c1.getRealPart();
    temp2 = this->realPart * c1.getImaginaryPart();
    temp3 = this->imaginaryPart * c1.getRealPart();
    temp4 = this->imaginaryPart * c1.getImaginaryPart();
    //because multiplying two imaginary numbers become negative subtract temp4 from temp1
    tempComplex.setRealPart(temp1 - temp4);
    tempComplex.setImaginaryPart(temp2 + temp3);	

    return tempComplex;	
}
// == operator for complex numbers
bool Complex::operator==(const Complex& c1)const{
    //if the real parts and imaginary parts are equal then return true
    if (this->realPart == c1.getRealPart() && this->imaginaryPart == c1.getImaginaryPart()){
        return true;
    }	
    return false;
}
// << operator for complex numbers
ostream& operator<<(ostream& lhs, const Complex& rhs){
    //return a formatted ostream (x, x)
    lhs << '(' << rhs.getRealPart() << ',' << ' ' << rhs.getImaginaryPart() << ')';
    return lhs;
}
// >> operator for complex numbers
istream& operator>>(istream& lhs, Complex& rhs){
    //use temp character to capture non numbers
    //use doubletemp to pass numbers into the complex object
    char temp;
    double doubletemp;
    lhs >> temp >> doubletemp;
    rhs.setRealPart(doubletemp); 
    lhs >> temp >> doubletemp;
    rhs.setImaginaryPart(doubletemp);
    lhs >> temp;
    return lhs;
}
