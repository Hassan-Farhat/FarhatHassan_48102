/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 9, 2016, 6:37 PM
 * Purpose : Calculate the miles per gallon of a car
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
    unsigned short galTank = 15, // Gallons in Tank
                   maxDist = 375, // Maximum distance in miles
                   mpg; // Miles per gallon
    
    //Process values
    mpg = maxDist / galTank;
   
    //Display Output
    cout << "Amount of fuel the car tank can hold  = " << galTank << "gal" << endl;
    cout << "Maximum distance the car can travel   = " << maxDist << "mi" << endl;
    cout << "The miles per gallon of the car       = " << mpg << "mpg" << endl;
    
    //Exit Program
    return 0;
}


