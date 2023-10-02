/* 
 * File:   main.cpp
 * Author: Peter Kim 
 * Created: Oct 1 2023
 * Purpose: 2D Augment - Dynamic Memory Allocation
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int **getData(int,int);       //Return the 2-D array and its size.
void prntDat(int**,int,int);  //Print the 2-D Array
void prntAug(int**,int,int);  //Print the 2-D Augmented Array
int **augment(int **,int,int);//Augment the original array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int rows, cols, **array, **aug;
    
    //Initialize Variables
    cin >> rows >> cols;
    
    //Process Input
    array = getData(rows, cols);
    aug = augment(array, rows, cols);
    
    //Output
    prntDat(array, rows, cols);
    prntAug(aug, rows, cols);
    
    //Exit
    delete []aug;
    delete []array;
    return 0;
}

int **getData(int rows,int cols) {
    //Allocate memory (pointers for each row array)
    int **array = new int*[rows];
    //Allocate the memory for each row
    for(int row = 0; row < rows; row++) {
        array[row] = new int[cols];
    }
    //Fill Array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> array[i][j];
        }
    }
    
    return array;
}

void prntDat(int **array,int rows,int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << array[i][j];
            if(j != cols - 1) {
                cout << " ";
            }
        }
        cout <<  endl;
    }
}

void prntAug(int **array,int rows,int cols) {
    for(int i = 0; i < rows + 1; i++) {
        for(int j = 0; j < cols + 1; j++) {
            cout << array[i][j];
            if(j != cols) {
                cout << " ";
            }
        }
        if(i != rows) {
            cout << endl;
        }
    }
}

int **augment(int **array, int rows, int cols) {
    //Allocate memory (pointers for each row array)
    int **aug = new int*[rows + 1];
    
    //Allocate the memory for each row
    for(int row = 0; row < rows + 1; row++) {
        aug[row] = new int[cols + 1];
    }
    
    //Fill first row of augment array
    for(int i = 0; i < cols + 1; i++) {
        aug[0][i] = 0;
    }
    
        //Fill First column of each rows
    for(int i = 0; i < rows + 1; i++) {
        aug[i][0] = 0;
    }
    
    //Fill next rows of augment array
    for(int i = 1; i <= rows; i++) {
        for(int j = 0; j < cols; j++) {
            aug[i][j + 1] = array[i - 1][j];
        }
    }
    
    return aug;
}
