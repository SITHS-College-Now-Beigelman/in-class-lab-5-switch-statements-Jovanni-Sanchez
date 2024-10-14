// Jovanni Sanchez
// Lab 5, Part 3
// Problem #2
// 10/8/2024

#include <array>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/* Your program will simulate a lost robot taking steps in a random matter.
The robot begins in the middle of Manhattan. Each time the robot moves one block,
either north, south, east, west with probability 25% of each. You want the robot to get
to a point that is 2 blocks to the east and 3 blocks to the north of the starting point.
Given the same random choices for moves, change your code so that your code prints out
how many steps it took to get to the destination point. On average, how many steps does it
take for the robot to reach the destination point? Run the code 10 times and give the average! */

int main()
{
    int currentLoop;
    int numOfStepsEast = 0;
    int numOfStepsNorth = 0;
    int avgNumberOfSteps = 0;
    int sumOfEveryStepTaken = 0;
    array<float, 10> everyPossibleStep; // el diablo >:(

    srand(time(0)); // Real time changes (woah :O)

    /* currentLoop is used for iteration. The rest of the variables are used
    as tallies for the type of step the robot takes. If the robot steps north,
    a step is added to the numOfStepsNorth and so on. The reason for these tallies
    is so I can output how many steps the robot went east or north, the sum of every step  */

    cout << "The robot will now begin 10 loops.\n"
         << "In each loop the robot will roam aimlessly until:\n"
         << "   - It has consecutively made 2 steps East and 3 steps North.\n"
         << "   - Or it dies :c\n\n";

    /* I hate using arrays, it's awesome. Arrays are a necessary evil in this instance
    (at least i think they are...) I not only have to make the code run until the robot
    consecutively makes 2 steps east and 3 steps north (in no particular order), but also
    make the robot do it TEN TIMES and get an average out of it. So I used the help off a array
    (boo!) to store the total after each loop to use them later to find a sum and a average.  */

    for (currentLoop = 0; currentLoop < 10; currentLoop++)
    {
        bool roaming = true;
        int tmpTotalSteps = 0;
        int cuttingOffPoint = 840; // sorry lil buddy

        /* Here I assign temporary variables only used within this for and while loop.
        The bool roaming is used to determine wheter the robot has reached it's destination
        or if the while loop should countine looping. tmpTotalSteps will be assigned to the total
        of each steps of each loop, which will then be added to the array for safe keeping. The
        cuttingOffPoint is exactly what it sounds like. I was thinking after surpassing a limit of
        steps (probably a high one), I kill the robot and set the total for that loop to the cutting
        off point. I decide not to implement the cutting off point as I couldn't think off a good limit
        to just end the robot's run. */

        while (roaming)
        {
            int internalDirection = rand() % 4 + 1;

            /* If the direction the robot takes a step in is South or West, that step
            is added to the total while simultaneously resetting the steps taken north and
            east zero. This ensures the robot truely makes it's way to it's destination after
            2 steps east and 3 steps north (in no particular order). */

            tmpTotalSteps += 1;

            switch (internalDirection)
            {
            case 1:
                numOfStepsNorth += 1;
                break;
            case 2:
                // loser
                numOfStepsEast = 0;
                numOfStepsNorth = 0;
                break;
            case 3:
                numOfStepsEast += 1;
                break;
            case 4:
                // get bent
                numOfStepsEast = 0;
                numOfStepsNorth = 0;
                break;
            }

            /* If the robot has reached it's destination, I tell it to stop roaming
            and print out the total number of steps it took to get their. Else if, the robot
            exceeds the limit of steps it can take, I cut it off and set the total for that loop
            to the limit. Else, I make it keep roaming until it eventually reaches it's destination. */

            if (numOfStepsEast == 2 && numOfStepsNorth == 3)
            {
                roaming = false;
                everyPossibleStep[currentLoop] = tmpTotalSteps;
                cout << "The robot has reached it's destination after " << tmpTotalSteps << " steps.\n";
            }
            else if (tmpTotalSteps >= cuttingOffPoint)
            {
                roaming = false;
                everyPossibleStep[currentLoop] = cuttingOffPoint;
                cout << "The robot has reached it's destination after " << cuttingOffPoint << " steps.\n";
            }
            else
            {
                roaming = true;
            }
        }
    }

    /* The code below is really simple. First, I use a for loop to assign the sum of every
    step taken in the above loops to the variable sumOfEveryStepTaken by just skimming through
    the list and adding it's totals to the variable. Next I assign avgNumberOfSteps to that sum
    divide by the numbers of loops the robot had (10). Finally I output that sum and average in
    a nice little sentence. */

    for (currentLoop = 0; currentLoop < everyPossibleStep.size(); currentLoop++)
    {
        sumOfEveryStepTaken = sumOfEveryStepTaken + everyPossibleStep[currentLoop];
    }

    avgNumberOfSteps = sumOfEveryStepTaken / 10;

    cout << "\nAfter 10 loops, the robot has made:\n"
         << sumOfEveryStepTaken << " total steps or an average of "
         << avgNumberOfSteps << " steps per loop.";

    return 0;
}