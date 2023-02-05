#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>

class Exercise
{
  private:
    std::string name;
    int sets;
    int reps;
  public:
    Exercise() : name(""), sets(0), reps(0) {}
    Exercise(std::string n, int s, int r) : name(n), sets(s), reps(r) {}

    std::string getName() const;
    int getSets() const;
    int getReps() const;
};

#endif