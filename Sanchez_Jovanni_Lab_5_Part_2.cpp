// Jovanni Sanchez
// Lab 5, Part 2
// 10/8/2024

#include <string>
#include <iostream>
using namespace std;

/* Calculating Music Streaming Data Usage */
/* Low quality (96 kbps): Uses 0.72 MB per minute or 43.2 MB per hour.
Normal quality (160 kbps): Uses 1.20 MB per minute or 72 MB per hour.
High quality (320 kbps): Uses 2.40 MB per minute or 115.2 MB per hour. */
/* Note: Assume that 1 Gigabyte = 1,000 Megabytes */

int main()
{
    // Setting up Variables
    double userGigabytes;         // Used to store the user's gb
    string userStreamingQuality;  // Used to store the streaming quality (as a string)
    int internalStreamingQuality; // Used to store the streaming quality (as a int)
    float qualityDifferenceHours;
    float qualityDifferenceMinutes;

    /* Varaibles qualityDifferenceHours and qualityDifferenceMinutes
    will be assinged different numbers. This makes the math for later
    super easy, */

    cout << "How many Gigabytes is in your monthly plan?: ";
    cin >> userGigabytes; // Get the user's Gigabytes

    cout << "Do you want to stream in Low, Standard, or High Quality?\n"
         << "Please input 1, 2, or 3 based on the quality corelating with "
         << "the quality numerically: ";
    cin >> internalStreamingQuality; // Get the user's streaming quality

    /* While internalStreamingQuality is greater than 3 or less than 1,
    make the user reinput their quality to a valid one. */

    while (internalStreamingQuality > 3 || internalStreamingQuality < 1)
    {
        cout << "Remember, there are only 3 qualities:\n"
             << "    Low quality correspondes to 1.\n"
             << "    Standard quality correspondes to 2.\n"
             << "    High quality correspondes to 3.\n"
             << "Please enter a valid quality: ";
        cin >> internalStreamingQuality;
    }

    /*
    In this switch statement I assign:
       qualityDifferenceHours to the qualities mb per hour
       qualityDifferenceMinutes to the qualities mb per minute
       and userStreamingQuality to the name of the quality
    */

    switch (internalStreamingQuality)
    {
    case 1:
        qualityDifferenceHours = 43.2;   // 43.2 mb per hour
        qualityDifferenceMinutes = 0.72; // 0.72 mb per minute
        userStreamingQuality = "Low quality";
        break;
    case 2:
        qualityDifferenceHours = 72;     // 72 mb per hour
        qualityDifferenceMinutes = 1.20; // 1.20 mb per minute
        userStreamingQuality = "Standard quality";
        break;
    case 3:
        qualityDifferenceHours = 115.2; // 115.2 mb per hour
        qualityDifferenceMinutes = 2.4; // 2.4 mb per minute
        userStreamingQuality = "High quality";
        break;
    default:
        qualityDifferenceHours = 1.0;
        qualityDifferenceMinutes = 1.0;
        userStreamingQuality = "??? quality";
        cout << "\nFallbacking to 1 mb per hour and minute.";
        /* Fallback the mbs per hour and minute to 1.0. Just in case
        the user some how breaks my code, fall back to these variables. */
    }

    /* Using previously assinged variables to output how much the user can stream
    in x quality for y minutes and z hours. */

    cout << "\nWith " << userGigabytes << " GB, you can stream in:\n"
         << userStreamingQuality << " for " << (userGigabytes * 1000) / qualityDifferenceMinutes
         << " Minutes, " << "or for " << (userGigabytes * 1000) / qualityDifferenceHours << " Hours.\n";

    return 0;
}