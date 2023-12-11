/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ModifiedTime.h
 * Author: User
 *
 * Created on December 10, 2023, 6:27 PM
 */

// ModifiedTime.h
#ifndef MODIFIEDTIME_H
#define MODIFIEDTIME_H

// Base class
class ModifiedTime
{
protected:
    int customHour, customMin, customSec;
    char customDay;

public:
    ModifiedTime();
    class badHour { };
    class badSeconds { };
};

// Derived Class
class ModifiedMilTime : public ModifiedTime
{
private:
    int milCustomHour, milCustomSec;

public:
    ModifiedMilTime();
    void display();
};

#endif /* MODIFIEDTIME_H */

