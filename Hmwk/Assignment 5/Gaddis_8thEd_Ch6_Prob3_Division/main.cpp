/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 5, 2016, 6:03 PM
 * Purpose : Determine which devision has the greatest sales
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //Name of the devision
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
float getSales (int);
void HstSale (float, float, float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float d1,d2,d3,d4;          //Sales of devision 1,2,3,4 in $
    
    //Process values -> Map inputs to Outputs
    for (int i=1; i<=4; i++){
        if (i==1) d1 = getSales(i);
        else if (i==2) d2 = getSales(i);
        else if (i==3) d3 = getSales(i);
        else d4 = getSales(i);
    }
    
    //Sort and display values:
    HstSale (d1,d2,d3,d4);
    //Exit Program
    return 0;
}

//Asks users to input the sales figures
float getSales (int n){
    string name;                //Name of the devision
    if (n==1) name = "North West";
    else if (n==2) name = "South West";
    else if (n==3) name = "North East";
    else name = "South East";
    float sales;
    do{
        cout << "Input the sales of " << name << " in thousands ($)"<< endl;
        cin >> sales;
    }while (sales < 0);
    return sales;
}

//Determine which sales figure is the highest
void HstSale (float d1, float d2,float d3,float d4){
    //Sort for the maximum value
    float max, min;
    max = d1;
    if (d2 > max) max = d2;
    if (d3 > max) max = d3;
    if (d4 > max) max = d4;
    
    //Display the winner
    cout << setprecision(2) << fixed << showpoint;
    if (max == d1){
        cout << "The North West sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d1<< "$ thousands" << endl;
    }
    if (max == d2){
        cout << "The South West sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d2<< "$ thousands" << endl;
    }
    if (max == d3){
        cout << "The North East sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d3<< "$ thousands" << endl;
    }
    if (max == d4){
        cout << "The South East sector won!" << endl;
        cout << "Its Quarterly Sales figure is: " << d4<< "$ thousands" << endl;
    }
}