/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on December 5, 2023, 8:37 PM
 */

#include <iostream>
#include <fstream>

using namespace std;

// Struct definition
struct Company {
    float *qrtSales;
};

// Function prototypes
float *fillArray(const int);
void printArray(const int, Company[]);
int writeBinaryFile(fstream&, Company[], const int);
int writeTextFile(fstream&, Company[], const int);

int main() {
    // Open the Text and binary files
    fstream txtFile, binFile;
    txtFile.open("data.txt", ios::in | ios::out);
    binFile.open("data.bin", ios::in | ios::out | ios::binary);
    const int size = 4;
    Company div[size];

    // Initialize
    cout << "This program inputs the quarterly sales of each division of a company into a file." << endl << endl;
    cout << "Input the sales for the Eastern Division...." << endl;
    div[0].qrtSales = fillArray(size);
    cout << "Input the sales for the Western Division...." << endl;
    div[1].qrtSales = fillArray(size);
    cout << "Input the sales for the Northern Division..." << endl;
    div[2].qrtSales = fillArray(size);
    cout << "Input the sales for the Southern Division..." << endl;
    div[3].qrtSales = fillArray(size);

    // Output data into a file
    writeTextFile(txtFile, div, size);
    writeBinaryFile(binFile, div, size);

    // Output List
    cout << endl << "The inputed list for each division's quarterly sales is: " << endl;
    printArray(size, div);

    // Delete memory
    for (int i = 0; i < size; ++i) {
        delete[] div[i].qrtSales;
    }

    // Close the files
    txtFile.close();
    binFile.close();

    // Exit
    return 0;
}

float *fillArray(const int size) {
    // Initialize dynamic array
    float *array = new float[size];
    cout << "Input for each quarter..." << endl;
    // Fill dynamic array
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " Quarter: ";
        cin >> array[i];
    }

    return array;
}

void printArray(const int size, Company div[]) {
    const char* divisionNames[] = {"Eastern", "Western", "Northern", "Southern"};

    for (int j = 0; j < size; ++j) {
        cout << "The " << divisionNames[j] << " division:" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " Quarter: " << div[j].qrtSales[i] << endl;
        }
    }
}

int writeBinaryFile(fstream& out, Company div[], const int size) {
    for (int i = 0; i < size; i++) {
        out.write(reinterpret_cast<char *>(div[i].qrtSales), size * sizeof(float));
    }
}

int writeTextFile(fstream& out, Company div[], const int size) {
    const char* divisionNames[] = {"Eastern", "Western", "Northern", "Southern"};

    for (int j = 0; j < size; ++j) {
        out << "The " << divisionNames[j] << " division:" << endl;
        for (int i = 0; i < size; i++) {
            out << i + 1 << " Quarter: " << div[j].qrtSales[i] << endl;
        }
    }
}
