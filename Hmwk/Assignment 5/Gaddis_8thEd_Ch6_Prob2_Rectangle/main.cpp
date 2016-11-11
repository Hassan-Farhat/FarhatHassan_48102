/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on November 6, 2016, 9:43 AM
 * Purpose : Find the area of a rectangle
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void getDmsn(float &, float &);
float Area(float, float);
void Display(float, float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float length, width, area;  //The length, width, and area of the rectangle
    
    //Input values
    getDmsn(length, width);
    
    //Process values -> Map inputs to Outputs
    area = Area(length, width);
    
    //Display Output
    Display(length, width, area);

    //Exit Program
    return 0;
}

//Function for the user to input the data:
void getDmsn(float &length, float &width){
    do{
        cout << "Input the length of the square." << endl;
        cin >> length;
    }while (length <= 0);
    do{
        cout << "Input the width of the square." << endl;
        cin >> width;
    }while (width <= 0);
}

//Calculate the area of the square:
float Area(float length, float width){
    return length * width;
}

//Display the output
void Display(float length, float width, float area){
    cout << setprecision(2) << fixed << showpoint;
    cout << endl;
    cout << "The dimensions of the rectangle:" << endl;
    cout << "Length = " << length << " units" << endl;
    cout << "Width = " << width << " units" << endl;
    cout << endl;
    cout << "The area = " << area << " unit^2" << endl; 
}

