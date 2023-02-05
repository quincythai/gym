#ifndef WORKOUTPROGRAM_H
#define WORKOUTPROGRAM_H

#include "Exercise.h"
#include <vector>

class WorkoutProgram
{
  private:
    int numExercises;
    std::vector<Exercise> exercises;
  public:
    WorkoutProgram(): numExercises(0) {}
    // vector's default constructor makes its own empty vector
    int getNumExercises() const;

    void addExercise(const Exercise &e);

    bool removeExercise(const std::string exerciseName);

    void printList() const;

    int calculateTotalReps() const;
};

#endif