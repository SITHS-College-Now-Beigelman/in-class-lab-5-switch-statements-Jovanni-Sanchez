// Jovanni Sanchez
// Lab 5, Part 3
// Problem #2
// 10/8/2024

#include <array> // Averaging is a pain
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int currentLoop;
    int numOfStepsEast = 0;
    int numOfStepsNorth = 0;
    int sumOfRobotSteps = 0;
    int avgNumberOfSteps = 0;
    array<float, 10> everyPossibleStep;

    srand(time(0));

    for (currentLoop = 0; currentLoop < 10; currentLoop++)
    {
        bool roaming = true;
        int tmpTotalSteps = 0;

        while (roaming)
        {
            int internalDirection = rand() % 4 + 1;

            cout << left;

            switch (internalDirection)
            {
            case 1:
                cout << "North.\n";
                numOfStepsNorth += 1;
                tmpTotalSteps += 1;
                break;
            case 2:
                cout << "South.\n";
                numOfStepsEast = 0;
                numOfStepsNorth = 0;
                tmpTotalSteps += 1;
                break;
            case 3:
                cout << "East.\n";
                numOfStepsEast += 1;
                tmpTotalSteps += 1;
                break;
            case 4:
                cout << "West.\n";
                numOfStepsEast = 0;
                numOfStepsNorth = 0;
                tmpTotalSteps += 1;
                break;
            }

            if (numOfStepsEast == 2 && numOfStepsNorth == 3)
            {
                roaming = false;
                everyPossibleStep[currentLoop] = tmpTotalSteps;
                cout << "The robot has reached it's destination after " << tmpTotalSteps << " steps.\n";
            }
            else
            {
                roaming = true;
            }
        }
    }

    for (currentLoop = 0; currentLoop < everyPossibleStep.size(); currentLoop++)
    {
        sumOfRobotSteps = sumOfRobotSteps + everyPossibleStep[currentLoop]; // get sum of the total of each loop
    }

    avgNumberOfSteps = sumOfRobotSteps / 10;

    cout << "\nAfter 10 loops, the robot has made:\n"
         << sumOfRobotSteps << " total steps or an average of "
         << avgNumberOfSteps << " steps per loop.";

    return 0;
}