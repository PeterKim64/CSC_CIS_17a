/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 *
 * Created on December 10, 2023, 6:20 PM
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "ModifiedVector.h"

// Global Constants

// Function prototypes
void fillVector(ModifiedVector<unsigned char> &);
void printVector(ModifiedVector<unsigned char> &, char);

// Execution Begins Here
int main(int argc, char **argv)
{
    // Declare Variables
    unsigned char vectorSize = 100;
    ModifiedVector<unsigned char> mv(vectorSize);

    // Fill the Vector
    fillVector(mv);

    // Print the Vector
    cout << "Original Random Dynamic Array derived Modified Vector" << endl;
    printVector(mv, 10);

    // Push the new values
    for (unsigned char i = 1; i <= 5; i++)
    {
        mv.insert('0' + i);
    }

    // Copy the Vector
    ModifiedVector<unsigned char> copyMv(mv);

    // Pop the new values
    for (unsigned char i = 1; i <= 2; i++)
    {
        cout << "Values Popped off = " << copyMv.remove() << endl;
    }

    // Print the Vector
    cout << "Copied Random Dynamic Array derived Modified Vector" << endl;
    printVector(copyMv, 10);

    return 0;
}

void printVector(ModifiedVector<unsigned char> &mv, char perLine)
{
    cout << endl;
    for (unsigned char i = 0; i < mv.getSize(); i++)
    {
        cout << mv[i] << " ";
        if (i % perLine == (perLine - 1))
            cout << endl;
    }
    cout << endl;
}

void fillVector(ModifiedVector<unsigned char> &mv)
{
    for (unsigned char i = 0; i < mv.getSize(); i++)
    {
        mv[i] = rand() % 26 + 65;
    }
}

