// Jovanni Sanchez
// Lab 5, Part 2
// 10/8/2024

#include <string>
#include <iostream>
using namespace std;

int main()
{
    // Setting up Variables
    double userGigabytes;
    string userStreamingQuality;
    float qualityDifferenceHours;
    float qualityDifferenceMinutes;


    cout << "How many Gigabytes is in your monthly plan?: ";
    cin >> userGigabytes; // Get the user's Gigabytes

    cout << "Do you want to stream in Low, Standard, or High Quality: ";
    cin >> userStreamingQuality;

    if (userStreamingQuality == "Low quality" || "Low" || "low")
    {
        qualityDifferenceHours = 43.2;
        qualityDifferenceMinutes = 0.72;
    }
    else if (userStreamingQuality == "Standard quality" || "Standard" || "standard")
    {
        qualityDifferenceHours = 72;
        qualityDifferenceMinutes = 1.20;
    }
    else if (userStreamingQuality == "High quality" || "High" || "high")
    {
        qualityDifferenceHours = 115.2;
        qualityDifferenceMinutes = 2.4;
    }
    else
    {
        // Fallback the mb per hour and minutes to 1.0
        qualityDifferenceHours = 1.0;
        qualityDifferenceMinutes = 1.0;
    }

    if(userStreamingQuality != "Low quality" || "Standard quality" || "High quality")
    {
        cout << "\nWith " << userGigabytes << " GB, you can stream in:\n"
            << userStreamingQuality << " quality for " << (userGigabytes * 1000) / qualityDifferenceMinutes 
            << " Minutes, " << "or for " << (userGigabytes * 1000) / qualityDifferenceHours << " Hours.\n";
    }
    else
    {
        cout << "\nWith " << userGigabytes << " GB, you can stream in:\n"
            << userStreamingQuality << " for " << (userGigabytes * 1000) / qualityDifferenceMinutes 
            << " Minutes, " << "or for " << (userGigabytes * 1000) / qualityDifferenceHours << " Hours.\n";
    }

    return 0;
}