/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 7, 2016, 6:57 PM
 * Purpose : Calculate the amount of people who drink energy drinks.
 */
// Include system level libraries
#include <iostream>  //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

// User Libraries
// Global Libraries
const unsigned char PERCENT=100;

//Functional Prototypes

//Program execution begins here!
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short custmrs= 16500;  // Amount of customers surveyed
    unsigned char pDrnkrs= 15;      // Amount of people who purchase 1 or more drinks per week in percent form
    unsigned char pCDrkrs= 58;      // Amount of citrus drinkers in percent form
    float wPrcher, cDrnkrs;         // Weekly Purchasers, Citrus Drinkers
    
    // Calculations begin here:
    wPrcher = custmrs * pDrnkrs / PERCENT;
    cDrnkrs = wPrcher * pCDrkrs / PERCENT;
    
    // Display Output:
    cout << "Total number of customers surveyed = " << custmrs << endl;
    cout << "Number of customers who purchased energy drinks = " << wPrcher;
    cout << " People" << endl;
    cout << "Number of customers who prefer citrus flavored drinks = " << cDrnkrs;
    cout << " People" << endl;
    return 0;
}

