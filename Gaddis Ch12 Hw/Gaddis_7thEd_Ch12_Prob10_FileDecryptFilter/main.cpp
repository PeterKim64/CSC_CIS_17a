/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim
 * Created on December 5, 2023, 8:09 PM
 * Description: Decrypt a file 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void writeToTextFile(fstream&, const string&, int);
void writeToBinaryFile(fstream&, const string&, int);
char* readFromBinaryFile(fstream&, int);
void writeToBinaryFile2(fstream&, int, const char*);
void writeToTextFile2(fstream&, int, const char*);
void encryptString(string&, int);
char* decryptString(const char*, int);
void printString(const string&);
void printCharArray(int, const char*);

int main() {
    // Open files
    fstream textFile, binFile, decryptText, decryptBin;
    textFile.open("data.txt", ios::in | ios::out);
    binFile.open("data.bin", ios::in | ios::out | ios::binary);
    decryptText.open("decrypt.txt", ios::in | ios::out);
    decryptBin.open("decrypt.bin", ios::in | ios::out | ios::binary);

    // Input
    string input;
    cout << "Enter the sentence input: " << endl;
    getline(cin, input);
    int size = input.size();

    // Write to binary and text files
    encryptString(input, size);
    writeToTextFile(textFile, input, size);
    writeToBinaryFile(binFile, input, size);

    // Print encrypted message
    cout << "The Encrypted Message is: ";
    printString(input);

    // Decrypt the encrypted message
    char* copy = readFromBinaryFile(binFile, size);
    char* finish = decryptString(copy, size);

    // Write decrypted to files
    writeToBinaryFile2(decryptBin, size, finish);
    writeToTextFile2(decryptText, size, finish);

    // Output decrypted files
    cout << "The Decrypted message is: ";
    printCharArray(size, finish);

    // Delete the arrays
    delete[] copy;
    delete[] finish;

    // Close the files
    textFile.close();
    binFile.close();
    decryptText.close();
    decryptBin.close();

    return 0;
}

void writeToBinaryFile(fstream& out, const string& input, int size) {
    char* copy = new char[size];
    for (int i = 0; i < size; i++) {
        copy[i] = input[i];
    }
    out.write(copy, size * sizeof(char));
    delete[] copy;
}

void writeToTextFile(fstream& out, const string& input, int size) {
    for (int i = 0; i < size; i++) {
        out << input[i];
    }
}

char* readFromBinaryFile(fstream& in, int size) {
    long cursor = 0;
    char* array = new char[size];
    in.seekg(cursor, ios::beg);
    in.read(array, size * sizeof(char));
    return array;
}

void writeToBinaryFile2(fstream& out, int size, const char* copy) {
    out.write(copy, size * sizeof(char));
}

void writeToTextFile2(fstream& out, int size, const char* copy) {
    for (int i = 0; i < size; i++) {
        out << copy[i];
    }
}

void encryptString(string& input, int size) {
    for (int i = 0; i < size; i++) {
        if (isalpha(input[i])) {
            input[i] -= 10;
        }
    }
}

char* decryptString(const char* copy, int size) {
    char* finish = new char[size];
    for (int i = 0; i < size; i++) {
        finish[i] = copy[i] + 10;
        if (finish[i] == '*') {
            finish[i] = ' ';
        }
    }
    return finish;
}

void printString(const string& input) {
    cout << input << endl;
}

void printCharArray(int size, const char* copy) {
    for (int i = 0; i < size; i++) {
        cout << copy[i];
    }
    cout << endl;
}
