// Jovanni Sanchez
// Lab 5, Part 1
// 10/8/2024

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

/* Calculating calories burned during Exercise */
/* Total Calories Burned =
(Duration in minutes) × (MET × 3.5 × Weight in kg) / 200 */

int main()
{
    // Setting up Variables
    float MET;                // Metabolic Equivalent of Task
    double userWeight;        // The user's weight (in kg)
    string exerciseName;      // The name of the exercise
    double durationInMinutes; // The duration of the exercise (in min)

    cout << "What exercise do you want to do?: ";
    cin >> exerciseName; // Very Important :D

    cout << "Please input your weight (in kilograms): ";
    cin >> userWeight; // The weight will be reused later for finding duration

    cout << "Please input how long you want to exercised for (in minutes): ";
    cin >> durationInMinutes; // This won't be reused >:(

    if (exerciseName == "Walking slowly")
    {
        MET = 2.0;
    }
    else if (exerciseName == "Walking quickly")
    {
        MET = 3.0;
    }
    else if (exerciseName == "Jogging")
    {
        MET = 8.8; // If Jogging, the MET is 8.8
    }
    else
    {
        cout << "I'm sorry, I don't know the MET "
             << "or Metabolic Equivalent of Task for "
             << exerciseName << ".\nI'm defaulting the MET to 1.0.\n";
        MET = 1.0; // I'm too lazy to do more exercises
    }

    cout << "\nThe MET for " << exerciseName << " is " << MET << ".\n";

    cout << "The total number of calories you will burn is "
         << (durationInMinutes) * (MET * 3.5 * userWeight) / 200
         << " Calories" << endl;

    // Setting up Extra Credit Variables
    /* Duration in minutes =
    (desiredCalories * 200) / (MET * 3.5 * userWeight) */

    double desiredCalories; // The user's desired Calories

    cout << "\nHow many calories do you want to burn?: ";
    cin >> desiredCalories; // Get desired calories

    cout << "To burn " << desiredCalories << " Calories, You will need to be:"
         << fixed << showpoint << setprecision(1) // Fix decimals to only 1 point
         << "\n"
         << exerciseName << " for " << (desiredCalories * 200) / (MET * 3.5 * userWeight) << " minutes";

    return 0;
}