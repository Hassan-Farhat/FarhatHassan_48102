/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 16, 2016, 7:10 PM
 * Purpose : Male and Female Percentage of a class
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
    int male, female, tPeople; // Number of male students, number of female students, total number of people
    float pMale, pFemale; //Percentage of males and percentage of females
    
    //Input values
    cout << "Input an integer value for the number of males:" << endl;
    cin >> male; 
    cout << "Input an integer value for the number of females:"<<endl;
    cin >> female; 
    
    //Calculate the Percent male to female
    tPeople = male + female;
    pMale = static_cast <float> (male)/tPeople;
    pFemale = static_cast <float> (female)/tPeople;
    
    //Display Output
    cout << setprecision(2) << fixed;
    cout << "The total number of people = " << setw(1) << tPeople << endl;
    cout << "The percentage of male students = " << setw(1) << pMale << "%" << endl;
    cout << "The percentage of female students = " << setw(1) << pFemale << "%" << endl;
    //Exit Program
    return 0;
}

