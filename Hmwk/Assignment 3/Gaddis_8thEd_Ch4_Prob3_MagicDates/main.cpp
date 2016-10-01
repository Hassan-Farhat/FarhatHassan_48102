/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 12:35 PM
 * Purpose : Determine weather or not the input is a "magic date"
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short month, day, year, // The date mm/dd/yy
                   multi;            // The test variable  
   
    //Input values
    cout << "Please input the date in dd/mm/yy format to determine it is a magic date"<< endl
            << "Please only use the last two digits for the year:"<< endl;
    cin >> month >> day >> year;
    
    //Process values -> Map inputs to Outputs
    multi = day * month;
    
    //Display Output
    cout << day << "-" << month << "-" << year << ((multi == year)? " is a magic date." : " is not a magic date.") << endl;

    //Exit Program
    return 0;
}