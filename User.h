#ifndef USER_H
#define USER_H

#include <string>

class User
{
  private:
    std::string name;
    char gender;
    int age;
    int weight;
  public:
    void setName();
    std::string getName() const;

    void setGender();
    char getGender() const;

    void setAge();
    int getAge() const;

    void setWeight();
    int getWeight() const;
    
    void setInfo();
};

#endif