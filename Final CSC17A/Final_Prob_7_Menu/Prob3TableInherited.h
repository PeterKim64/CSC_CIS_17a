/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: User
 *
 * Created on December 17, 2023, 2:13 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"
#include <string>
template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
T *augTable; //Augmented Table with sums
    public:
Prob3TableInherited(char *,int,int); //Constructor
~Prob3TableInherited(){delete [] augTable;}; //Destructor
const T *getAugTable(void){return augTable;};
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* name, int rows, int cols)
    : Prob3Table<T>(name, rows, cols) {
    char* fileName=name; 
    this->rows=rows; 
    this->cols=cols; 
    augTable=new T[rows*cols+(rows+cols+1)]; 
    //initialize aug table 
        int augRows=rows+1; 
    int augCols=cols+1; 
    for(int i=0; i<augRows*augCols; i++) {
        augTable[i]=0; 
    }
    //echoback
//    cout<<"calculations done in base class constructor."<<endl; 
//    cout<<this->grandTotal<<endl; 
//    cout<<"rowSums"<<endl; 
//    for(int i=0; i<rows; i++) {
//        cout<<this->rowSum[i]<<" ";
//    }
//    cout<<endl; 
//    cout<<"colSums"<<endl; 
//    for(int i=0; i<cols; i++) {
//        cout<<this->colSum[i]<<" "; 
//    }
    
    /* Very proud of the below work to get this into a loop. It was very
     * confusing to me since the augmented table and table indexes would
     * get shifted every time you would go down a row. I used this long
     * work around to try to find a pattern and it appeared to me after
     * much work. 
     */
    //set aug Table
//    int p=0;  
//    for(int i=p*augCols; i<augCols*p+cols; i++) {
//        augTable[i]=this->table[i];
//        cout<<i<<" i "<<endl; 
//    }
//    augTable[cols+p*augCols]=this->rowSum[p]; 
//    p++;
//    for(int i=p*augCols; i<augCols*p+cols; i++) {
//        augTable[i]=this->table[i-p]; 
//    }
//    augTable[cols+p*augCols]=this->rowSum[1];
//    p++;
//    for(int i=p*augCols; i<augCols*p+cols; i++) {
//        augTable[i]=this->table[i-p];
//    }
//    augTable[cols+p*augCols]=this->rowSum[p]; 
    
    for(int i=0; i<=rows; i++) {
        for(int j=i*augCols; j<augCols*i+cols; j++) {
            augTable[j]=this->table[j-i]; 
        }
        augTable[cols+i*augCols]=this->rowSum[i]; 
    }

    int j=0; 
    for(int i=augRows*augCols-augCols; i<augRows*augCols; i++) {
        augTable[i]=this->colSum[j]; 
        j++;
        if(j==augCols) {                            // last element of the array
            augTable[augRows*augCols-1]=this->grandTotal; 
        }
    }
}

#endif /* PROB3TABLEINHERITED_H */

