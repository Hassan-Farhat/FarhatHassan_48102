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
    cout << "Please input the number of students in the class (1 to 25):" << endl;
    cin >> nStudnt;
    while ((1>nStudnt) && (nStudnt>25)){
        cout << "You entered a values that was either less than one or greater than 25." << endl;
        cout << "Please re-enter the number of students in your class :" << endl;
        cin >> nStudnt;
    }
    
    //Process variables (loops) and Display output
    if (nStudnt == 1){
        cout << "You one have one student and please input their name" << endl;
        cin >> name;
        cout << "Your only student is : "<< name << endl;
    }
    for (int i=1; i<=nStudnt; i++){
        cout << "Please enter the first name of your students (lower case only) (one at a time)" << endl;
        cin >> name;
        if (i==1){
            fName = name;
        }
        else if (i==2){
            if (name < fName){
                lName = fName;
                fName = name;
            }
            else {
                lName = name;
            }
        }
        else {
            if ((name < fName)){
                fName = name;
            }
            else if (name > lName){
                lName = name;
            }
        }
    }
    cout << "The First student will be : " << fName << endl;
    cout << "The Last student will be : " << lName << endl;
    
    //Exit Program
    return 0;
}

