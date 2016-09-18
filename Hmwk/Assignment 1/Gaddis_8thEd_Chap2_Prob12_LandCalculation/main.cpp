/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 10, 2016, 6:21 PM
 * Purpose : Convert square feet to acres.
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned short CFACTOR = 43560; // Conversion factor from square feet to acres 

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float feet = 391876; // Size of land in square feet
    float acre; // Size of land in acres
   
    //Calculating how many acres
    acre = feet / CFACTOR;
    //Display Output
    cout << "Size of land in square feet = " << feet << " ft^2" << endl;
    cout << "Number of acres = " << acre << " ac" << endl;
    //Exit Program
    return 0;
}
