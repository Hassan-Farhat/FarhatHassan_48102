/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 6:51 PM
 * Purpose : Calculate the monthly phone bill
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
    char plan;                       // Type of monthly plan
    float monCost,addMinc, totCost;  // Monthly cost, and cost of additional minutes, Total Cost
    unsigned short numMins, minUsed, // Number of minutes in plan, and number of minutes used
                   totMins;          // Total minutes  
    
    //Input values
    cout << "What plan do you have (A,B,C): "<< endl;
    cin >> plan;
    cout << "How many minutes did you use? " << endl;
    cin >> minUsed;
    
    //Process values
    switch (plan){
        case 'A' : 
            monCost = 39.99;
            numMins = 450;
            addMinc = 0.45;
            (minUsed <= numMins)? totCost = monCost : totCost = ((minUsed - numMins)*addMinc) + monCost;
            cout << "You total amount due is " << totCost << "$" << endl;
            break;
        case 'B' : 
            monCost = 59.99;
            numMins = 900;
            addMinc = 0.40;
            (minUsed <= numMins)? totCost = monCost : totCost = ((minUsed - numMins)*addMinc) + monCost;
            cout << "You total amount due is " << totCost << "$" << endl;
            break;
        case 'C' : 
            monCost = 69.99;
            numMins = 450;
            totCost = monCost;
            cout << "You total amount due is " << totCost << "$" << endl;
            break;
        default :
            cout << "Please enter A,B, or C" << endl;
    }
    
    //Display Output

    //Exit Program
    return 0;
}

