/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 9, 2016, 4:51 PM
 * Purpose : Convert quarters, dimes and nickels into cents. 
 */
//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char CNVQC = 25; // Conversion from quarters to cents
const unsigned char CNVDC = 10; // Conversion from dimes to cents
const unsigned char CNVNC = 5;  // Conversion from nickels to cents

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int quarter, // Number of quarters
        dimes,   // Number of dimes
        nickels, // Number of nickels 
        cqrt,    // Number of cents in quarters
        cdim,    // Number of cents in dimes
        cnck,    // Number of cents in nickels
        cents;   // Number of total cents
    
    //Input values
    cout << "Input number of quarters :" << endl;
    cin >> quarter;
    cout << "Input number of dimes :" << endl;
    cin >> dimes;
    cout << "Input number of nickels :" << endl;
    cin >> nickels;
    
    //Converting quarters, dimes, and nickels into cent:
    cqrt = quarter * CNVQC;
    cdim = dimes * CNVDC;
    cnck = nickels * CNVNC;
    cents = cqrt + cdim + cnck;
    
    //Display Output
    cout << "Number of quarters = " << quarter << endl;
    cout << "Number of dimes = " << dimes << endl;
    cout << "Number of nickels = " << nickels << endl;
    cout << "Number of cents = " << cents << endl;
    
    //Exit Program
    return 0;
}


