/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: User
 *
 * Created on November 9, 2023, 7:47 PM
 */
#include <fstream>
#include <cstdlib>
#include <iostream> 

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) { 
    fstream inFile; 
    fstream outFile; 
    int standard[13]; 
    
    //open file
    inFile.open("deck.txt", ios::in);
    outFile.open("outFile.txt", ios::out | ios::binary); 
    
    for(int i=0; i<13; i++) {
        inFile>>standard[i]; 
    } 
    outFile.write(reinterpret_cast<char *>(standard), sizeof(standard)); 
    outFile.read(reinterpret_cast<char *>(standard), sizeof(standard)); 
    
    for(int i=0; i<13; i++) {
        cout<<standard[i]<<" ";  
    } 
    
    
    //close file
    outFile.close(); 
    inFile.close(); 
    
    return 0;
}

