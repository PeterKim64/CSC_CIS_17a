/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 10, 2023, 7:19 PM
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>
using namespace std; // Library Name-space

// User Libraries

// Global/Universal Constants -- No Global Variables
// Science, Math, Conversions, Higher Dimensioned constants only

// Function Prototypes
template <class CustomMax>
CustomMax getCustomMax(CustomMax val1, CustomMax val2)
{
    CustomMax result;
    result = (val1 > val2) ? val1 : val2;
    return result;
}

template <class CustomMin>
CustomMin getCustomMin(CustomMin val1, CustomMin val2)
{
    CustomMin result;
    result = (val1 < val2) ? val1 : val2;
    return result;
}

// Execute code
int main()
{
    // Initialize class
    int customNum1, customNum2, customMinNum, customMaxNum;
    // Output
    cout << "This Program Utilizes templates to find the maximum and minimum between 2 inputs." << endl;
    cout << "Input customNum1 and customNum2: ";
    cin >> customNum1 >> customNum2;
    // Calculate max and min
    customMaxNum = getCustomMax(customNum1, customNum2);
    customMinNum = getCustomMin(customNum1, customNum2);
    cout << endl
         << "The Maximum is: " << customMaxNum << endl;
    cout << "The Minimum is: " << customMinNum << endl;
    return 0;
}

