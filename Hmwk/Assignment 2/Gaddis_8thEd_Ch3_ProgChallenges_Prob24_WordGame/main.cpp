/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on September 22, 2016, 12:14 PM
 * Purpose : Word game
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip> 
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int size = 260;
    char name[size], city[size], proff[size], animal[size], petname[size], college[size];
    unsigned char age;
    
    //Input values
    cout << "Input your name, city , profession, college you attended, your adopted animal, and its name:" << endl;
    cin.getline(name,size);
    cin.getline(city,size);
    cin.getline(proff,size);
    cin.getline(college,size);
    cin.getline(animal,size);
    cin.getline(petname,size);
    cout << "Input your age:" << endl;
    cin >> age;
    
    //Display Output
    cout << "There was a person named " << name << "who lived in " << city << ". At the age of " << static_cast <int> (age) 
         << ", " << name << "went to collage at " << college << ". " << name << " graduated and went to work as a"
         << proff << ". Then, " << name << "adopted a(n) " << animal << "named " << petname << ". They both lived happily ever after !"<< endl;
    
    //Exit Program
    return 0;
}

