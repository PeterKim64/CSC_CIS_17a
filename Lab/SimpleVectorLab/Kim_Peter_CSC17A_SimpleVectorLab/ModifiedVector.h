/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   ModifiedVector.h
 * Author: User
 *
 * Created on December 10, 2023, 6:20 PM
 */

#ifndef MODIFIEDVECTOR_H
#define MODIFIEDVECTOR_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <class T>
class ModifiedVector
{
private:
    T *arrayPointer;
    int vectorSize;
    void memoryError();
    void subscriptError();

public:
    // Default constructor
    ModifiedVector() { arrayPointer = 0; vectorSize = 0; }

    // Constructor declaration
    ModifiedVector(int);

    // Copy constructor declaration
    ModifiedVector(const ModifiedVector &);

    // Destructor declaration
    ~ModifiedVector();

    // Accessor to return the vector size
    int getSize() const { return vectorSize; }

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T &operator[](const int &);

    // Remove function pulls off the end of the array and resizes
    T remove();

    // Insert function pushes on the end of the array but first resizes
    void insert(T);
};

// Remove function
template <class T>
T ModifiedVector<T>::remove()
{
    T *newPtr = new T[--vectorSize];

    // Copy the original values into the new array
    for (int count = 0; count < vectorSize; count++)
        *(newPtr + count) = *(arrayPointer + count);

    T endRet = arrayPointer[vectorSize];

    // Delete the old array
    delete[] arrayPointer;

    // Set the old pointer to the new pointer
    arrayPointer = newPtr;

    // Return the value popped off
    return endRet;
}

// Insert function
template <class T>
void ModifiedVector<T>::insert(T val)
{
    T *newPtr = new T[vectorSize + 1];

    // Copy the original values into the new array
    for (int count = 0; count < vectorSize; count++)
        *(newPtr + count) = *(arrayPointer + count);

    // Push the new value onto the array
    *(newPtr + vectorSize++) = val;

    // Delete the old array
    delete[] arrayPointer;

    // Set the old pointer to the new pointer
    arrayPointer = newPtr;
}

// Constructor for ModifiedVector class. Sets the size of the array and allocates memory for it.
template <class T>
ModifiedVector<T>::ModifiedVector(int s)
{
    vectorSize = s;
    // Allocate memory for the array.
    try
    {
        arrayPointer = new T[s];
    }
    catch (bad_alloc)
    {
        memoryError();
    }

    // Initialize the array.
    for (int count = 0; count < vectorSize; count++)
        *(arrayPointer + count) = 0;
}

// Copy Constructor for ModifiedVector class.
template <class T>
ModifiedVector<T>::ModifiedVector(const ModifiedVector &obj)
{
    // Copy the array size.
    vectorSize = obj.vectorSize;

    // Allocate memory for the array.
    arrayPointer = new T[vectorSize];
    if (arrayPointer == 0)
        memoryError();

    // Copy the elements of obj's array.
    for (int count = 0; count < vectorSize; count++)
        *(arrayPointer + count) = *(obj.arrayPointer + count);
}

// Destructor for ModifiedVector class.
template <class T>
ModifiedVector<T>::~ModifiedVector()
{
    if (vectorSize > 0)
        delete[] arrayPointer;
}

// memError function. Displays an error message and terminates the program when memory allocation fails.
template <class T>
void ModifiedVector<T>::memoryError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

// subscriptError function. Displays an error message and terminates the program when a subscript is out of range.
template <class T>
void ModifiedVector<T>::subscriptError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

// getElementAt function. The argument is a subscript. This function returns the value stored at the subscript in the array.
template <class T>
T ModifiedVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= vectorSize)
        subscriptError();
    return arrayPointer[sub];
}

// Overloaded [] operator. The argument is a subscript. This function returns a reference to the element in the array indexed by the subscript.
template <class T>
T &ModifiedVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= vectorSize)
        subscriptError();
    return arrayPointer[sub];
}

#endif


