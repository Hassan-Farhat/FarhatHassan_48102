/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 1:14 PM
 * Purpose : Calculate the BMI and determine the persons health
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
    unsigned short height, weight, // Height in inches and weight in pounds
            con = 703;             // The constant in the equation
    float bmi;                     // The bmi
    
    //Input values
    cout << "Input your height in inches :" << endl;
    cin >> height;
    cout << "Input your weight in pounds :" << endl;
    cin >> weight;
    
    //Process values + Output
    bmi = (static_cast <float> (weight) * con)/(height * height);
    cout << setprecision(1) << fixed << showpoint;
    if (bmi >= 18.5 && bmi <= 25) 
        cout << bmi << " is in the optimal range." << endl;
    else if (bmi <= 18.5)
        cout << bmi << " is in the underweight range" << endl;
    else 
        cout << bmi << " is in the overweight range" << endl;

    //Exit Program
    return 0;
}
