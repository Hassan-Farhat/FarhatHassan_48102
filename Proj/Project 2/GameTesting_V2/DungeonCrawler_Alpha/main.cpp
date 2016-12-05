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
#include <vector>     //Vector

using namespace std;

//User Libraries

//Global Constants
const int MAPCOL=100;

//Function prototypes
void intro (string);
char clsslct ();
bool dodge (int [],int,int);
bool swin  (int[], int[], int &);
void prntskl(string [], int []);
void mods(int [],bool [], float &, int &, int &, int &, int &);
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
void pntroll(int[], int[], int = 3);
void pntsrol(int[], int[], int = 2);
void whowins(int, int, int &, int &, char, char, float, float);
int  fight(int[], int[], int &, int = 3);
short  dmg(int, char, char, float);
short  mdmg(int, char, char, float);
string who(char);
void spAtck(int &);
string choice();
void bubble(int [], int);
void loot (vector<short> &, vector<short> &, int, int &, int &);
void Select(vector<short> &, int n);
bool linTest (vector<short> &, int);
bool binTest (vector<short> &, int);

int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare Variables
    const int SIZE=100;
    vector<short> coin(SIZE),point(SIZE);
    int skills[]={6,7,2,100};
    string skNames[]={"Agility" , "Attack", "Luck", "Health"}; //Name of the skills.
    int points = 10, min;                //Number of spendable points.
    short mn=4,                           //Checking/Calculation values.
          choice;                        //Choice (selection of skill).
    const int MAPROW=100;
    char map[MAPROW][MAPROW], pmap[MAPROW][MAPROW];
    string move, start, type;
    int spawn, effigy;
    int prow=6, pcol=4;
    pmap[prow][pcol] = 'P';
    int coins = 15, counter=0, score=0;
    bool it[]={true,true,true,true,true,true,true};
    string items[]={"Shield", "Holy Spell", "Armor", "Sword", "Human Effigy",
                     "Rabbit's Foot", "Bow"}, attack, confirm, input;
    int used = 7, select;
    int spDice[SIZE], pDice[SIZE], scDice[SIZE], cDice[SIZE];
    int sn=3,n=3,sm=2,m=3,mhealth = 15, pLuck, health;
    int cWins,pWins,spWins,scWins, pAglty, ddge;
    bool spWin;
    char pClass, cClass;
    float pAttck, mAttck=1.5;
    bool dChance = false;
    
    //The Intro-screen:
    intro (start);
    
    //Player selects their class
    pClass = clsslct();
    
    //Player sets up their skills.
    do{
        skill(skills, skNames, points, min, mn, choice);
        mods (skills, it, pAttck, pAglty, pLuck, health, effigy);
        skTree(skills,skNames,mn);
        cout<<"If you are happy with this skill set up then type in yes else type in no."<<endl;
        do{
            cin >> confirm;
        } while(confirm != "Yes" && confirm != "yes" && confirm != "No" && confirm != "no"); 
    }while (confirm == "No" || confirm == "no");
    
    
    //Shop:
    cout << endl;
    shop(it,items,used,coins,select);
    
    do{
        counter = 0;
        mhealth = 15;

        //Create the map:
        crtmap(map);
        fillmap(pmap,map,spawn,prow,pcol);
        movemnt(pmap,move,prow,pcol,cClass);
        
        //Battle
        if (cClass=='='||cClass=='*'||cClass=='#'||cClass=='B'){
            type = who(cClass);
            cout << "You are fighting a "<<type<<" type monster."<<endl;
            do{
                do {
                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                    cin >> input;  //Player inputs their move
                    cout << endl;
                }while (input!="dodge" && input!="attack" && input!="inventory");
                if (input=="attack"){
                    if (cClass=='B'){
                        mhealth = 50;
                        mAttck = 2;
                    }
                    cout<<endl;
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
                    sort(pDice,n);
                    sort(cDice,m);
                    pWins = fight(pDice,cDice,cWins);
                    pntroll(pDice,cDice);
                    cout<<"You won: " << pWins << " rolls" << endl;
                    cout<<"The monster won: "<<cWins<< " rolls"<<endl;
                    whowins(pWins,cWins,health,mhealth,pClass,cClass,pAttck,mAttck);
                    if ((counter % 3)==0 ){
                       sort(spDice,sn);
                       bubble(scDice,sm);
                       spWin=swin(spDice,scDice,spWins);
                       pntsrol(spDice,scDice);
                       cout<<"You won: "<<spWins<<" rolls"<<endl;
                       if (spWin == true){
                           spAtck (mhealth);
                       }else cout<<"You failed your cast."<<endl;
                    }
                    cout<<endl<<mhealth<<" "<<health<<endl;
                    cout<<endl;
                    counter+=1;
                }else if (input=="inventory"){
                    invtry(it,items,n,cClass,health,mhealth);
                }else{
                    dChance = dodge (skills,ddge,pAglty);
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
                    sort(pDice,n);
                    sort(cDice,m);
                    pWins = fight(pDice,cDice,cWins);
                    ddge=rand()%99+1;
                    if(dChance == true && ddge>=50){ 
                        pWins += 3;
                        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
                        cout<<"You dodge safely and land a powerful hit"<<endl;
                    }else if (dChance == true && ddge<=50){
                        cout << "You dodge safely!!"<<endl;
                    }else{
                        health = health - mdmg(cWins, pClass, cClass, mAttck);
                        cout << "Your dodge attempt failed and you where hit." << endl;
                    }
                    cout<<mhealth<<" "<<health<<endl;
                    if(it[4]==true && health <= 0){
                        health = effigy;
                    }
                }
            }while(health>0 && mhealth>0);
            if (mhealth == 0){
                loot (coin, point, pLuck, score, coins);
            }
        }
    }while(move!="end");
    return 0;
}

void bubble(int a[], int n){
    bool swap;
    int temp;
    do{
        swap = false;
        for(int i=0; i<(n-1); i++){
            if (a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

void loot (vector<short> &a,vector<short> &b,int pLuck,int &score,int &coins){
    int x = rand()%99 + 1, n, t;
    bool found1, found2;
    if (x >= pLuck) n=15;
    else n=10;
    for (int i=0;i<n;i++){
        
    }
}

void intro (string start){
    cout << "    ==================================================================" << endl;
    cout << "                Welcome to Dungeon Crawler Version 2" << endl;
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
        cout<<i+1<<". "<<setw(7)<<skNames[i]<<setw(4)<<skills[i]<<endl;
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
   spawn = rand()%5;
   if (spawn == 0 || spawn == 4) return '-';
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
        do{
            cout<<"Input the direction of your turn (up,left,right)"<<endl;
            cin>>move;
        }while(move!="up" && move!="left" && move!="right");
        //Determine player location on map
        if (move == "up" || move == "Up") prow -= 1;
        else if (move == "right" || move == "Right") pcol += 1;
        else if (move == "left" || move == "Left") pcol -= 1;
        mon = pmap[prow][pcol];
    }while(pmap[prow][pcol]=='|');
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

string who(char cClass){
    if (cClass == '*') return "Holy";
    else if (cClass == '=') return "Ghost";
    else if (cClass == '#') return "Dark";
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

void pntroll(int pD[],int cD[], int m){
    cout << "            NORMAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<pD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout<<endl;
}

void pntsrol(int spD[],int scD[], int m){
    cout <<"            SPECIAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<spD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}

short  dmg(int wins, char pClass, char cClass, float pAttck){
    int damage = wins * pAttck;  
    if (pClass=='D' && cClass=='*') return damage/2;
    else if (pClass=='D' && cClass=='=') return damage+3;
    else if (pClass=='H' && cClass=='#') return damage+3;
    else if (pClass=='H' && cClass=='=') return damage/2;
    else if (pClass=='G' && cClass=='#') return damage/2;
    else if (pClass=='G' && cClass=='*') return damage+3;
    else return damage;
}

short  mdmg(int wins, char pClass, char cClass, float mAttck){
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
         <<"3. Demon-Hunter (Dark type class)"<<endl;
    do{
        cout << "Please type in the full name of the class" << endl;
        cin >> clss;
    } while(clss!="Paladin" && clss!="Necromancer" && clss!="Demon-Hunter");
    
    if (clss == "Paladin") return 'H';
    else if (clss == "Necromancer") return 'G';
    else if (clss == "Demon Hunter") return 'D';
}

void mods (int skills[],bool it[],float &pAttck,int &pAglty,int &pLuck,int &health, int &effigy){
    //Modifiers:
    health = skills[3];
    effigy = health;
    pAttck = skills[1] / 2;
    pAglty = 100 - (skills[0] * 9);   
    pLuck = 100 - (skills[2] * 4);
    if(it[2] == false) pLuck = 100 - ((skills[2]+2) * 4);
    if(it[3] == false) health = skills[3] + 5;
    if(it[5] == false) pAttck = (skills[1]+1)/ 2;
}

void invtry(bool it[], string items[], short n, char cClass, int &health, int &mHealth){
    string use;
    cout << "Input the name exactly of the item you would like to use" << endl;
    cout << "If you don't want to use any item type in leave" << endl;
    if (it[0] == false)cout <<"- "<< items[0] << endl;    //Shield
    if (it[1] == false)cout <<"- "<<items[1] << endl;    //Holy Spell
    if (it[6] == false)cout <<"- "<<items[6] << endl;    //Bow
    if (it[0]==true&&it[1]==true&&it[6]==true) cout<<"You have no items."<<endl;
    do{ 
        getline(cin,use);   //Player inputs what item they wish to use
    }while (use!=items[0] && use!=items[1] && use!=items[6] && use!="leave");
    if(it[0]==false && use==items[0]){
        it[0]=false;
        cout<<"You gain 10 points of health"<<endl;
        health += 10;
    }else if(it[1]==false && use==items[1]){
        if(cClass=='B'){
            short chance = rand()%9 + 1;
            it[1] = true;
            if (chance%2){
                cout << "Holy spell worked! YOU DEAL 10 dmg" <<endl;
                mHealth -= 10;
            }else { 
                cout << "The spell failed" << endl;
            }
        }else {
            cout<<"This item can only be used in the boss battle."<<endl;
        }
    }else if(it[6]==false && use==items[6]){
        if (cClass=='B'){
            it[6]=true;
            cout << "You shoot at the boss and deal 8 damage" << endl;
            mHealth-=8;
        }else {
            it[6]=true;
            cout << "You kill the monster with a brilliant shot" << endl;
            mHealth = 0;
        }
    }
}

bool dodge (int skills[], int ddge,int pAglty){
    ddge = rand()%99+1+(skills[2]/2);
    if (ddge >= pAglty){
        cout << "You successfully dodged." << endl;
        return true;
    }else {
        cout << "The dodge failed." << endl;
        return false;
    }
}

bool swin (int spDice [],int scDice [],int &spWins){
    spWins=0;
    for (int i=0; i<2; i++){
        if (spDice[i]>scDice[i]) spWins+=1; 
        else if (spDice[i]==scDice[i]) spWins+=1;
    }
    if (spWins>=2) return true;
    else return false;
}

void spAtck (int &mhealth){
    int x;
    cout<<"You unleash a powerful spell and remove half you enemies health"<<endl;
    x = mhealth/2;
    mhealth -= x;
}