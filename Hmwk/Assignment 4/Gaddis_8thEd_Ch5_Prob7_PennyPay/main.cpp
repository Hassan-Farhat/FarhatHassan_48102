/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 8, 2016, 6:26 PM
 * Purpose : Calculate the salary
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
    float dollars;
    int cents=1; 
    unsigned short k;
    
    //Input values
    cout << "Input the number of days you will get paid:" << endl;
    cin >> k;
    
    //Process values
    for (int i=0; i<k; i++){
        cents = cents * 2;
    }
    
    dollars = cents/100.0;
    
    //Display output
    cout << "The total number of cents : " << cents << endl;
    cout << "The total dollar amount will be : " << dollars << "$"<< endl;

    //Exit Program
    return 0;
}

