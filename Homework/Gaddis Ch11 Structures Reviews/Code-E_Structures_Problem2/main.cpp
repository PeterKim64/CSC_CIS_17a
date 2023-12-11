//Peter Kim                 	  CSC5                   Chapter 11, p. 645, #5
//
/*******************************************************************************
 * 
 * CALCULATE AND OUTPUTE WEATHER STATISTICS (MODIFIED)
 * _____________________________________________________________________________
 * This program uses a structure to store the following weather data for a month: 
 * total rainfall, high temperature, low temperature, average temperature. The 
 * program takes for input all these values for each month for 12 months. It 
 * then calculates and displays the average and total rainfall, and the highest
 * and lowest temperatures for the year. Has enumeration for months. 
 * 
 * _____________________________________________________________________________
 * INPUT
 *	month					: which month it is 
 *	total rainfall			: total rainfall in month
 *	high temperature		: high temperature in the month
 *	low temperature 		: low temperature in the month
 * 
 * 
 ******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
 
struct weather {
    float rain, high, low;
};
 
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
 
    //Declare Variable Data Types and Constants
    const int size = 6;
    weather months[size];
    float max, min, avgTemp, avgRain;
    int count = 0;
 
    //Display Outputs
    while(cin >> months[count].rain >> months[count].high >> months[count].low) {
        cout << "Enter the total rainfall for the month:" << endl
             << "Enter the high temp:" << endl
             << "Enter the low temp:" << endl;
        count += 1;
    }
 
    //find average monthly rainfall
    avgRain = 0;
    for(int i = 0; i < count; i++) {
        avgRain += months[i].rain;
    }
    avgRain = avgRain / count;
 
    //find highest temperature
    max = months[0].high;
    for(int i = 1; i < count; i++) {
        if(months[i].high > months[i - 1].high) {
            max = months[i].high;
        }
    }
 
    //find lowest temperature
    min = months[0].low;
    for(int i = 1; i < count; i++) {
        if(months[i].low < months[i - 1].low) {
            min = months[i].low;
        }
    }
 
    //find average temperature
    avgTemp = 0;
    for(int i = 0; i < count; i++) {
        avgTemp += (months[i].high + months[i].low);
    }
    avgTemp = avgTemp / (count*2);
 
    //Output results
    cout << setprecision(2) << fixed;
    cout << "Average monthly rainfall:" << avgRain << endl;
    cout << setprecision(0) << fixed;
    cout << "High Temp:" << max << endl;
    cout << "Low Temp:" << min << endl;
    cout << setprecision(1) << fixed;
    cout << "Average Temp:" << avgTemp;
 
    //Exit stage right!
    return 0;
}
