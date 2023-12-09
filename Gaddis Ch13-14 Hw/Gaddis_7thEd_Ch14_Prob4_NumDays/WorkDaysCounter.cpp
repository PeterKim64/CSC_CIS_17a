/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   WorkDaysCounter.cpp
 * Author: User
 * 
 * Created on December 8, 2023, 7:51 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "WorkDaysCounter.h"

WorkDaysCounter::WorkDaysCounter() {
    cout << "This Program counts how much work hours amount to in days." << endl;
    cout << "Would you like to input hours for today? (y/n): ";
    cin >> userChoice;

    // Initialize totalDays and workHours
    totalDays = workHours = 0;

    // Loop for hour input
    while (userChoice == 'y') {
        cout << "How many hours did you work?" << endl;
        cout << "Input hours: ";
        cin >> workHours;
        countDays();

        // Ask if there are more days
        cout << endl << "Would you like to input another day? (y/n): ";
        cin >> userChoice;
        cout << endl;
    }
}

void WorkDaysCounter::countDays() {
    // Calculate the amount of days
    totalDays += workHours / 8;
    cout << "You have " << setprecision(2) << fixed << totalDays << " day(s) right now..." << endl;
}

void WorkDaysCounter::displayTotalDays() {
    cout << "The total amount of days accumulated is " << setprecision(2) << fixed << totalDays << " day(s).";
}


