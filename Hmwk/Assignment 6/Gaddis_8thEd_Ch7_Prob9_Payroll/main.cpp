/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 16, 2016, 6:34 PM
 * Purpose : Calculate the payroll of each employee
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void InHrsPR (int [], int[], float [], char);
void Wages (float [], float [], int [], char);
void EReport (float [], float [], int [], int [], char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE = 9;
    char used = 7;
    int empID[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489}; // The employee ID numbers
    int hours[SIZE];        //The hours worked by each employee
    float payRate[SIZE];    //The payrate of each employee
    float wages[SIZE];      //The wages of each employee
    
    //Input values
    InHrsPR (empID,hours,payRate, used);
    
    //Calculation of wages
    Wages (payRate, wages, hours, used);
    
    //Display Output
    EReport (payRate, wages, empID, hours, used);
    
    //Exit Program
    return 0;
}

//Fill in the the hours:
void InHrsPR (int empID[] , int hours[], float payRate[], char used){
    cout << "Input the number of hours,(not less that 0)," << endl;
    cout << "and pay rate of each employee,(not less that 15$/hr)" << endl;
    for (int i=0; i<used; i++){
        do{
            cout << "Employee " << empID[i] << " worked : ";
            cin >> hours[i];
        } while (hours[i] < 0);
        do{
            cout << "Employee " << empID[i] << " pay rate is : ";
            cin >> payRate[i];
        } while (payRate[i] < 15); 
        cout << endl;
    }
}

//Calculate the wage of each employee
void Wages (float payRate[], float wages[], int hours[], char used){
    for (int i=0; i<used; i++){
        wages[i] = payRate[i] * hours[i]; 
    }
}

//Display the employee report:
void EReport (float payRate[], float wages[], int empID[], int hours[], char used){
    for (int i=0; i<used; i++){
        cout << "Employee:   " << empID[i] << endl;
        cout << "Hours work: " << hours[i] << endl;
        cout << "Payrate:    " << payRate[i] << " $/hr" << endl;
        cout << "Wage:       " << wages[i] << " $" << endl;
        cout << "===========================================" << endl;
    }
}