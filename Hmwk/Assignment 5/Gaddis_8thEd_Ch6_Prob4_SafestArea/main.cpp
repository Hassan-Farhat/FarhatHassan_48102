/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 5, 2016, 6:59 PM
 * Purpose : The Safest and Worst Area for car accidents
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void getAcdnt(int &, int &, int &, int &, int &);
void Low(int, int, int, int, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int north, south, east, west, cent; //the number of car accidents
    
    //Input values
    getAcdnt(north,south,east,west,cent);
    
    //Sort and Display Output:
    Low(north,south,east,west,cent);

    //Exit Program
    return 0;
}

//Input the number of accidents:
void getAcdnt(int &north, int &south, int &east, int &west, int &cent){
    int x;
    for (int i=1; i<=5; i++){
        string name;
        if (i == 1) name = "North";
        else if (i == 2) name = "South";
        else if (i == 3) name = "East";
        else if (i == 4) name = "West";
        else if (i == 5) name = "Center";
        do{
            cout << "Input the number of accidents in the " << name << endl;
            cin >> x;
        }while (x < 0);
        if (i == 1) north = x;
        else if (i == 2) south = x;
        else if (i == 3) east = x;
        else if (i == 4) west = x;
        else if (i == 5) cent = x;
    }
}

//Sort and display the output
void Low(int north,int south,int east,int west,int cent){
    //Sort the 5 regions of a city
    int min;
    min = north;
    if (south < min) min = south;
    if (east < min)  min = east;
    if (west < min)  min = west;
    if (cent < min)  min = cent;
    //Display the safest and the most dangerous
    cout << endl;
    if (min == north){
        cout << "The safest place is the North with " << north << endl;
    }
    if (min == south){
        cout << "The safest place is the South with " << south << endl;
    }
    if (min == east){
        cout << "The safest place is the East with " << east << endl;
    }
    if (min == west){
        cout << "The safest place is the West with " << west << endl;
    }
    if (min == cent){
        cout << "The safest place is the Center with " << cent << endl;   
    }
}

