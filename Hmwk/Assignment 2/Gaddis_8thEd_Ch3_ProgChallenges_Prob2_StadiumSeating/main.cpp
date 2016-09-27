/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 16, 2016, 5:34 PM
 * Purpose : Calculate the amount of income generated
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
    float classA = 15,     // Cost of Class A,B,C seats in dollars.
          classB = 12,
          classC = 9;
    int nClassA, nClassB, nClassC; // Number of Class A,B,C tickets sold
    float tIncome;                 //Total income made
       
    //Input values
    cout << "Enter an integer for the number of Class A tickets sold:" << endl;
    cin >> nClassA;
    cout << "Enter an integer for the number of Class B tickets sold:" << endl;
    cin >> nClassB;
    cout << "Enter an integer for the number of Class C tickets sold:" << endl;
    cin >> nClassC;
    
    //Calculate the total income:
    tIncome = (classA*nClassA) + (classB*nClassB) + (classC*nClassC);
    
    //Display Output
    cout << setprecision(2) << fixed;
     cout << "\nCost of seats in each class\n";
    cout << "================="<< endl;
    cout << "Class A $" << setw(5) << classA << endl;
    cout << "Class B $" << setw(5) << classB << endl;
    cout << "Class C $" << setw(5) << classC << endl;
    cout << "\nTotal Income\n";
    cout << "================="<< endl;
    cout << "Total Income = " << "$" << tIncome << endl;
    //Exit Program
    return 0;
}

