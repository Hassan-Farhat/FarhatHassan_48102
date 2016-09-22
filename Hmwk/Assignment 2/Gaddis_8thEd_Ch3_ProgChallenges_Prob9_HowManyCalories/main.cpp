/*
 * File:   main.cpp
 * Author: Hassan
 * Created on September 17, 2016, 2:23 PM
 * Purpose : Calculate the amount of calories were eaten by the User
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
    int tCookie = 30, //Number of cookies in one bag
        numSrv  = 10, //Number of servings
        calSrv = 300, //Calories per  serving
        numCPS,       //Number of cookies per serving
        calPC,        //Number of calories per cookie
        numCkie,      //Number of cookies user ate
        numCals;      //Number of calories consumed by user. 
    
    //Input values
    cout << "How many cookies did you eat:" << endl;
    cin >> numCkie;
    
    //Calculations: 
    numCPS = tCookie / numSrv;
    calPC = calSrv / numCPS;
    numCals = numCkie * calPC;
    
    //Display Output
    cout << "The calories per cookie :        " << setw (7) << calPC << endl;
    cout << "The number of cookies you ate :  " << setw(7) << numCkie << endl;
    cout << "The number of calories you ate : " << setw(7) << numCals <<endl;
    //Exit Program
    return 0;
}
