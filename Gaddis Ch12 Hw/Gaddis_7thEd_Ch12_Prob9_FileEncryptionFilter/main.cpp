/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 * Created on December 6, 2023, 8:04 PM
 * Purpose: File Encryption Filter
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void writeTextToFile(fstream &fileStream, string data);
void writeBinaryToFile(fstream &fileStream, string data);
void encryptMessage(string &message);
void printMessage(string message);

int main(int argc, char** argv) {
    fstream textFile, binaryFile;
    textFile.open("data.txt", ios::in | ios::out);
    binaryFile.open("data.bin", ios::in | ios::out | ios::binary);
    
    string userInput;
    
    cout << "Enter the sentence input: " << endl;
    cin.clear();
    getline(cin, userInput);
    
    encryptMessage(userInput);
    writeTextToFile(textFile, userInput);
    writeBinaryToFile(binaryFile, userInput);
    
    cout << "The Encrypted Message is: " << endl;
    printMessage(userInput);
    
    textFile.close();
    binaryFile.close();
    
    return 0;
}

void writeBinaryToFile(fstream &out, string data) {
    int dataSize = data.size();
    char *dataCopy = new char[dataSize];
    for (int i = 0; i < dataSize; i++) {
        dataCopy[i] = data[i];
    }
    out.write(reinterpret_cast<char *>(dataCopy), dataSize * sizeof(char));
    delete[] dataCopy;
}

void writeTextToFile(fstream &out, string data) {
    int dataSize = data.size();
    for (int i = 0, n = dataSize; i < n; i++) {
        out << data[i];
    }
}

void encryptMessage(string &message) {
    int messageSize = message.size();
    char encryptedChar;
    for (int i = 0, n = messageSize; i < n; i++) {
        if ((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z')) {
            encryptedChar = message[i] - 10;
            message[i] = encryptedChar;
        }
    }
}

void printMessage(string message) {
    int messageSize = message.size();
    for (int i = 0; i < messageSize; i++) {
        cout << message[i];
    }
}


