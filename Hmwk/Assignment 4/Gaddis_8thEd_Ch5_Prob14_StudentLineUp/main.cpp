/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 10, 2016, 9:22 AM
 * Purpose : The program should tell the user which student will be at the start of the line and which student will be at the end.
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <string>     //Student names
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string name, //Student names
           fName, //Name of First student
           lName; //Name of Last student
    unsigned short nStudnt;
    
    //Input values
    do{
        cout << "Please input the number of students in the class (1 to 25):" << endl;
        cin >> nStudnt;
    }while ((1>nStudnt) || (nStudnt>25));
    
    //Process variables (loops) and Display output
    cout << "Please enter the first names of your students (one at a time)" << endl;
    cin >> name;
    fName = name;
    lName = name;
    
    for (int i=2; i<=nStudnt; i++){
        cout << "Please enter the first names of your students (one at a time)" << endl;
        cin >> name;
        if ((name < fName)){
            fName = name;
        }
        else if (name > lName){
            lName = name;
        }
    }
    cout << "The First student will be : " << fName << endl;
    cout << "The Last student will be : " << lName << endl;
    
    //Exit Program
    return 0;
}

