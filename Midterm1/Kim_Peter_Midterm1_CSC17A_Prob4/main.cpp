/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim 
 * Created on October 22, 2023, 7:42 PM
 * Purpose: Encrypt and Decrypt a 4 digit integer variable 
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>          // strings, strcpy, strlen
#include <string>           // c_str()
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
//Only Universal Physics/Math/Conversions found here
//No Global Variables 
//Higher Dimension arrays requiring definition prior to prototype only 

//Function Prototypes
void encrypt(int[],int);         // encrypts array of numbers and includes size
void decrypt(int[],int);         // same as above but decrypts
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables or constants here
    const int SIZE=12;         // size of array to hold 4 digits, larger than specified
    int choice;                // choice to encrypt or decrypt
    string input;              // numbers to be input
    int numbers[SIZE]; 
    int length;                // length of string to validate 4 digits  
    
    // Input  
        cout<<"Please enter a 4 digit integer. "; 
        cout<<"Enter only digits 0-7."<<endl;
        cin>>input;
    //read in
        for(int i=0; i<SIZE; i++) {
            numbers[i]=input[i]-'0';  // string to int array so adjust for acii codes -'0'
        }
    //validate input length of 4 digits
        length=input.length();
        if(length!=4) {
            cout<<"You did not input a number of 4 digits. Please try again.";
            return 0;  
        }
    // validate numbers being input
//        for(int i=0; i<length; i++) {
//         
//        }
    // validate input range 0-7
        for(int i=0; i<length; i++) { 
            if(numbers[i]>7) {
                cout<<"The input includes a number not in 0-7 range, or a character."<<endl; 
                return 0; 
            }
        }
    //choice of whether to encrypt or decrypt 
    cout<<"Would you like to encrypt or decrypt your input?"<<endl; 
    cout<<"Press 0 to encrypt, 1 to decrypt."<<endl;  
    cin>>choice;            // encrypt or decrypt
    //begin processing
    switch(choice) {
    case 0:         // choice encrypt
        cout<<"You chose to encrypt."<<endl; 
        //process
        encrypt(numbers,length); 
        //output
        cout<<"The number "<<input<<" is ";
        for(int i=0; i<length; i++) {
            cout<<numbers[i]; 
        }
        cout<<" after encryption."<<endl; 
        break; 
    case 1:         //choice decrypt
        cout<<"You chose to decrypt."<<endl; 
        //process
        decrypt(numbers,length); 
        //output
        cout<<"The number "<<input<<" is ";
        for(int i=0; i<length; i++) {
            cout<<numbers[i]; 
        }
        cout<<" after decryption."<<endl; 
        break;
    default: 
        cout<<"You did not enter a valid choice input."<<endl; 
        cout<<"Please try again: 0 to encrypt, 1 to decrypt."<<endl;   
    } 

    //Output
   
    return 0;
}
void encrypt(int array[], int size) {
    for(int i=0; i<size; i++) {
        array[i]+=6; 
        array[i]=array[i]%8;
    }
}
void decrypt(int array[], int size) {
    for(int i=0; i<size; i++) {
        array[i]=(array[i]+2)%8; 
    }
}
