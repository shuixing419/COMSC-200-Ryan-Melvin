#include <iostream> 
#include <stdexcept>
#include <cmath>
#include "Jie_Zhou_RationalNumber.h"
using namespace std;

// Constructor
RationalNumber::RationalNumber(int num, int den) : numerator(num), denominator(den) 
{
    if (denominator == 0) 
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    if (denominator < 0) 
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    reduce();
}

// GCD helper function
int RationalNumber::gcd(int a, int b) 
{
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduce fraction
void RationalNumber::reduce() 
{
    int common = gcd(numerator, denominator);

    numerator /= common;
    denominator /= common;

    if (denominator < 0) 
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Accessor functions
int RationalNumber::getNumerator() const 
{
    return numerator;
}

int RationalNumber::getDenominator() const 
{
    return denominator;
}

// Print function
void RationalNumber::printRational() const 
{
    if (denominator == 1) 
    {
        std::cout << numerator;
    }
    else 
    {
        std::cout << numerator << "/" << denominator;
    }
}

// Arithmetic operators
RationalNumber RationalNumber::operator+(const RationalNumber& right) const 
{
    int num = numerator * right.denominator + right.numerator * denominator;
    int den = denominator * right.denominator;
    return RationalNumber(num, den);
}

RationalNumber RationalNumber::operator-(const RationalNumber& right) const 
{
    int num = numerator * right.denominator - right.numerator * denominator;
    int den = denominator * right.denominator;
    return RationalNumber(num, den);
}

RationalNumber RationalNumber::operator*(const RationalNumber& right) const 
{
    int num = numerator * right.numerator;
    int den = denominator * right.denominator;
    return RationalNumber(num, den);
}

RationalNumber RationalNumber::operator/(const RationalNumber& right) const 
{
    if (right.numerator == 0) 
    {
        throw std::invalid_argument("Division by zero rational number");
    }
    int num = numerator * right.denominator;
    int den = denominator * right.numerator;
    return RationalNumber(num, den);
}

// Assignment operator
RationalNumber& RationalNumber::operator=(const RationalNumber& right) 
{
    if (this != &right) 
    {
        numerator = right.numerator;
        denominator = right.denominator;
    }
    return *this;
}

// Relational operators
bool RationalNumber::operator<(const RationalNumber& right) const 
{
    return (numerator * right.denominator) < (right.numerator * denominator);
}

bool RationalNumber::operator>(const RationalNumber& right) const 
{
    return (numerator * right.denominator) > (right.numerator * denominator);
}

bool RationalNumber::operator<=(const RationalNumber& right) const 
{
    return (numerator * right.denominator) <= (right.numerator * denominator);
}

bool RationalNumber::operator>=(const RationalNumber& right) const 
{
    return (numerator * right.denominator) >= (right.numerator * denominator);
}

bool RationalNumber::operator==(const RationalNumber& right) const 
{
    return (numerator * right.denominator) == (right.numerator * denominator);
}

bool RationalNumber::operator!=(const RationalNumber& right) const 
{
    return (numerator * right.denominator) != (right.numerator * denominator);
}

// Output operator
std::ostream& operator<<(std::ostream& output, const RationalNumber& rational) 
{
    if (rational.getDenominator() == 1) 
    {
        output << rational.getNumerator();
    }
    else 
    {
        output << rational.getNumerator() << "/" << rational.getDenominator();
    }
    return output;
}