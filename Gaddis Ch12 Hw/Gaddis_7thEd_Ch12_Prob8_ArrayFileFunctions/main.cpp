/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on December 5, 2023, 8:15 PM
 * Description: Array/File Functions
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
int writeArrayToBinaryFile(fstream&, int*, int);
int writeArrayToTextFile(fstream&, int*, int);
int* readArrayFromFile(fstream&, int);
int* fillArray(int);
void printArray(const int*, int);

int main() {
    // Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    // Open the Text and binary files
    int* array;
    int size;
    fstream txtFile, binFile;
    txtFile.open("data.txt", ios::in | ios::out);
    binFile.open("data.bin", ios::in | ios::out | ios::binary);

    // Initialize
    cout << "Input the size of the array: ";
    cin >> size;

    // Initialize array
    array = fillArray(size);

    // Write into files
    writeArrayToBinaryFile(binFile, array, size);
    writeArrayToTextFile(txtFile, array, size);

    // Read files
    int* readArray = readArrayFromFile(binFile, size);
    printArray(readArray, size);

    // Close the files
    txtFile.close();
    binFile.close();

    // Delete dynamic arrays
    delete[] readArray;
    delete[] array;

    return 0;
}

int writeArrayToBinaryFile(fstream& out, int* array, int size) {
    out.write(reinterpret_cast<char*>(array), size * sizeof(int));
}

int writeArrayToTextFile(fstream& out, int* array, int size) {
    for (int i = 0; i < size; i++) {
        out << array[i];
    }
}

int* readArrayFromFile(fstream& in, int size) {
    // Initialize cursor and array
    long cursor = 0;
    int* array = new int[size];
    // Read file
    in.seekg(cursor, ios::beg);
    in.read(reinterpret_cast<char*>(array), size * sizeof(int));
    return array;
}

int* fillArray(int size) {
    // Initialize dynamic array
    int* array = new int[size];
    // Fill dynamic array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 9;
    }
    return array;
}

void printArray(const int* array, int size) {
    cout << "The random array with the size of " << size << " is: ";
    for (int i = 0; i < size; i++) {
        cout << array[i];
    }
}


