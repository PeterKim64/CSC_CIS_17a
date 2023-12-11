/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ModifiedScore.cpp
 * Author: User
 * 
 * Created on December 10, 2023, 6:29 PM
 */

// ModifiedScore.cpp
#include <iostream>
using namespace std;

#include "ModifiedScore.h"

ModifiedScore::ModifiedScore()
{
    cout << "This program inputs student scores and outputs if they passed or failed." << endl;
    cout << "Input Each field for student's score..." << endl;
    cout << "Grammar Score     (0-30): ";
    cin >> customGrammar;
    // Validation
    if (customGrammar > 30 || customGrammar < 0)
    {
        cout << "Invalid Score! Try Again: ";
        cin >> customGrammar;
    }
    cout << "Spelling Score    (0-20): ";
    cin >> customSpell;
    // Validation
    if (customSpell > 20 || customSpell < 0)
    {
        cout << "Invalid Score! Try Again: ";
        cin >> customSpell;
    }
    cout << "Word Length Score (0-20): ";
    cin >> customLength;
    // Validation
    if (customLength > 20 || customLength < 0)
    {
        cout << "Invalid Score! Try Again: ";
        cin >> customLength;
    }
    cout << "Content Score     (0-30): ";
    cin >> customContent;
    // Validation
    if (customContent > 30 || customContent < 0)
    {
        cout << "Invalid Score! Try Again: ";
        cin >> customContent;
    }
}

ModifiedPassFail::ModifiedPassFail()
{
    minCustomPass = 70;
    customTotScore = customGrammar + customSpell + customLength + customContent;
}

void ModifiedPassFail::display()
{
    cout << endl
         << "The Total Score of the student has been graded." << endl;
    cout << "Score: " << customTotScore << "/100" << endl;
    if (customTotScore >= minCustomPass)
    {
        cout << "The Student has Passed the class with a letter grade of a(n) ";
        if (customTotScore >= 70 && customTotScore < 80)
        {
            cout << "C";
        }
        else if (customTotScore >= 80 && customTotScore < 90)
        {
            cout << "B";
        }
        if (customTotScore >= 90 && customTotScore <= 100)
        {
            cout << "A";
        }
    }
    else
    {
        cout << "The Student did not pass, as the grade is less than 70.";
    }
    cout << endl;
}

