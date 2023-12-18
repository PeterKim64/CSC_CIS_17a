/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Prob3Table.h
 * Author: User
 *
 * Created on December 16, 2023, 5:23 PM
 */
#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
using namespace std; 

template<class T>
class Prob3Table{
protected:
int rows; //Number of rows in the table
int cols; //Number of cols in the table
T *rowSum; //RowSum array
T *colSum; //ColSum array
T *table; //Table array
T grandTotal; //Grand total
void calcTable(void); //Calculate all the sums
public:
Prob3Table(char *,int,int); //Constructor then Destructor
~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
const T *getTable(void){return table;};
const T *getRowSum(void){return rowSum;};
const T *getColSum(void){return colSum;};
T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3Table<T>::Prob3Table(char* name,int rows, int cols) {
    char* fileName=name; 
    fstream inFile; 
    this->rows=rows; 
    this->cols=cols; 
    grandTotal=0;
    //create arrays 
    rowSum=new T[rows]; 
    colSum=new T[cols]; 
    table=new T[rows*cols]; 
    //open file and initialize table 
    inFile.open(fileName); 
    for(int i=0; i<rows*cols; i++) {
        inFile>>table[i]; 
    }
    inFile.close();
    
    calcTable(); 
}

template <class T>
void Prob3Table<T>::calcTable(void) {
    T accumulate=0; 
    T accumulateRows; 
    T accumulateCols; 
    //first do rows and total
    for(int i=0; i<rows; i++) {
        accumulateRows=0;               // for each new row sum, need to reset 
        for(int j=0; j<cols; j++) {
        accumulateRows+=table[i*cols+j]; 
        accumulate+=table[i*cols+j];    // since every element will get passed thru, can just do the grand total here
        }
        rowSum[i]=accumulateRows;       // the sum received from inner loop transfers to the array 
    }
    
    //set grand total
    grandTotal=accumulate; 
    //now do columns
    for(int i=0; i<cols; i++) {
        accumulateCols=0;               // resets each sum at 0 
        for(int j=i; j<=rows*cols-1-rows+i; j+=cols) {//first loop goes thru each column. Second loop increment thru the column+row to get to the next column element.
        accumulateCols+=table[j];          
        }
        colSum[i]=accumulateCols;       // set col sums for that column
    }
//       for(int i=0; i<cols; i++) {
//        for(int j=i; j<=rows*cols-1-rows+i; j+=cols) {//first loop goes thru each column. Second loop increment thru the column+row to get to the next column element.
//            cout<<table[j]<<endl;  
//        }
//    }
}

#endif /* PROB3TABLE_H */

