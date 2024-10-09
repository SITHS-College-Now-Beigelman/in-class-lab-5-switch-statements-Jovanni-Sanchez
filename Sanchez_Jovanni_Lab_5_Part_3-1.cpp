// Jovanni Sanchez
// Lab 5, Part 3
// 10/8/2024

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// 1 means North, 2 means South, 3 means East and 4 means West

int main()
{
    int currentRobotStep;
    int numOfStepsEast = 0;
    int numOfStepsWest = 0;
    int numOfStepsNorth = 0;
    int numOfStepsSouth = 0;

    srand(time(0));

    cout << "The robot will take these steps:\n"
         << "\n";

    for (currentRobotStep = 0; currentRobotStep < 25; currentRobotStep++)
    {
        int internalDirection = rand() % 4 + 1;

        switch (internalDirection)
        {
        case 1:
            cout << "North.\n";
            numOfStepsNorth += 1;
            break;
        case 2:
            cout << "South.\n";
            numOfStepsSouth += 1;
            break;
        case 3:
            cout << "East.\n";
            numOfStepsEast += 1;
            break;
        case 4:
            cout << "West.\n";
            numOfStepsWest += 1;
            break;
        }
    }

    cout << "\nAfter 25 Steps, The robot took:\n"
         << numOfStepsNorth << " steps North.\n"
         << numOfStepsSouth << " steps South.\n"
         << numOfStepsEast << " steps East.\n"
         << numOfStepsWest << " steps West.\n";

    return 0;
}