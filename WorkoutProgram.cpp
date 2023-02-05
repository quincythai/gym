#include "WorkoutProgram.h"
#include "Exercise.h"
#include <iostream>
#include <vector>

int WorkoutProgram::getNumExercises() const
{
  return numExercises;
}

void WorkoutProgram::addExercise(const Exercise &e)
{
  exercises.push_back(e);
  numExercises++;
}

bool WorkoutProgram::removeExercise(const std::string exerciseName)
{
  if (numExercises == 0)
  {
    std::cout << "No exercise to remove. " << std::endl;
    return true;
  }

  for (std::vector<Exercise>::iterator it = exercises.begin(); it != exercises.end(); it++)
  {
    if (it->getName() == exerciseName)
    {
      exercises.erase(it);
      numExercises--;
      return true;
    }
  }
  return false;
}

void WorkoutProgram::printList() const
{
  std::cout << std::string(20, '-') << std::endl;
  for (int i = 0; i < numExercises; i++)
  {
    std::cout << "Exercise: " << exercises[i].getName() << ", Sets: " << exercises[i].getSets()
              << ", Reps: " << exercises[i].getReps() << std::endl;
  }
  std::cout << std::string(20, '-') << std::endl;
}

int WorkoutProgram::calculateTotalReps() const
{
  int totalReps = 0;
  for (int i = 0; i < numExercises; i++)
  {
    totalReps += (exercises[i].getSets() * exercises[i].getReps());
  }
  return totalReps;
}
