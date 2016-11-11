/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 6:46 PM
 * Purpose : Calculate Hospital Charge
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //Used to determine if its an in or out patient
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void GetData(int &, float &, float &, float &);
void GetData(float &, float &);
float Charge(float, float);
float Charge(int, float, float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int days;       //Number of days spent in the hospital
    float hCharge,  //Hospital services charges
          mCharge,  //Medication charges
          dRate,    //Daily Rate
          cost;     //Total cost
    string type;    //Type of patient
    
    //Input values, calculate hospital charge, and display the cost
    cout << "Is this an in-patient or an out-patient?" << endl;
    do{
        cout << "Type in for in-patient or out for out-patient" << endl;
        cin >> type;
    }while(!(type == "in") && !(type == "out"));
    cout << setprecision(2) << fixed  << showpoint;
    if(type == "in"){
        GetData(days, hCharge, mCharge, dRate);
        cost = Charge(days, hCharge, mCharge, dRate);
        cout << endl << "The total cost of service = " << cost << " $" << endl;
    }
    else{
        GetData(hCharge, mCharge);
        cost = Charge(hCharge, mCharge);
        cout << endl << "The total cost of service = " << cost << " $" << endl;
    }

    //Exit Program
    return 0;
}

//Input the data for the in patient:
void GetData(int &days, float &hCharge, float &mCharge, float &dRate){
    do{
        cout << endl << "Days spent in hospital: ";
        cin >> days;
    }while (days < 0);
    do{
        cout << "Cost per day: ";
        cin >> dRate;
    }while (dRate < 0);
    do{
        cout << "Hospital service charge: ";
        cin >> hCharge;
    }while (hCharge < 0);
    do{
        cout << "Hospital Medication charge: ";
        cin >> mCharge;
    }while (mCharge < 0);
}

//Input the date for th out patient:
void GetData(float &hCharge, float &mCharge){
    do{
        cout << endl << "Hospital service charge: ";
        cin >> hCharge;
    }while (hCharge < 0);
    do{
        cout << "Hospital Medication charge: ";
        cin >> mCharge;
    }while (mCharge < 0);
}

//Calculate the cost for the In patient:
float Charge(int days, float hCharge, float mCharge, float dRate){
    return (days * dRate) + hCharge + mCharge;
}

//Calculate the cost for the Out patient:
float Charge(float hCharge, float mCharge){
    return hCharge + mCharge;
}