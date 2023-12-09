/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on December 5, 2023, 8:11 PM
 * Description: Filter sentence and make all first letters capital
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void writeToTextFile(fstream&, const string&);
void writeToBinaryFile(fstream&, const string&);
void applyFilter(string&);
void printString(const string&);

int main() {
    // Open files
    fstream textFile, binFile;
    textFile.open("data.txt", ios::in | ios::out);
    binFile.open("data.bin", ios::in | ios::out | ios::binary);
    string input;

    // Initialize
    cout << "Enter the sentence input: " << endl;

    // Input the sentences
    cin.clear();
    getline(cin, input);

    // Write to binary and text files
    writeToTextFile(textFile, input);
    writeToBinaryFile(binFile, input);
    applyFilter(input);

    // Read back in the array, then print out
    cout << "The filtered sentences are: " << endl;
    printString(input);

    // Close the files
    textFile.close();
    binFile.close();

    return 0;
}

void writeToBinaryFile(fstream& out, const string& input) {
    int size = input.size();
    char* copy = new char[size];
    for (int i = 0; i < size; i++) {
        copy[i] = input[i];
    }
    out.write(copy, size * sizeof(char));
    delete[] copy;
}

void writeToTextFile(fstream& out, const string& input) {
    for (char c : input) {
        out << c;
    }
}

void applyFilter(string& input) {
    int size = input.size();
    char a;

    // Capitalize first letter
    if (islower(input[0])) {
        a = toupper(input[0]);
        input[0] = a;
    }

    for (int i = 1; i < size; i++) {
        // Check which ones to lowercase and which ones to uppercase
        if (islower(input[i]) && input[i - 2] == '.') {
            // Convert lowercase to uppercase
            input[i] = toupper(input[i]);
        } else if (isupper(input[i]) && input[i - 2] != '.') {
            // Convert uppercase to lowercase
            input[i] = tolower(input[i]);
        }
    }
}

void printString(const string& input) {
    for (char c : input) {
        cout << c;
    }
    cout << endl;
}

