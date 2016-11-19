/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 18, 2016, 5:58 PM
 * Purpose : RainFall Statistic
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void FillRain (int[], int);
void HRain (int[], int);
void LRain (int[], int);
void DplyRain (int [], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;   //Size of the array
    int rain[SIZE];         //Amount of rain in inch
    int months = 12;        //Number of months
        
    //Input values, calculate, and display the average and total amount of rain fall 
    FillRain (rain, months);
    
    
    //Determine what is the highest and lowest
    HRain (rain, months);
    LRain (rain, months);
    
    //Display the array
    DplyRain (rain, months);
    
    //Exit Program
    return 0;
}

//Fill in the amount of rain each month and display the average and total.
void FillRain (int rain[], int months){
    int total=0;      //Total amount of rainfall
    float avg;        //Average amount of rainfall
    for (int i=0; i<months; i++){
        rain[i]=rand()%49 + 1;
        total += rain[i];
    }
    avg = total / months;
    cout << setprecision(2) << fixed << showpoint;
    cout << "The total was " << total << " inches of rain in the " << months << " month period." << endl;
    cout << "The average was " << avg << " inches of rain the " << months << " month period." << endl; 
}

//Find the highest and lowest.
void HRain (int rain[], int months){
    int max = rain[0],      //The maximum amount of rain per month.
        month = 1;          //The month with the maximum amount.
    for (int i=1; i<months; i++){
        if (rain[i] > max){
            max = rain[i];
            month = i+1;
        }
    }
    cout << "Highest month: " << month 
            << " it had " << max << " inches of rainfall." << endl;
}

void LRain (int rain[], int months){
    int min = rain[0],      //The minimum amount of rain per month.
        month = 1;          //The month with the minimum amount.
    for (int i=1; i<months; i++){
        if (rain[i] < min){
            min = rain[i];
            month = i+1;
        }
    }
    cout << "Lowest month: " << month 
            << " it had " << min << " inches of rainfall." << endl;
}

//Display the array:
void DplyRain (int rain[], int months){
    for (int i=0; i<months; i++){
        cout << "Month " << i+1 << ": " << rain[i] << " inches" << endl;
    }
}