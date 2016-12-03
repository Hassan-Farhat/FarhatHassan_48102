/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on December 2, 2016, 4:19 PM
 * Purpose: Alpha test for the game.
 */

#include <iostream>   //Input/Output objects
#include <fstream>    //File I/O
#include <string>     //String Library
#include <cstdlib>    //Random number
#include <ctime>      //Used to set random number seed
#include <iomanip>    //Used for in the scoreboard
#include <cmath>      //Used in calculating final score

using namespace std;

//User Libraries

//Global Constants
const int MAPCOL=100;

//Function prototypes
void skTree (int [], string [], short);
void skillcal (int[], string [], int, short, int&);
void skillcal (int[], string [], short, int&);
void skill (int [], string [], int, int, short, short);
void crtmap(char[][MAPCOL]);
char spType(int);
void fillmap(char[][MAPCOL], char[][MAPCOL], int, int, int);
void prntmap(char[][MAPCOL],int,int);
void movemnt(char[][MAPCOL],string, int &, int &);
void shop (bool[],string[],int,int,int);

int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare Variables
    string skNames[]={"Agility" , "Attack", "Luck", "Health"}; //Name of the skills.
    int skills[]={5,5,2,25},             //The default point distribution.
        points = 10, min;                     //Number of spendable points.
    short n=4,                       //Checking/Calculation values.
          choice;                        //Choice (selection of skill).
    const int MAPROW=100;
    char map[MAPROW][MAPROW], pmap[MAPROW][MAPROW];
    string move;
    int spawn;
    int prow=6, pcol=4;
    pmap[prow][pcol] = 'P';
    int coins = 15;
    const int SIZE=100;
    bool it[]={true,true,true,true,true,true,true};
    string items[]={"Shield", "Holy Spell", "Armor", "Sword", "Human Effigy",
                     "Rabbit's Foot", "Bow"};
    int used = 7, select;
    
    
    //Player sets up their skills.
    skill(skills, skNames, points, min, n, choice);
    
    //Shop:
    shop(it,items,used,coins,select);
    
    //Create the map.
    do{
        crtmap(map);
        fillmap(pmap,map,spawn,prow,pcol);
        movemnt(pmap,move,prow,pcol);
    }while(move!="end");
    return 0;
}

void skill(int skills[], string skNames[], int points, int min, short n, short choice){
    cout << "This is the skill setup tree:" << endl 
    << "Here you will decide your attributes:" << endl << endl;
    do{ //Skill Set-Up loop starts here
        skTree(skills,skNames,n);
        cout << "What skill would you like to rank up?" << endl;
        cout << "Type in the number before the skill." << endl;
        do{
            cin >> choice;
        }while (choice > 4);
        switch (choice){
            case 1:
                min=skills[0];
                skillcal(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 2:
                min=skills[1];
                skillcal(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 3:
                min=skills[2];
                skillcal(skills,skNames,min,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 4:
                skillcal(skills,skNames,choice,points);
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
        }
    }while (points > 0);  //End of Skill Set-Up loop
}

void skTree (int skills[], string skNames[], short n){
    for (int i=0;i<n;i++){
        cout<<i+1<<". "<<setw(7)<<skNames[i]<<setw(3)<<skills[i]<<endl;
    }
}

void skillcal (int skills[],string skNames[],int min,short choice,int &points){
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
            skills[choice-1] = min;
            points = points - extra;
            cout<<"Your " << skNames[choice-1] << " was too low it has been "
                <<"reset to 5." << endl;
        }
    }   //End of Check
}

void skillcal (int skills[], string skNames[], short choice, int &points){
    int x;
    do{
        cout<<endl<<"How many points would you like to add in to "
            <<skNames[choice-1]<<endl<<"You have "<<points<<" to spend."<<endl;
        cin >> x; //Storage of points to add.
    }while (x > points);
    skills[choice-1] += x;   
    points -= x;    
}

void crtmap(char map[][MAPCOL]){
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            if(i==0 && (k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==1&&(k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==2&&(k==0 || k==4 || k==8)) map[i][k]='|';
            else if(i==3&&(k==0 || k==2 || k==6 || k==8)) map[i][k]='|';
            else if(i==4&&(k==0 || k==2 || k==4 || k==6 || k==8))map[i][k]='|';
            else if(i==5&&(k==0 || k==8)) map[i][k]='|';
            else if(i==6&&(k==0 || k==3 || k==5 || k==8)) map[i][k]='|';
            else if(i==0&&k==4)map[i][k]='B';
            else if(i==6&&k==4)map[i][k]='C';
            else map[i][k]='-';
        }
    }
}

char spType(int spawn){
   spawn = rand()%3;
   if (spawn == 0) return '-';
   else if (spawn == 1) return '*';
   else if (spawn == 2) return '#'; 
}

void fillmap(char pmap[][MAPCOL], char map[][MAPCOL], int spawn, int prow, int pcol){
    for (int i=0; i<7; i++){
            for (int k=0; k<9; k++){
                if(map[i][k]=='-' || map[i][k]=='*' || map[i][k]=='#')map[i][k] = spType(spawn);
            }
        }
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            if (i!=prow || k!=pcol) pmap[i][k]= map[i][k];
        }
    }
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            cout << pmap[i][k];
            if(k==8) cout<<endl;
        }
    }
}

void movemnt(char pmap[][MAPCOL], string move, int & prow, int & pcol){
    cout<<"Input the direction of your turn (up,left,right)"<<endl;
        cin>>move;
        //Determine player location on map
        if (move == "up" || move == "Up") prow -= 1;
        else if (move == "right" || move == "Right") pcol += 1;
        else if (move == "left" || move == "Left") pcol -= 1;
        pmap[prow][pcol] = 'P';
}

void prntmap(char pmap[][MAPCOL], int prow, int pcol){
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            cout << pmap[i][k];
            if(k==8) cout<<endl;
        }
    }
}

void shop(bool it[],string items[],int n,int coins,int select){
    do{
        for(int i=0; i<n; i++){
            if (it[i])cout<<i+1<<". "<<items[i]<<endl;
            else cout<<i+1<<". "<<"Purchased"<<endl; 
        }
        cout<<"You currently have "<<coins<<" coins."<<endl; 
        cout<<"Type in the number before the item to buy it."<<endl;
        cout<<"Each item costs 5 coins."<<endl;
        cout<<"You can leave by typing in 10"<<endl;
        cin>>select;
        cout<<endl;
        switch (select){
            case 1: 
                coins = (it[0])? coins-=5 : coins = coins; 
                it[0] = false;break;
            case 2:
                coins = (it[1])? coins-=5 : coins = coins;
                it[1] = false;break;
            case 3:
                coins = (it[2])? coins-=5 : coins = coins;
                it[2]= false;break;
            case 4:
                coins = (it[3])? coins-=5 : coins = coins;
                it[3] = false;break;
            case 5:
                coins = (it[4])? coins-=5 : coins = coins;
                it[4] = false;break;
            case 6:
                coins = (it[5])? coins-=5 : coins = coins;
                it[5] = false;break;
            case 7:
                coins = (it[6])? coins-=5 : coins = coins;
                it[6] = false;break;
            case 10:
                cout<<"Thank you come again."<<endl;break;
            default: cout<<"You didn't input a selection"<<endl<<endl;
        }
    }while(!(coins < 5) && !(select==10));
}