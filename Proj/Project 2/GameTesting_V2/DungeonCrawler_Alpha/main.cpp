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
char clsslct ();
void prntskl(string [], int []);
void mods(int [],bool [], float &, int &, int &, int &);
void skTree (int [], string [], short);
void skillcal (int[], string [], int, short, int&);
void skillcal (int[], string [], short, int&);
void skill (int [], string [], int, int, short, short);
void crtmap(char[][MAPCOL]);
void invtry(bool [], string [], short, char, int &, int &);
char spType(int);
void fillmap(char[][MAPCOL], char[][MAPCOL], int, int, int);
void prntmap(char[][MAPCOL],int,int);
void movemnt(char[][MAPCOL],string, int &, int &, char &);
void shop (bool[],string[],int,int,int);
void roll(int[], int, int[], int, int[], int, int[], int);
void sort(int[], int);
void pntroll(int[], int[], int[], int[], int = 2, int = 3);
void whowins(int, int, int &, int &, char, char, float, float);
int  fight(int[], int[], int &, int = 3);
int  sfight(int[],int[],int &, int = 2);
int  dmg(int, char, char, float);
int  mdmg(int, char, char, float);
string choice();

int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare Variables
    string skNames[]={"Agility" , "Attack", "Luck", "Health"}; //Name of the skills.
    int points = 10, min;                //Number of spendable points.
    short mn=4,                           //Checking/Calculation values.
          choice;                        //Choice (selection of skill).
    const int MAPROW=100;
    char map[MAPROW][MAPROW], pmap[MAPROW][MAPROW];
    string move, start;
    int spawn;
    int prow=6, pcol=4;
    pmap[prow][pcol] = 'P';
    int coins = 15, counter;
    const int SIZE=100;
    bool it[]={true,true,true,true,true,true,true};
    string items[]={"Shield", "Holy Spell", "Armor", "Sword", "Human Effigy",
                     "Rabbit's Foot", "Bow"}, attack, confirm, input;
    int used = 7, select;
    int spDice[SIZE], pDice[SIZE], scDice[SIZE], cDice[SIZE];
    int sn=3,n=3,sm=2,m=3,mhealth = 15, pLuck, health;
    int cWins,pWins,scWins,spWins, Aglty;
    char pClass, cClass;
    float pAttck, mAttck=1.5;
    
    //The Intro-screen:
    cout << "    ==================================================================" << endl;
    cout << "                  Welcome this is Dungeon Crawler" << endl;
    cout << "              Created by Hassan Farhat for CSC-5 48102" << endl;
    cout << "                  When you are ready type in start" << endl;
    cout << "    ==================================================================" << endl;
    do{
        cin >> start;
    }while (!(start == "start"));
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    
    //Player selects their class
    pClass = clsslct();
    
    //Player sets up their skills.
    do{
        int skills[]={5,5,2,25};
        skill(skills, skNames, points, min, mn, choice);
        mods (skills, it, pAttck, Aglty, pLuck, health);
        prntskl(skNames,skills);
        cout<<"If you are happy with this skill set up then type in yes else type in no."<<endl;
        do{
            cin >> confirm;
        } while(confirm != "Yes" && confirm != "yes" && confirm != "No" && confirm != "no"); 
    }while (confirm == "No" || confirm == "no");
    
    
    //Shop:
    shop(it,items,used,coins,select);
    
    do{
        mhealth = 15;
        counter = 0;
        
        //Create the map:
        crtmap(map);
        fillmap(pmap,map,spawn,prow,pcol);
        movemnt(pmap,move,prow,pcol,cClass);
        
        //Battle
        if (cClass=='='||cClass=='*'||cClass=='#'){
            do{
                do {
                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                    cin >> input;  //Player inputs their move
                    cout << endl;
                }while (input!="dodge" && input!="attack" && input!="inventory");
                if (input=="attack"){
                    cout<<endl;
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
                    sort(spDice,sn);
                    sort(pDice,n);
                    sort(scDice,sm);
                    sort(cDice,m);
                    pWins = fight(pDice,cDice,cWins);
                    spWins = sfight(spDice,scDice,scWins);
                    pntroll(spDice,pDice,scDice,cDice);
                    whowins(pWins,cWins,health,mhealth,pClass,cClass,pAttck,mAttck);
                    cout<<mhealth<<" "<<health<<endl;
                    cout<<endl;
                }else if (input=="inventory"){
                    
                }else{
                    invtry(it,items,n,cClass,health,mhealth);   
                } 
            }while(health>0 && mhealth>0);
        }
        if (cClass=='B'){
            cout << "YOU ARE IN A BOSS BATTLE" <<endl;
        }
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
   spawn = rand()%4;
   if (spawn == 0) return '-';
   else if (spawn == 1) return '*';
   else if (spawn == 2) return '#'; 
   else if (spawn == 3) return '=';
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

void movemnt(char pmap[][MAPCOL], string move, int &prow, int &pcol, char &mon){
    do{
    cout<<"Input the direction of your turn (up,left,right)"<<endl;
    cin>>move;
    }while(move!="up" && move!="left" && move!="right");
    //Determine player location on map
    if (move == "up" || move == "Up") prow -= 1;
    else if (move == "right" || move == "Right") pcol += 1;
    else if (move == "left" || move == "Left") pcol -= 1;
    mon = pmap[prow][pcol];
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

int  fight(int pD[],int cD[],int &cWins,int m){
    int pWins=0;
    cWins=0;
    for (int i=0; i<m; i++){
        if (pD[i]>cD[i]) pWins+=1;
        else if (pD[i]<cD[i]) cWins+=1;
        else{
            pWins+=1;
            cWins+=1;
        }
    }
    return pWins;
}

int  sfight(int spD[],int scD[],int &scWins, int m){
    int spWins=0;
    scWins=0;
    for (int i=0; i<m; i++){
        if (spD[i]>scD[i]) spWins+=1;
        else if (spD[i]<scD[i]) scWins+=1;
        else{
            spWins+=1;
            scWins+=1;
        }
    }
    return spWins;
}

void roll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    for (int i=0; i<sn; i++)spD[i]=rand()%12+1;
    for (int i=0; i<n; i++)pD[i]=rand()%12+1;
    for (int i=0; i<sm; i++)scD[i]=rand()%12+1;
    for (int i=0; i<m; i++)cD[i]=rand()%12+1;
}

void sort(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void pntroll(int spD[], int pD[],int scD[],int cD[],int n, int m){
    cout <<"NORMAL DICE   SPECIAL DICE" << endl;
    for (int i=0; i<m; i++)cout<<setw(3)<<pD[i];
    cout << "        ";
    for (int i=0; i<n; i++)cout<<setw(3)<<spD[i];
    cout << endl;
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout << "        ";
    for (int i=0; i<n; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}

int  dmg(int wins, char pClass, char cClass, float pAttck){
    int damage = wins * pAttck;  
    if (pClass=='D' && cClass=='*') return damage/2;
    else if (pClass=='D' && cClass=='=') return damage+3;
    else if (pClass=='H' && cClass=='#') return damage+3;
    else if (pClass=='H' && cClass=='=') return damage/2;
    else if (pClass=='G' && cClass=='#') return damage/2;
    else if (pClass=='G' && cClass=='*') return damage+3;
    else return damage;
}

int  mdmg(int wins, char pClass, char cClass, float mAttck){
    int damage = (wins * mAttck + 0.5);  
    if (cClass=='#' && pClass=='H') return damage/2;
    else if (cClass=='#' && pClass=='G') return damage+3;
    else if (cClass=='*' && pClass=='D') return damage+3;
    else if (cClass=='*' && pClass=='G') return damage/2;
    else if (cClass=='=' && pClass=='D') return damage/2;
    else if (cClass=='=' && pClass=='H') return damage+3;
    else return damage;
}

void whowins(int pWins,int cWins,int &health, int &mhealth,char pClass,char cClass,float pAttck,float mAttck){
    if (pWins>cWins){
        cout<<"You attack"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
    }else if (pWins<cWins){
        cout<<"The monster successfully attacks"<<endl;
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }else{
        cout<<"You both hit each other"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }
}

char clsslct(){
    string clss;
    cout <<"What class would you like to use?"<<endl;
    cout <<"1. Paladin      (Holy type class)"<<endl
         <<"2. Necromancer  (Ghost type class)"<<endl
         <<"3. Demon Hunter (Dark type class)"<<endl;
    do{
        cout << "Please type in the full name of the class" << endl;
        cin.ignore();
        getline(cin,clss);
    } while(clss!="Paladin" && clss!="Necromancer" && clss!="Demon Hunter");
    
    if (clss == "Paladin") return 'H';
    else if (clss == "Necromancer") return 'G';
    else if (clss == "Demon Hunter") return 'D';
}

void mods (int skills[],bool it[],float &pAttck,int &pAglty,int &pLuck,int &health){
    //Modifiers:
    pAttck = skills[1] / 2;
    pAglty = 100 - (skills[0] * 9);   
    pLuck = 100 - (skills[2] * 4);
    if(it[2] == false) pLuck = 100 - ((skills[2]+2) * 4);
    if(it[3] == false) health = skills[3] + 5;
    if(it[5] == false) pAttck = (skills[1]+1)/ 2;
}

void prntskl(string skNames[],int skills[]){
    cout << "Current skill set up:" <<endl;
    for (int i=0;i<4;i++){
        cout<<skNames[i]<<setw(3)<<skills[i]<<endl;
    }
}

void invtry(bool it[], string items[], short n, char cClass, int &health, int &mHealth){
    string use;
    cout << "Input the name exactly of the item you would like to use" << endl;
    cout << "If you don't want to use any item type in leave" << endl;
    if (it[0] == false)cout << items[0] << endl;    //Shield
    if (it[1] == false)cout << items[1] << endl;    //Holy Spell
    if (it[6] == false)cout << items[6] << endl;    //Bow
    do{ 
        getline(cin,use);   //Player inputs what item they wish to use
    }while (use!=items[0] && use!=items[1] && use!=items[8] && use!="leave");
    if(it[0]==false && use==items[0]){
        it[0]=false;
        cout<<"You gain 10 points of health"<<endl;
        health += 10;
    }
    else if(it[1]==false && use==items[1]){
        if(cClass=='B'){
            short chance = rand()%9 + 1;
            it[1] = true;
            if (chance%2){
                cout << "Holy spell worked! YOU DEAL 10 dmg" <<endl;
                mHealth -= 10;
            }
            else { 
                cout << "The spell failed" << endl;
            }
        }
        else {
            cout<<"This item can only be used in the boss battle."<<endl;
        }
    }
    else if(it[6]==false && use==items[6]){
        it[6]=true;
        if (cClass=='B'){
            cout << "You shoot at the boss and deal 8 damage" << endl;
            mHealth-=8;
        }
        else {
            cout << "You kill the monster with a brilliant shot" << endl;
            mHealth = 0;
        }
    }
}