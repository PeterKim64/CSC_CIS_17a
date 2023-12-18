/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Prob2Sort.h
 * Author: User
 *
 * Created on December 17, 2023, 2:01 PM
 */

#include <cstdlib>
using namespace std; 

#ifndef PROB2SORT_H
#define PROB2SORT_H

template<class T>
class Prob2Sort{
private:
int *index; //Index that is utilized
char *sorted; 
//in the sort
public:
Prob2Sort(){index=NULL;}; //Constructor
~Prob2Sort(){delete []index;}; //Destructor
T * sortArray(const T*,int,bool); //Sorts a single column array
T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array
//represented as a 1 dim array
};

template <class T>
T* Prob2Sort<T>::sortArray(const T* array,int size,bool ascend) {
    
}
/*
 * This class function sorts a single column of a 2D array for a data type specified. 
 */
template <class T>
T* Prob2Sort<T>::sortArray(const T* array,int column,int row,int columnToSort,bool ascend) {
    //Declare variables
    int size=column*row;
    int increment=row;              // increments after each column index
    columnToSort-=1;                // subtract one for index of column array
    index=new int[size];            // array of indexes of column to be sorted
    //Initialize index array
    for(int i=0; i<size; i++) {
        index[i]=i;    
    }
    int tempIndex=0;
        bool swap;  
        do {
            swap=false; 
            for(int i=columnToSort; i<size-row+columnToSort; i+=increment) {
                if(array[index[i]]<array[index[i+increment]]) {
                    tempIndex=index[i]; 
                    index[i]=index[i+increment]; 
                    index[i+increment]=tempIndex; 
                    swap=true;
                }
                else if(array[index[i]]>array[index[i+increment]] && ascend==false){
                    tempIndex=index[i]; 
                    index[i]=index[i+increment]; 
                    index[i+increment]=tempIndex; 
                    swap=true;
                }
            }    
        } while(swap);

       
    
    char* sorted=new char[size];
    for(int i=0; i<size; i++) {
        sorted[i]=array[index[i]];
    }
    return sorted; 
}

#endif /* PROB2SORT_H */

