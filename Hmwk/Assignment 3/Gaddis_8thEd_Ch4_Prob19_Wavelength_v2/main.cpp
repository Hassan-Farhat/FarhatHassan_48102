/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 29, 2016, 12:16 PM
 * Purpose : Determine the type of electromagnetic wave based on wave length.
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float waveLen;
    
    //Input values
    cout << "Input wave length of radiation in Meters and the program will tell you the type of wave:" << endl;
    cin >> waveLen;
    //Process values -> Map inputs to Outputs
    cout << ((waveLen > 1e-2f)?"Radio wave":
             (waveLen > 1e-3f)?"Microwave":
             (waveLen > 7e-7f)?"Infrared":
             (waveLen > 4e-7f)?"Visible Light":
             (waveLen > 1e-8f)?"Ultraviolet":
             (waveLen > 1e-11f)?"X-ray":"Gamma Radiation")<<endl;
    //Exit Program
    return 0;
}
