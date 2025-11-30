#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>

class IntegerSet 
{
private:
    std::vector<bool> set;  // Boolean vector where index represents integer 0-100

public:
    IntegerSet();
    IntegerSet(const int elements[], int size);
    IntegerSet unionOfSets(const IntegerSet& other) const;
    IntegerSet intersectionOfSets(const IntegerSet& other) const;
    void insertElement(int k);
    void deleteElement(int k);
    void printSet() const;
    bool isEqualTo(const IntegerSet& other) const;
    void inputSet();
};

#endif