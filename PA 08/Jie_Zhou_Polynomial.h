#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>


class Polynomial {
public:
    Polynomial();
    ~Polynomial();
    void addTerm(int coefficient, int exponent);
    void enterTerms();
    void printPolynomial() const;
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

private:
    struct Term {
        int coefficient;
        int exponent;
        Term(int c, int e) : coefficient(c), exponent(e) {}
    };

    std::vector<Term> terms;
    void combineLikeTerms();  // Combines terms with same exponent by adding coefficients
};

#endif