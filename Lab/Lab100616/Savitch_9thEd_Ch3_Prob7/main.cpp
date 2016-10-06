/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 6, 2016, 11:54 AM
 * Purpose : Calculate your weight
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float GRAVITY = 6.673e-8f,   //Universal Gravity Constant (cm^3/g/sec^2)
            CNKGGRM = 1000,        //Conversion from kilograms to grams
            CNSGGRM = 14593.9f,    //Conversion from Slugs to grams
            CNKMMET = 1000,        //Conversion from Kilometers to meters
            CNMETCM = 100,         //Conversion from meters to centimeters
            CNDYNLB = 2.24809e-6f, //Conversion from dyne to pounds
            CNSGLBS = 32.174f;     //Conversion form Slug to pounds


//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float msEarth = 5.972e24f,//Google lookup --> Mass of earth in Kg
          msMark = 6.0f,      //Mass of Mark --> Slug
          rdEarth = 6371.0f,  //Google radius of earth
          weight,             //Force of attraction from physics
          wCheck;             //Weight check
    
    //Input values
    msEarth *= CNKGGRM;         //Convert mass of the earth to grams
    msMark *= CNSGGRM;          //Convert mass of mark to grams
    rdEarth *= CNKMMET*CNMETCM; //Convert the radius of earth to centimeters
    
    //Process values -> Map inputs to Outputs
    weight = GRAVITY*msMark*msEarth/rdEarth/rdEarth;
    weight *= CNDYNLB;   // Convert dyne to lbs
    wCheck = 6*CNSGLBS; 
    
    //Display Output
    cout << "Because of the weak gravity of earth Mark weighs = " << weight << "lbs"<< endl;
    cout << "As a check Mark's weight is = " << wCheck << "lbs" << endl;
    cout << "The percentage error in the radius of earth = +-" << 100.0f*18/6371<<"%"<<endl;
    cout << "The margin of error for the weight = " << (weight-wCheck)/weight*100.0f<<"%"<<endl;
    
    //Exit Program
    return 0;
}

