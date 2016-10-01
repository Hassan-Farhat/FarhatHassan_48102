/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 1:59 PM
 * Purpose : Color mixing program
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string color1, color2; //Colors to mix
    
    //Input values
    cout << "Input the first primary color : (no capitalization please)" << endl;
    cin >> color1;
    cout << "Input the second primary color : (no capitalization please)" << endl;
    cin >> color2;
    
    //Process values -> Map inputs to Outputs
    if ( (color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red") ){
        cout << "Mixing red and blue will make purple." << endl;
    }
    else if ( (color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red") ){
        cout << "Mixing red and yellow will make orange." << endl;
    }
    else if ( (color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue") ){
        cout << "Mixing yellow and blue will make orange." << endl;
    }
    else 
        cout << "You did not enter a primary color or you capitalized." << endl;
    
    //Display Output

    //Exit Program
    return 0;
}
