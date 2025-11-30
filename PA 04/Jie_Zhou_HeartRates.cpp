#include <iostream>
#include <string>
#include <utility>
#include "Jie_Zhou_HeartRates.h"

using namespace std;

// Constructor
HeartRates::HeartRates(const std::string& firstName, const std::string& lastName,
    int birthMonth, int birthDay, int birthYear)
    : firstName(firstName), lastName(lastName), birthMonth(birthMonth),
    birthDay(birthDay), birthYear(birthYear)
{
}

// Setters and getters
void HeartRates::setFirstName(const std::string& firstName) 
{
    this->firstName = firstName;
}

std::string HeartRates::getFirstName() const 
{
    return firstName;
}

void HeartRates::setLastName(const std::string& lastName) 
{
    this->lastName = lastName;
}

std::string HeartRates::getLastName() const 
{
    return lastName;
}

void HeartRates::setBirthMonth(int birthMonth) 
{
    this->birthMonth = birthMonth;
}

int HeartRates::getBirthMonth() const 
{
    return birthMonth;
}

void HeartRates::setBirthDay(int birthDay) 
{
    this->birthDay = birthDay;
}

int HeartRates::getBirthDay() const 
{
    return birthDay;
}

void HeartRates::setBirthYear(int birthYear) 
{
    this->birthYear = birthYear;
}

int HeartRates::getBirthYear() const 
{
    return birthYear;
}

// Calculate age based on current date
int HeartRates::getAge(int currentMonth, int currentDay, int currentYear) const 
{
    int age = currentYear - birthYear;
    // Adjust age if birthday hasn't occurred yet this year
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) 
    {
        age--;
    }
    return age;
}

// Calculate maximum heart rate (220 - age)
int HeartRates::getMaximumHeartRate(int age) const 
{
    return 220 - age;
}

// Calculate target heart rate range (50-85% of max)
std::pair<int, int> HeartRates::getTargetHeartRate(int age) const 
{
    int maxHeartRate = getMaximumHeartRate(age);
    return std::make_pair(static_cast<int>(maxHeartRate * 0.50),
        static_cast<int>(maxHeartRate * 0.85));
}