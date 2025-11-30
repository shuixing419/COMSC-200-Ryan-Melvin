#ifndef Jie_Zhou_RATIONAL_NUMBER_H
#define Jie_Zhou_RATIONAL_NUMBER_H


#include <iostream>

class RationalNumber 
{
public:
    RationalNumber(int num = 0, int den = 1);
    void printRational() const;

    // Accessor functions
    int getNumerator() const;
    int getDenominator() const;

    // Arithmetic operators as member functions
    RationalNumber operator+(const RationalNumber& right) const;
    RationalNumber operator-(const RationalNumber& right) const;
    RationalNumber operator*(const RationalNumber& right) const;
    RationalNumber operator/(const RationalNumber& right) const;

    // Assignment operator
    RationalNumber& operator=(const RationalNumber& right);

    // Relational operators as member functions
    bool operator<(const RationalNumber& right) const;
    bool operator>(const RationalNumber& right) const;
    bool operator<=(const RationalNumber& right) const;
    bool operator>=(const RationalNumber& right) const;
    bool operator==(const RationalNumber& right) const;
    bool operator!=(const RationalNumber& right) const;

private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int a, int b);  // Add this declaration
};

// Output operator as non-member function
std::ostream& operator<<(std::ostream& os, const RationalNumber& r);

#endif