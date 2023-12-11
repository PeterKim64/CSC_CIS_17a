/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ModifiedTime.cpp
 * Author: User
 * 
 * Created on December 10, 2023, 6:27 PM
 */

// ModifiedTime.cpp
#include <iostream>
using namespace std;

#include "ModifiedTime.h"

ModifiedTime::ModifiedTime()
{
    cout << "This Program inputs standard time and outputs both military and standard time." << endl;
    cout << "Input Each Field..." << endl;
    cout << "Input Hours  (1-12) : ";
    cin >> customHour;
    // Validation
    if (customHour > 12 || customHour < 1)
    {
        cout << "Invalid Hour! Try again: ";
        cin >> customHour;
    }
    cout << "Input Minutes (0-59): ";
    cin >> customMin;
    // Validation
    if (customMin > 59 || customMin < 1)
    {
        cout << "Invalid Minutes! Try again: ";
        cin >> customMin;
    }
    cout << "Input Seconds (0-59): ";
    cin >> customSec;
    // Validation
    if (customSec > 59 || customSec < 1)
    {
        cout << "Invalid Seconds! Try again: ";
        cin >> customSec;
    }
    cout << "Day or Night(a or p): ";
    cin >> customDay;
}

ModifiedMilTime::ModifiedMilTime()
{
    if (customDay == 'a' && customHour == 12)
    {
        milCustomHour = customMin;
    }
    else if (customDay == 'p' && customHour == 12)
    {
        milCustomHour = (customHour * 100) + customMin;
    }
    else if (customDay == 'a')
    {
        milCustomHour = (customHour * 100) + customMin;
    }
    else if (customDay == 'p')
    {
        milCustomHour = (customHour + 12) * 100;
        milCustomHour += customMin;
    }
    milCustomSec = customSec;
}

void ModifiedMilTime::display()
{
    cout << endl
         << "The Converted Times are..." << endl;
    cout << "Standard Time..." << endl;
    cout << customHour << ":" << customMin << ":" << customSec;
    // Output for am or pm
    if (customDay == 'a')
    {
        cout << " A.M." << endl
             << endl;
    }
    else
    {
        cout << " P.M." << endl
             << endl;
    }
    cout << "Military Time..." << endl;
    cout << milCustomHour << " Hours and " << milCustomSec << " Seconds";
}


