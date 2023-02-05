#include <iostream>
#include <string>
#include "WorkoutProgram.h"
#include "InputValidation.h"
#include "Exercise.h"
#include "User.h"

WorkoutProgram program;
User u;

void printMenu()
{
  std::cout << std::string(20, '-') << std::endl;
  std::cout << "1. Create exercise list" << std::endl;
  std::cout << "2. Print exercise list" << std::endl;
  std::cout << "3. Remove exercise" << std::endl;
  std::cout << "4. Calculate lifting skill" << std::endl;
  std::cout << "5. Exit" << std::endl
            << std::endl;
  std::cout << "Enter input: ";
}

void createExerciseList()
{
  std::string exerciseName;
  int sets, reps;

  std::cout << std::string(20, '-') << std::endl;
  std::cout << "Enter exercise name, sets done, reps done: " << std::endl;
  std::cout << "Enter -1 in the name to stop. " << std::endl;
  std::cout << "\n";

  while (true)
  {
    std::cout << "Exercise name: ";
    std::getline(std::cin, exerciseName);
    if (exerciseName == "-1")
      break;

    std::cout << "Sets: ";
    std::cin >> sets;
    std::cout << "Reps: ";
    std::cin >> reps;
    std::cin.ignore();

    program.addExercise(Exercise(exerciseName, sets, reps));
    std::cout << std::endl;
  }
}

void checkNumber(int &num)
{
  while (num <= 0)
  {
    std::cout << "Enter in a number larger than 0. ";
    std::cin >> num;
  }
}

void calculateLiftingSkill()
{
  int squatPR, benchPR, deadliftPR;
  std::string squat, bench, deadlift;
  std::cout << "Squat PR: ";
  std::cin >> squatPR;
  checkNumber(squatPR);
  std::cout << "Bench PR: ";
  std::cin >> benchPR;
  checkNumber(benchPR);
  std::cout << "Deadlift PR: ";
  std::cin >> deadliftPR;
  checkNumber(deadliftPR);
  int weight = u.getWeight();
  char gender = u.getGender();

  if (gender == 'm')
  {
    if (squatPR > (2.5 * weight))
      squat = "FREAK!";
    if (benchPR > (2 * weight))
      bench = "FREAK!";
    if (deadliftPR > (3 * weight))
      deadlift = "FREAK!";

    if (squatPR <= (3 * weight) && squatPR > (2.5 * weight))
      squat = "Elite";
    if (benchPR <= (2.25 * weight) && benchPR > (2 * weight))
      bench = "Elite";
    if (deadliftPR <= (3.5 * weight) && (deadliftPR > 3 * weight))
      deadlift = "Elite";

    if (squatPR <= (2.5 * weight) && squatPR > (1.75 * weight))
      squat = "Advanced";
    if (benchPR <= (2 * weight) && benchPR > (1.5 * weight))
      bench = "Advanced";
    if (deadliftPR <= (3 * weight) && deadliftPR > (2.25 * weight))
      deadlift = "Advanced";

    if (squatPR <= (1.75 * weight) && squatPR > (1.25 * weight))
      squat = "Intermediate";
    if (benchPR <= (1.5 * weight) && benchPR > (1 * weight))
      bench = "Intermediate";
    if (deadliftPR <= (2.25 * weight) && deadliftPR > (1.5 * weight))
      deadlift = "Intermediate";

    if (squatPR <= (1.25 * weight) && squatPR > 135)
      squat = "Beginner";
    if (benchPR <= (1 * weight) && benchPR > 95)
      bench = "Beginner";
    if (deadliftPR <= (1.5 * weight) && deadliftPR > 135)
      deadlift = "Beginner";

    if (squatPR >= 45 && squatPR <= 135)
      squat = "Noob";
    if (benchPR >= 45 && benchPR <= 95)
      bench = "Noob";
    if (deadliftPR >= 45 && deadliftPR <= 135)
      deadlift = "Noob";
  }

  if (gender == 'f')
  {
    if (squatPR > (2.25 * weight))
      squat = "FREAK!";
    if (benchPR > (1.25 * weight))
      bench = "FREAK!";
    if (deadliftPR > (3 * weight))
      deadlift = "FREAK!";

    if (squatPR <= (2.25 * weight))
      squat = "Elite";
    if (benchPR <= (1.25 * weight))
      bench = "Elite";
    if (deadliftPR <= (3 * weight))
      deadlift = "Elite";

    if (squatPR <= (1.75 * weight))
      squat = "Advanced";
    if (benchPR <= (1 * weight))
      bench = "Advanced";
    if (deadliftPR <= (2.25 * weight))
      deadlift = "Advanced";

    if (squatPR <= (1.5 * weight))
      squat = "Intermediate";
    if (benchPR <= (0.75 * weight))
      bench = "Intermediate";
    if (deadliftPR <= (1.75 * weight))
      deadlift = "Intermediate";

    if (squatPR <= (1 * weight))
      squat = "Beginner";
    if (benchPR <= (0.5 * weight))
      bench = "Beginner";
    if (deadliftPR <= (1 * weight))
      deadlift = "Beginner";

    if (squatPR >= 45 && squatPR <= 95)
      squat = "Noob";
    if (benchPR >= 0 && benchPR <= 45)
      bench = "Noob";
    if (deadliftPR >= 45 && deadliftPR <= 135)
      deadlift = "Noob";
  }

  std::cout << "\n";
  std::cout << "Squat: " << squat << "\n";
  std::cout << "Bench: " << bench << "\n";
  std::cout << "Deadlift: " << deadlift << "\n";
}

void removeExercise()
{
  std::string input;
  std::cout << "Enter exercise you want to remove: ";
  std::getline(std::cin, input);
  while (true)
  {
    if (program.removeExercise(input))
    {
      std::cout << "Exercise removed. " << std::endl;
      break;
    }
    else
    {
      std::cout << "Exercise not found. " << std::endl;
      std::cin.ignore();
    }
  }
}

int main()
{
  u.setInfo();

  while (true)
  {
    printMenu();
    std::string input;
    std::cin >> input;
    std::cin.ignore();

    if (InputValidation::isNumber(input))
    {
      int choice = std::stoi(input);
      switch (choice)
      {
      case 1:
        createExerciseList();
        break;
      case 2:
        program.printList();
        break;
      case 3:
        removeExercise();
        break;
      case 4:
        calculateLiftingSkill();
        break;
      case 5:
        std::cout << "Exiting..." << std::endl;
        return 0;
      default:
        std::cout << "Invalid choice. Enter a number between 1-4. " << std::endl;
      }
    }
    else
    {
      std::cout << "Invalid input. Enter a number. " << std::endl;
    }
  }

  return 0;
}

