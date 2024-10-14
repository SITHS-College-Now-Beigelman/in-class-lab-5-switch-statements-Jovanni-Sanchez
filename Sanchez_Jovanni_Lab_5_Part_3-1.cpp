// Jovanni Sanchez
// Lab 5, Part 3
// 10/8/2024

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/* Your program will simulate a lost robot taking steps in a random matter.
The robot begins in the middle of Manhattan. Each time the robot moves one block,
either north, south, east, west with probability 25% of each. The robot moves 25 times.
At each step, how many blocks away (print this in north or south, east or west of the
starting point) is the robot from the starting point? */

int main()
{
    int currentRobotStep;
    int numOfStepsEast = 0;
    int numOfStepsWest = 0;
    int numOfStepsNorth = 0;
    int numOfStepsSouth = 0;

    /* currentRobotStep is used for iteration. The rest of the variables
    are used as tallies for the type of step the robot takes. If the robot
    steps north, a step is added to the numOfStepsNorth and so on. The reason
    for these tallies is so I can output how many steps the robot went on after
    it's 25 steps are up. */

    srand(time(0)); // Ensures different results in real time :O

    /* This header is kinda useless since the program outputs steps super fast,
    meaning the header is on screen for a split second before being overshadowed by
    the robot's steps. */

    cout << "The robot will take these steps:\n\n";
    //

    for (currentRobotStep = 0; currentRobotStep < 25; currentRobotStep++)
    {
        // the steps iterate from 0 to 24 (techinaclly 25)

        int internalDirection = rand() % 4 + 1;

        /* 1 means North, 2 means South, 3 means East, 4 means West.
        I print out the direction aswell as adding 1 to the tally of each
        step in the corresponding direction. */

        switch (internalDirection)
        {
        case 1:
            cout << "North.\n";
            numOfStepsNorth++;
            break;
        case 2:
            cout << "South.\n";
            numOfStepsSouth++;
            break;
        case 3:
            cout << "East.\n";
            numOfStepsEast++;
            break;
        case 4:
            cout << "West.\n";
            numOfStepsWest++;
            break;
        }
    }

    /* After the 25 steps, I print out the tallies previouly established.
    You will know if this code work because the sum of these individual tallies
    should add up to 25. */

    cout << "\nAfter 25 Steps, The robot took:\n"
         << numOfStepsNorth << " steps North.\n"
         << numOfStepsSouth << " steps South.\n"
         << numOfStepsEast << " steps East.\n"
         << numOfStepsWest << " steps West.\n";

    return 0;
}