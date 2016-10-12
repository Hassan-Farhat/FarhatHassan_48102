/* 
 * File:   main.cpp
 * Author: Hassan
 * Created on October 9, 2016, 12:31 PM
 * Purpose : Display all ASCII characters
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
    char ch; //(ch) will be used to display the characters
    
    //Process values and display output
    for (int i=0;i<=127;i++){
        ch = i;
        if (i%16 == 0){
            cout << endl << ch << " ";
        }
        else {
            cout << ch << " ";
        }
    }
    //Exit Program
    cout << endl;
    return 0;
}
