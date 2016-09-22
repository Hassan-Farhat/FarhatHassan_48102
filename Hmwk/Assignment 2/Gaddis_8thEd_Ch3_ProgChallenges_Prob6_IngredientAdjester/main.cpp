/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 17, 2016, 11:16 AM
 * Purpose : Adjust and display ingredients based on user input
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
    float sugar = 1.5f, butter = 1.0f, flour = 2.75f; // Sugar, butter, and flour required to make a standard batch of 48 cookies
    int stAmnt = 48; // Standard amount of cookies in recipe
    int cookies; // Amount of cookies to be made (user input)
    float adjSgr, adjBttr, adjFlr; // Adjusted amount of sugar, butter, and flour
    
    //Input values
    cout << "Please enter an integer for the number of cookies you would like to bake:"<<endl;
    cin >> cookies;
            
    //Calculating the adjustments:
    adjSgr = (sugar  * cookies)/ stAmnt ; 
    adjBttr = (butter  * cookies)/ stAmnt ;
    adjFlr = (flour * cookies)/ stAmnt ;
    
    //Display Output
    cout << setprecision(2) << fixed;
    cout << adjSgr << "cups of sugar" << endl;
    cout << adjBttr << "cups of Butter" << endl;
    cout << adjFlr << "cups of Flour" << endl;

    //Exit Program
    return 0;
}

