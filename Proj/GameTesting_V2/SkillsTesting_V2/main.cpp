/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hassan
 *
 * Created on November 25, 2016, 1:41 PM
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void skTree (int [], string [], short);
void skill (int[], string [], short, short, int&);
void skill (int[], string [], short, int&);


int main(int argc, char** argv) {
    cout << "This is the skill setup tree:" << endl 
    << "Here you will decide your attributes:" << endl << endl;
    string skNames[]={"Agility" , "Attack", "Luck", "Health"};
    int skills[]={5,5,2,25},
        points = 10;                     //Number of spendable points.
    short min,n=4,                         //Checking/Calculation values.
          choice;                        //Choice (selection of skill)           
    do{ //Skill Set-Up loop starts here
        skTree(skills,skNames,n);
        cout << "What skill would you like to rank up?" << endl;
        cout << "Type in the number before the skill." << endl;
        do{
            cin >> choice;
        }while (choice > 4);
        switch (choice){
            case 1:
                min=5;
                skill(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 2:
                min=5;
                skill(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 3:
                min=2;
                skill(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 4:
                skill(skills,skNames,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
        }
    }while (points > 0);  //End of Skill Set-Up loop
    return 0;
}

void skTree (int skills[], string skNames[], short n){
    for (int i=0;i<n;i++){
        cout<<i+1<<". "<<setw(7)<<skNames[i]<<setw(3)<<skills[i]<<endl;
    }
}

void skill (int skills[],string skNames[],short min,short choice,int &points){
    int x, remove, extra;
    do{
        cout<<endl<<"How many points would you like to add in to "
            <<skNames[choice-1]<<endl<<"You have "<<points<< " to spend."<<endl;
        cin >> x; //Storage of points to add.
    }while (x > points);
    skills[choice-1] += x;   
    points -= x;    
    while (skills[choice-1] > 10 || skills[choice-1] < min){ //Start check.
        cout<<"You have "<<skills[choice-1]<<" points in "<<skNames[choice-1];
        cout<<endl<<"you cannot have more than 10 point or less than"<<min
            <<" points."<<endl;
        if (skills[choice-1] > 10){ 
            cout << "Please input how many you would like to remove?" << endl;
            cin >> remove;
            skills[choice-1] = skills[choice-1] - remove;
            points = points + remove;
        }
        else if (skills[choice-1] < min){ //Calculations that correct to few attack points.
            extra = 5 - skills[choice-1];  
            skills[choice-1] = 5;
            points = points - extra;
            cout << "Your attack was too low it has been reset to 5." << endl;
        }
    }   //End of Check
}

void skill (int skills[], string skNames[], short choice, int &points){
    int x;
    do{
        cout<<endl<<"How many points would you like to add in to "
            <<skNames[choice-1]<<endl<<"You have "<<points<<" to spend."<<endl;
        cin >> x; //Storage of points to add.
    }while (x > points);
    skills[choice-1] += x;   
    points -= x;    
}