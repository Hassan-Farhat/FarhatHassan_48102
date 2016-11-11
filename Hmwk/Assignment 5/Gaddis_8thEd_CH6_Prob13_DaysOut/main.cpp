/* 
 * File:   main.cpp
 * Author: Hassan
 * Created on November 6, 2016, 5:11 PM
 * Purpose: Calculate the average number of absent days
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int NumEply();
int NumDays(int);
float AvgDays(int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int numEply,      //Number of Employees
        numDays;      //Number of days absent
    float avgDays;    //Average number of days absent
    
    //Input values
    numEply = NumEply();
    numDays = NumDays(numEply);
    
    //Calculate the average number of days the employees were absent
    avgDays = AvgDays(numEply, numDays);
    
    //Display Output
    cout << setprecision(2) << showpoint << fixed;
    cout << endl << "The total number of employees : " << numEply << endl;
    cout << "The average number of days absent for the employees : "
         << avgDays << " days" << endl;

    //Exit Program
    return 0;
}

//Input the number of employees
int NumEply(){
    int x;
    do{
        cout << "Enter how many employees in the company : "; 
        cin >> x;
    }while (x <= 0);
    return x;
}

//Input number of absent days per employee
int NumDays(int numEply){
    int totDays = 0;    //Total number of absent days
    int nDays;          //Number of days each employee was absent
    for (int i=1; i<=numEply; i++){
        do{
            cout<< "Input the number of days employee " <<i<< " was absent : ";
            cin >> nDays;
        }while (nDays < 0);
        totDays += nDays;
    }
    return totDays;
} 

//Calculate the average number of days the employees were absent
float AvgDays(int numEply, int numDays){
    return static_cast <float> (numDays) / numEply;
}