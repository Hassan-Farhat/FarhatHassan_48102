/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 9, 2016, 9:01 AM
 * Purpose : Calculate hotel occupancy
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //To clean up the output
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short numFlrs,   //Number of floors 
                   numRoom,   //Number of rooms on each floor
                   numOcc,    //Number of occupied rooms
                   totRoom=0, //Total number of rooms
                   totOcc=0;  //Total number of occupied rooms
    float perOcc;             //Number of rooms occupied
    
    //Input number of rooms:
    cout << "Please input the number of floors are in the hotel:" << endl;
    cin >> numFlrs;
    
    //Processing values: Loop, calculations:
    for (int i = 1; i <= numFlrs; i++){
        if (i==13) {
            i++;
        }
        cout << "Floor " << i << endl;
        cout << "Input number of rooms:" << endl;
        cin >> numRoom;
        cout << "Input number of rooms occupied" << endl;
        cin >> numOcc;
        while (numOcc > numRoom){
            cout << "Impossible entry please re-input number of occupied rooms :" << endl;
            cin >> numOcc;
        }
        totRoom+=numRoom;
        totOcc+=numOcc;
    }
    perOcc = static_cast<float> (totOcc)/totRoom * 100;
    
    //Display output:
    cout << "Total number of floors         : " << numFlrs << endl;
    cout << "Total number of rooms          : " << totRoom << endl;
    cout << "Total number of occupied rooms : " << totOcc  << endl;
    cout << setprecision(2) << fixed;
    cout << "The percentage of rooms occupied : "<< perOcc << "%" << endl;
    //Exit Program
    return 0;
}