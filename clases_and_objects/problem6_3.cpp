#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
   double real; //real part
   double imag; //imaginary part
public:
   Complex(); //default constructor
   Complex(double, double); //argumented constructor
   //overloded arithmeic operators on complex numbers
   Complex operator + (Complex &other) const;
   Complex operator - (Complex &other) const;
   Complex operator * (Complex &other) const;
   Complex operator / (Complex &other) const;
// void operator = (Complex &other);
   void display()const; //displays complex number on the screen
};

#endif


#include "complex.h"

Complex::Complex()
{
   real = 0.0;
   imag = 0.0;
}
Complex::Complex(double a, double b)
{
   real = a;
   imag = b;
}
Complex Complex::operator+(Complex &other)const
{
   Complex c;
   c.real = this->real + other.real;
   c.imag = this->imag + other.imag;
   return c;
}
Complex Complex::operator-(Complex &other)const
{
   Complex c;
   c.real = this->real - other.real;
   c.imag = this->imag - other.imag;
   return c;
}
Complex Complex::operator*(Complex &other)const
{
   Complex c;
   c.real = (this->real * other.real) - (this->imag * other.imag);
   c.imag = (this->imag * other.real) + (this->real * other.imag);
   return c;
}
Complex Complex::operator/(Complex &other)const
{
   Complex c;
   double tmp = (other.real * other.real) + (other.imag * other.imag);
   c.real = (this->real * other.real) + (this->imag * other.imag) / tmp;
   c.imag = (this->imag * other.real) - (this->real * other.imag) / tmp;
   return c;
}
/*void Complex::operator=(Complex &other)
{
   this->real = other.real;
   this->imag = other.imag;
}*/
void Complex::display()const
{
   if (imag < 0)
       cout << real << " - " << abs(imag) << "i";
   else if (imag == 0)
       cout << real;
   else
       cout << real << " + " << imag << "i";
}

#include "complex.h"

int main()
{
   //complex objects
   Complex c1(2, 3), c2(4, -3);
   Complex c3;

   cout << "C1: ";
   c1.display();
   cout << "\nC2: ";
   c2.display();

   //addition
   cout << "\n\nC1 + C2 = ";
   c3 = c1 + c2;
   c3.display();

   //subtraction
   cout << "\nC1 - C2 = ";
   c3 = c1 - c2;
   c3.display();

   //multiplication
   cout << "\nC1 * C2 = ";
   c3 = c1*c2;
   c3.display();

   //division
   cout << "\nC1 / C2 = ";
   c3 = c1 / c2;
   c3.display();
   cout << "\n";
   system("pause");
}
