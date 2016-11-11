/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 10:06 AM
 * Purpose : Calculate distance of a falling object
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float GRAVITY = 9.81;

//Function prototypes
float Distance(float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float time;             //(time) how long the object fell for in seconds
    
    //Input values
    do{
        cout << "How many seconds did the object fall for ?" << endl;
        cin >> time;
    }while (time < 0);
    
    //Display Output
    cout << "The object fell for " << Distance(time) << " m" << endl;

    //Exit Program
    return 0;
}

//Calculate the Distance
float Distance(float time){
    return (time*time*GRAVITY)/2;
}



