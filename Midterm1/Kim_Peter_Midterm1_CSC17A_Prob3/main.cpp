/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Peter Kim 
 * Created on October 21, 2023, 10:42 PM
 * Purpose: Stats (mean, median, mode) on an array  
 */

// Code imported from Github, only finishing last function "stats" 

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    //Initialize variables 
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0; 
    int sumArray;               // sum of array to find average 
    
    //Find average     
    for(int i=0; i<array->size; i++) {
        sumArray+=array->data[i]; 
    }
    stats->avg=sumArray/(array->size); 
    
    //Find modes
    int nModes=0;
    
    //copy pasting from code-e mode function
     //Find the max Frequency
    int freq=1; 
    int freqTop=1; 
    int compare=array->data[0];         // set compare to the first element in the ary
    for(int i=1; i<array->size; i++) {      // start from the second element in the ary
        if(array->data[i]==compare) {
            freq++;
            
            if(freq>freqTop)
            freqTop=freq;           // Find max freqeuency out of all the numbers
        }
        else {
            freq=1; 
            compare=array->data[i]; 
        }
        
    }
    //Find the number of modes
    // count the amount of modes by counting amount of times freq==TopFreq
    freq=1;                     
    compare=array->data[0];             // Reset the values for the comparisons
    for(int i=1; i<array->size; i++) {      // start from the second element in the ary
        if(array->data[i]==compare) {
            freq++;
            if(freq==freqTop) {
                nModes++;            // now that we've found the max frequency, if freq==freqTop, add count to the mode
                
            }
        }
        else {
            freq=1; 
            compare=array->data[i]; 
        }
        
    }
    //Find the index that the modes are at 
    int modeIndex[nModes];            // array with index of where the modes are found
    int countIndex=0;                    // counts the index when reading in numbers for modeIndex
    freq=1; 
    compare=array->data[0]; 
    for(int i=1; i<array->size; i++) {      // start from the second element in the ary
        if(array->data[i]==compare) {
            freq++;
            if(freq==freqTop) {
                modeIndex[countIndex]=i; 
                countIndex++; 
                
            }
        }
        else {
            freq=1; 
            compare=array->data[i]; 
        }
        
    }
    if(nModes!=0)stats->mode->data=new int[nModes];
    stats->modFreq=freqTop; 
    stats->median=0;
    
    //Copy modeIndex into the new stats->mode->data memory 
    for(int i=0; i<nModes; i++) {
        stats->mode->data[i]=array->data[modeIndex[i]];
    }
    // number of modes
    stats->mode->size=nModes; 
    
    //Find median
    int medianIndex;                // index where median is kept 
    int evenOrOdd;                 // even or odd array size
    evenOrOdd=array->size % 2;
    if(evenOrOdd==0) {
        cout<<"The number is even. "<<endl; 
        medianIndex=array->size / 2;
        
        //Calculate  median for an even size of numbers
        stats->median=(array->data[medianIndex]+array->data[medianIndex+1])/2.0;
    }
    else if(evenOrOdd!=0) {
        cout<<"The number is odd. "<<endl;
        medianIndex=array->size /2; 
        stats->median=array->data[medianIndex];    //calculate median for odd size
    }
    
    
    
   
    return stats;
}