/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 13, 2016, 12:27 PM
 * Purpose : Calculate Average/Mean and Standard Deviation
 */
//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int x1,x2,x3,x4,x5; //Input values
    float avg,stdev;
    
    //Input values
    cout<<"This program calculates the mean and standard deviation"<<endl;
    cout<<"Input 5 values"<<endl;
    cin>>x1>>x2>>x3>>x4>>x5;

    //Process values 
    avg = (x1+x2+x3+x4+x5)/5;
    stdev = pow(((x1-avg)*(x1-avg)+(x2-avg)*(x2-avg)+(x3-avg)*(x3-avg)+(x4-avg)*(x4-avg)+(x5-avg)*(x5-avg))/4,0.5);
    
    //Display Output
    cout<< "The Input Values = " << x1 << x2 << x3 << x4 << x5;
    cout<< "The mean = "<<avg<<endl;
    cout<< "The standard deviation = "<<stdev<<endl;
    
    //Exit Program
    return 0;
}