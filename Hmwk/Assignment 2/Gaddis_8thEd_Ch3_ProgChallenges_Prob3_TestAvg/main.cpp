/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 16, 2016, 6:25 PM
 * Purpose : Calculate the test Average
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
    float test1, test2, test3, test4, test5, // Test 1,2,3,4,5 scores in percent
          avgScr;                            // Average test score
    
    //Input values
    cout << "Input test scores in percent:"<< endl;
    cin >> test1 >> test2 >> test3 >> test4 >> test5;
    
    //Calculating test average
    avgScr = (test1 + test2 + test3+ test4 + test5) / 5; 
    
    //Display Output
    cout << setprecision(1) << fixed;
    cout <<"Test 1 score ="<< setw(5) << test1 << "%" << endl; 
    cout <<"Test 2 score ="<< setw(5) << test2 << "%" << endl;
    cout <<"Test 3 score ="<< setw(5) << test3 << "%" << endl;
    cout <<"Test 4 score ="<< setw(5) << test4 << "%" << endl;
    cout <<"Test 5 score ="<< setw(5) << test5 << "%" << endl;
    cout <<"Average test score (mean( is score ="<< setw(5) << avgScr << "%" << endl;
    
    //Exit Program
    return 0;
}

