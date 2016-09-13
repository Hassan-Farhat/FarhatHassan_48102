/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 13, 2016, 11:55 AM
 * Purpose : How many millimeters will the ocean level rise in 5, 7, and 10 years time,
             calculate when riverside homeowners will have beach front property
 */
// Include system level libraries
#include <iostream>  //Input/Output Libraries
using namespace std; //Libraries compiled under standard namespace

// User Libraries
// Global Libraries
const float CNVMMFT = 304.8f; //Conversion from mm to ft
const float CNVMMM = 1000.0f; //Conversion form mm to m
//Functional Prototypes

//Program execution begins here!
int main(int argc, char** argv) {
     // Declare Variables
    float mmYear = 1.5f, // Millimeters Per Year
          sLvl5,        // Sea level rise in 5 years in Millimeters
          sLvl7,        // Sea level rise in 7 years in Millimeters
          sLvl10;       // Sea level rise in 10 years in Millimeters
    int nYear1=5, nYear2=7, nYear3=10, // Number of years to calculate rise
        nYrBch; // Number of year before your home is beach front property
    float elevRiv=860.0f; //Elevation of Riverside in feet according to wikipedia
    
    // Calculations: 
    sLvl5 = mmYear * nYear1;
    sLvl7 = mmYear * nYear2;
    sLvl10 = mmYear * nYear3;
    nYrBch = elevRiv / mmYear * CNVMMFT;
    
    // Output : 
    cout << "Rate of sea level rise = " << mmYear << " mm" << endl;
    cout << "Sea levels will rise " << sLvl5 << "mm in 5 years" << endl;
    cout << "Sea levels will rise " << sLvl7 << "mm in 7 years" << endl;
    cout << "Sea levels will rise " << sLvl10 << "mm in 10 years" << endl;
    cout << "At this rate Riverside won't have beach front property for " << nYrBch << " years" << endl;
    cout << "This rise equates to " << nYrBch*mmYear/CNVMMM << " meters" << endl;
    
    return 0;
}

