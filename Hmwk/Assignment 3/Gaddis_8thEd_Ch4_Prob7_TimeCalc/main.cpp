/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 1:36 PM
 * Purpose : Time calculator
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
    unsigned int sec; //Number of seconds
    unsigned short min, hr, days, sLeft; //Number of minutes, hours, days, and the left over seconds
    
    //Input values
    cout << "Input number of seconds:" << endl;
    cin >> sec;   
    
    //Process values -> Map inputs to Outputs
    if (sec >= 60 && sec < 3600){
        min = sec / 60;
        sLeft = sec % 60;
        cout << "Time in minutes and seconds " << min << "mins : " << sLeft << "secs" << endl;
    }
    else if (sec >= 3600 && sec < 86400){
        hr = sec / 3600;
        sLeft = sec % 3600; 
        min = sLeft / 60;
        sLeft = sec % 60;
        cout << "Time in hours, minutes, and seconds " << hr << "hr : " << min << "mins : " << sLeft << "secs" << endl;      
    }
    else {
        days = sec / 86400;
        sLeft = sec % 86400; 
        hr = sLeft / 3600;
        sLeft = sec % 3600; 
        min = sLeft / 60;
        sLeft = sec % 60;
        cout << "Time in hours, minutes, and seconds " << days << "days : " << hr << "hr : " << min << "mins : " << sLeft << "secs" << endl;
    }
    
    //Display Output

    //Exit Program
    return 0;
}
