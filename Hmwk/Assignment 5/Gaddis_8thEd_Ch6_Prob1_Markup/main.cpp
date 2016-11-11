/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 5, 2016, 5:37 PM
 * Purpose : Calculate the mark up price
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //For output manipulation
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT = 100;

//Function prototypes
float RetailP(float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float wCost, markup, retailP; //Whole sale cost, mark up, and retail price.
    
    //Input values
    do{
        cout << "Input the whole sale cost of the item" << endl;
        cin >> wCost;
    }while (wCost < 0);
    
    do{
        cout << "Input the mark up cost of the item" << endl;
        cin >> markup;
    }while (markup < 0);
    
    //Process values -> Map inputs to Outputs
    retailP = RetailP(wCost, markup);
    
    //Display Output
    cout << setprecision(2) << fixed << showpoint;
    cout << endl << "The retail price will be " << retailP << "$" << endl;

    //Exit Program
    return 0;
}

//Retail price calculation:
float RetailP(float cost, float Mp){
    return ((cost * Mp)/PERCENT) + cost;
}
