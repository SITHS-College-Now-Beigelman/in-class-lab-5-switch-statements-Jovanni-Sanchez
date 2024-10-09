// Jovanni Sanchez
// Lab 5, Part 3
// Problem #2
// 10/8/2024

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// while loop, remember

int main()
{
    int numOfStepsEast = 0;
    int numOfStepsWest = 0;
    int numOfStepsNorth = 0;
    int numOfStepsSouth = 0;
    int totalNumberOfSteps = 0;

    srand(time(0));

    while (numOfStepsEast != 2 && numOfStepsNorth != 3)
    {
        int internalDirection = rand() % 4 + 1;

        switch (internalDirection)
        {
        case 1:
            cout << "North.\n";
            numOfStepsNorth += 1;
            totalNumberOfSteps += 1;
            break;
        case 2:
            cout << "South.\n";
            totalNumberOfSteps += 1;
            break;
        case 3:
            cout << "East.\n";
            numOfStepsEast += 1;
            totalNumberOfSteps += 1;
            break;
        case 4:
            cout << "West.\n";
            totalNumberOfSteps += 1;
            break;
        }
    }

    return 0;
}