#include <iostream>
#include <algorithm>
#include <vector>
#include "Jie_Zhou_Polynomial.h"

using namespace std;

Polynomial::Polynomial() {}

Polynomial::~Polynomial() {}

// Adds term if coefficient is non-zero and combines like terms
void Polynomial::addTerm(int coefficient, int exponent) {
    if (coefficient != 0) {
        terms.push_back(Term(coefficient, exponent));
        combineLikeTerms();
    }
}

// Sorts terms by exponent and combines like terms
void Polynomial::combineLikeTerms() {
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exponent > b.exponent;
        });

    std::vector<Term> combined;
    for (size_t i = 0; i < terms.size(); ++i) {
        if (combined.empty() || combined.back().exponent != terms[i].exponent) {
            combined.push_back(terms[i]);
        }
        else {
            combined.back().coefficient += terms[i].coefficient;
        }
    }
    terms = combined;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(term.coefficient, term.exponent);
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(-term.coefficient, term.exponent);
    }
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        terms = other.terms;
    }
    return *this;
}

// Interactive input for polynomial terms
void Polynomial::enterTerms() {
    int numTerms;
    std::cout << "Enter number of polynomial terms: ";
    std::cin >> numTerms;
    for (int i = 0; i < numTerms; ++i) {
        int coefficient, exponent;
        std::cout << "\nEnter coefficient: ";
        std::cin >> coefficient;
        std::cout << "Enter exponent: ";
        std::cin >> exponent;
        addTerm(coefficient, exponent);
    }
    std::cout << std::endl;
}

// Output stream operator for polynomial printing
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    if (poly.terms.empty()) {
        os << "0";
        return os;
    }

    bool first = true;

    // Handle constant term separately
    for (const auto& term : poly.terms) {
        if (term.exponent == 0) {
            os << term.coefficient;
            first = false;
            break;
        }
    }

    // Print remaining terms with proper formatting
    for (const auto& term : poly.terms) {
        if (term.exponent != 0 && term.coefficient != 0) {
            if (term.coefficient > 0 && !first) {
                os << "+";
            }
            os << term.coefficient;
            if (term.exponent > 1) {
                os << "x^" << term.exponent;
            }
            else if (term.exponent == 1) {
                os << "x";
            }
            first = false;
        }
    }
    return os;
}

void Polynomial::printPolynomial() const {
    std::cout << *this << std::endl;
}