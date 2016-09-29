/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 29, 2016, 12:01 PM
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
    if (waveLen > 1e-2) cout << "Radio wave" << endl;
    else if (waveLen > 1e-3f) cout << "Microwave" << endl;
    else if (waveLen > 7e-7f) cout << "Infrared" <<endl;
    else if (waveLen > 4e-7f) cout << "Visible Light" << endl;
    else if (waveLen > 1e-8f) cout << "Ultraviolet" << endl;
    else if (waveLen > 1e-11f) cout << "X-ray" << endl;
    else cout << "Gamma radiation" << endl;
    

    //Exit Program
    return 0;
}
