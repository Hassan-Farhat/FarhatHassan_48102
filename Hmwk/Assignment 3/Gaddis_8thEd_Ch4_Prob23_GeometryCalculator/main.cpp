/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 1, 2016, 7:34 PM
 * Purpose : Build a menu that allows the users to select and calculate the areas of a circle, rectangle, and triangle
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float PI = 3.14259;

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Menu
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Quit" << endl <<endl;
    cout << "Enter your choice (1-4)" << endl;
    
    //Declaration of Variables
    char choice; // user input
    unsigned short radius, length, width, base, height;
    float area;
    
    //Input values
    cin>>choice;
    
    //Process values + Output
    switch (choice){
        case '1' :
            cout << "Input an integer value for the radius" << endl;
            cin >> radius;
            area = PI * radius * radius;
            cout << "The area of the circle is " << area << " Units^2" <<endl;
            break;
        case '2' :
            cout << "Input an integer value for the length and width" << endl;
            cin >> length >> width;
            area = length * width;
            cout << "The area of the rectangle is " << area << " Units^2" <<endl;
            break;
        case '3' :
            cout << "Input an integer value for the base and height" << endl;
            cin >> base >> height;
            area = base * height * 0.5;
            cout << "The area of the triangle is " << area << " Units^2" <<endl;
            break;
        case '4' :
            return 0;
            break;
        default : 
            cout << "Please input 1 through 4 only";
            
    }

    //Exit Program
    return 0;
}