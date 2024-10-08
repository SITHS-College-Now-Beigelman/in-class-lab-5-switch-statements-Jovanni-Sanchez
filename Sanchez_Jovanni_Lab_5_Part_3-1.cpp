// Jovanni Sanchez
// Lab 5, Part 3
// 10/8/2024

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//1 means North, 2 means South, 3 means East and 4 means West

int main()
{
    int pleaseTallyNorth = 0;
    int pleaseTallySouth = 0;
    int pleaseTallyEast = 0;
    int pleaseTallyWest = 0;
    int possibleRobotMoves;

    srand(time(0));

    for (possibleRobotMoves = 0; possibleRobotMoves < 25; possibleRobotMoves++)
    {
        int internalDirection = rand() % 4 + 1;

        switch (internalDirection)
        {
            case 1:
                cout << "North.\n";
                pleaseTallyNorth += 1;
                break;
            case 2:
                cout << "South.\n";
                pleaseTallySouth += 1;
                break;
            case 3:
                cout << "East.\n";
                pleaseTallyEast += 1;
                break;
            case 4:
                cout << "West.\n";
                pleaseTallyWest += 1;
                break;
        }
    }
    
    cout << "\nAfter 25 Steps, The robot is:\n"
         << pleaseTallyNorth << " steps North.\n"
         << pleaseTallySouth << " steps South.\n"
         << pleaseTallyEast << " steps East.\n"
         << pleaseTallyWest << " steps West.\n";

    return 0;
}