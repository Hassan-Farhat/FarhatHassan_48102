/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 16, 2016, 5:14 PM
 * Purpose : Calculate mpg with user entered variables 
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
    int galTank, tMiles; // Gallons in tank, and total miles.
    float mpg;           //The mpg
    
    //Input values
    cout << "Please enter an integer value for the number of gallons it take to fill up your car:";
    cin >> galTank;
    cout << "Please enter an integer value for the number of miles your car can go on a full tank of gas:";
    cin >> tMiles;
    
    //Calculate the mpg:
    mpg = static_cast<float> (tMiles)/galTank;
    
    //Display Output
    cout << "The miles per gallon =" << mpg << endl;
            
    //Exit Program
    return 0;
}
