#include "User.h"
#include "InputValidation.h"
#include <cctype>
#include <string>
#include <iostream>

void User::setName()
{
  std::string input;
  while (true)
  {
    std::cout << "Enter name: ";
    std::getline(std::cin, input);
    if (InputValidation::checkName(input))
    {
      name = input;
      break;
    }
    else
      std::cout << "Invalid input. Enter with valid characters." << std::endl;
  }
}

void User::setGender()
{
  char input;
  while (true)
  {
    std::cout << "Enter in (m/f): ";
    std::cin >> input;
    if (InputValidation::checkGender(input))
    {
      gender = tolower(input);
      break;
    }
    else
      std::cout << "Invalid input. Enter with valid characters." << std::endl;
  }
}

void User::setAge()
{
  std::string input;
  while (true)
  {
    std::cout << "Enter age: ";
    std::cin >> input;
    if (InputValidation::isNumber(input) && InputValidation::checkAge(stoi(input)))
    {
      age = stoi(input);
      break;
    }
      
    else
      std::cout << "Invalid input. Enter a valid number. " << std::endl;
  }
}

void User::setWeight()
{
  std::string input;
  while (true)
  {
    std::cout << "Enter weight in lbs: ";
    std::cin >> input;
    if (InputValidation::isNumber(input) && InputValidation::checkAge(stoi(input)))
    {
      weight = stoi(input);
      break;
    }
    else
      std::cout << "Invalid input. enter a valid weight. " << std::endl;
  }
}

void User::setInfo()
{
  setName();
  setAge();
  setGender();
  setWeight();
}

int User::getAge() const { return age; }
int User::getWeight() const { return weight; }
std::string User::getName() const { return name; }
char User::getGender() const { return gender; }