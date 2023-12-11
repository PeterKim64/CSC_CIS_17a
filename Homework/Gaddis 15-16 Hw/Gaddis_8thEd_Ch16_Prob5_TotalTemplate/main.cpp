/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 10, 2023, 7:21 PM
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>
using namespace std; // Library Name-space

// User Libraries

// Global/Universal Constants -- No Global Variables
// Science, Math, Conversions, Higher Dimensioned constants only

// Function Prototypes
template <class CustomType>
CustomType *getCustomInput(int);

template <class CustomType>
CustomType calculateCustomTotal(CustomType *customArray, CustomType customSize)
{
    CustomType sum = 0;
    for (int i = 0; i < customSize; i++)
    {
        sum += customArray[i];
    }
    return sum;
}

// Execute code
int main()
{
    // Initialize class
    int *customArray, customSize, customTotal;

    // Start
    cout << "This Program inputs the total of each inputed number." << endl;
    cout << "Input The number of inputs you will add." << endl;
    cout << "Enter Size: ";
    cin >> customSize;

    // Process
    customArray = getCustomInput<int>(customSize);
    customTotal = calculateCustomTotal(customArray, customSize);

    // Output
    cout << endl
         << "The running total is = " << customTotal << endl;

    // End
    return 0;
}

// For dynamic array
template <class CustomType>
CustomType *getCustomInput(int customSize)
{
    CustomType *customArray = new CustomType[customSize];
    for (int i = 0; i < customSize; i++)
    {
        cout << "Input Num#" << i + 1 << ": ";
        cin >> customArray[i];
    }
    return customArray;
}


