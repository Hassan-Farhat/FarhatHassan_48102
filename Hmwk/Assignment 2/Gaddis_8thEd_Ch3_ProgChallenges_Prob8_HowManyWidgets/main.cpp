/*
 * File:   main.cpp
 * Author: Hassan Faraht
 * Created on September 17, 2016, 2:07 PM
 * Purpose : Calculate the number of widgets
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float wWidget = 12.5f, // Weight of a widget in pounds
          nWidget, wPallet, tWeight; // Number of widgets, weight of pallet, and total weigh (all in pounds)
    
    //Input values
    cout << "Enter the weight of pallet:" << endl;
    cin >> wPallet;
    cout << "Enter the total weight of the pallet with the widgets" << endl;
    cin >> tWeight;
    
    //Calculate the number of widgets :
    nWidget = (tWeight - wPallet) / wWidget; 
    
    //Display Output
    cout << setprecision(1) << fixed;
    cout << "The weight of one pallet is :      " << wPallet << endl;
    cout << "The weight of a pallet + widgets : " << tWeight << endl;
    cout << "The number of widgets :            " << nWidget << endl;

    //Exit Program
    return 0;
}

