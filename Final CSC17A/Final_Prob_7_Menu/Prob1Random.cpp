/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Prob1Random.cpp
 * Author: User
 * 
 * Created on December 17, 2023, 1:59 PM
 */
#include <iostream>
#include <cstdlib>
#include "Prob1Random.h"
using namespace std; 

Prob1Random::Prob1Random(const char size,const char *numbers) {
    numRand=0;          // initialize at 0
    nset=size;          // copy size to nset
    freq=new int[size]; // create freq array
    set=new char[size]; // create set array 
    for(int i=0; i<size; i++) {     // copy array numbers into array set
        set[i]=numbers[i];
        freq[i]=0;
    }
}

char Prob1Random::randFromSet(void) { 
    int compare=int(set[rand()%5]);
    switch(compare) {
        case 19: 
            freq[0]+=1;  
            break; 
        case 34: 
            freq[1]+=1;
            break; 
        case 57:
            freq[2]+=1; 
            break; 
        case 79:
            freq[3]+=1; 
            break; 
        case 126:
            freq[4]+=1; 
            break; 
        default: 
            cout<<"something went wrong in rand from set"<<endl; 
    }
    numRand++; 
    return compare;
} //Returns a random number from the set

int* Prob1Random::getFreq(void) const{
     return freq;     
} //Returns the frequency histogram
char* Prob1Random::getSet(void) const{
    return set; 
} //Returns the set used
int Prob1Random::getNumRand(void) const{
    return numRand; 
} //Gets the number of times randFromSet

Prob1Random::~Prob1Random() {
    delete []set; 
    delete []freq; 
}

