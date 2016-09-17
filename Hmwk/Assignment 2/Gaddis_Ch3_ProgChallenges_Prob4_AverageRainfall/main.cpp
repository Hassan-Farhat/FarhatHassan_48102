/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 16, 2016, 6:43 PM
 * Purpose : Calculate the amount of average rainfall
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string  month1, month2, month3; // The 3 testing months 
    float rFall1, rFall2, rFall3,   // The rainfall of the three months
          avgrFall;                 // The average rain fall 
    
    //Input the months and the rainfall of each month
    cout << "Enter the name of 3 different months:" << endl;
    cin >> month1 >> month2 >> month3;
    cout << "Enter the amount of rainfall in each month respectively:" << endl;
    cin >> rFall1 >> rFall2 >> rFall3; 
    
    //Calculating the average rainfall
    avgrFall = (rFall1 + rFall2+ rFall3) / 3;
            
    //Display Output
    cout << setprecision(2) << fixed;
    cout << "The Average rain fall of " << month1 << " , " << month2 << " and " << month3 << " is " << avgrFall << endl;
    
    //Exit Program
    return 0;
}
