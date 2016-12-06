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
void prntskl(string [], int []);
void mods(int [],bool [], float &, int &, int &, int &, int &);
void skTree (int [], string [], short);
void skillcal (int[], string [], int, short, int&);
void skillcal (int[], string [], short, int&);
void skill (int [], string [], int, int, short, short);
void crtmap(char[][MAPCOL]);
void invtry(bool [], string [], short, char, int &, int &);
void fillmap(char[][MAPCOL], char[][MAPCOL], int, int, int);
void prntmap(char[][MAPCOL],int,int);
void movemnt(char[][MAPCOL],string, int &, int &, char &);
void shop (bool[],string[],int,int,int &, int &);
void roll(int[], int, int[], int, int[], int, int[], int);
void marksort(int[], int);
void pntroll(int[], int[], int = 3);
void pntsrol(int[], int[], int = 2);
void spAtck(int &);
void bubble(int [], int);
void bubble(vector<short> &, int);
void loot (vector<short> &, vector<short> &, int, int &, int &);
void select(vector<short> &, int);
void highscr (int);
void whowins(int, int, int &, int &, char, char, float, float);
char clsslct ();
char spType(int);
bool dodge (int [],int,int);
bool swin  (int[], int[], int &);
bool linear (vector<short> &, int, int);
bool binary (vector<short> &, int, int);
int  fight(int[], int[], int &, int = 3);
short  dmg(int, char, char, float);
short  mdmg(int, char, char, float);
string who(char);
string choice();

int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declare Variables:
    //Array Size variable:
    const int SIZE=100;
    const int MAPROW=100;
    //Intro screen:
    string start;                 //Used to start the game.
    //Character creation variables:
    int skills[]={6,7,2,100};               //Default skill values.
    string skNames[]={"Agility" , "Attack", //Name of the skills.
                      "Luck", "Health"}; 
    int points = 10, min,                //Number of spendable points.
        pAglty,                          //Player agility.
        pLuck;                           //Player Luck.
    short mn=4,                          //Checking/Calculation values.
          choice;                        //Choice (selection of skill).
    char pClass, cClass;                 //Player class.
    //Loot variables:
    vector<short> coin(SIZE),point(SIZE); //Vectors for coin chance and score chance.
    int score=0;                          //The score of the player.
    //Shop Variables:
    bool it[]={true,true,true,true,true,true,true}; //Item purchase list.
    string items[]={"Shield", "Holy Spell",         //Name of the items.
                    "Armor", "Sword", "Human Effigy",
                    "Rabbit's Foot", "Bow"}, 
                    confirm;                        //Skill confirmation.
    int used = 7,         //Utilized space of array.
        select,           //Selection of item to purchase.
        coins = 15,       //Number of coins the player has.
        effigy;           //Effigy health storage
    //Map and movement:
    char map[MAPROW][MAPROW],  //The dynamic updating map     
         pmap[MAPROW][MAPROW]; //The player changeable map 
    string move, type;         //The player movement and Monster type.
    int spawn;                 //The monster spawn.
    int prow=6, pcol=4;        //The initial player starting point.
    pmap[prow][pcol] = 'P';    //The initial player placement.
    //Battle Variables:
    int counter=0,                    //The special dice cool down.
        spDice[SIZE], pDice[SIZE],    //The player's normal and special dice.
        scDice[SIZE], cDice[SIZE],    //The computer's normal and special dice.
        sn=3,n=3,                     //The player's amount of dice.
        sm=2,m=3,                     //The computer's amount of dice.
        mhealth,health,               //Monster health and player health.
        ddge,                         //Player dodge chance.
        cWins,pWins,                  //Computer and player normal wins.
        spWins,scWins;                //Computer and player special wins.
    bool spWin;                         //Special win check.
    float pAttck, mAttck=1.5;           //The player and monster attack value.
    bool dChance = false, boss=false;   //The dodge check, boss check.
    string input;                 //The player action.
    //High Score Variables:
    string name, buffer;          //The player's name and the file buffer.  
    
    
    //The Intro-screen:
    intro (start);
    
    //Player selects their class
    pClass = clsslct();
    
    //Player sets up their skills.
    do{
        //Send player to skill function
        skill(skills, skNames, points, min, mn, choice);
        //Present player with their skill set up.
        skTree(skills,skNames,mn);
        cout<<"If you are happy with this skill set up then type in yes else type in no."<<endl;
        do{
            //Player confirms skill set up;
            cin >> confirm;
        } while(confirm != "Yes" && confirm != "yes" && confirm != "No" && confirm != "no"); 
    }while (confirm == "No" || confirm == "no");
    
    //Shop:
    cout<<endl<<"This is the camp store see anything you like?"<<endl;
    shop(it,items,used,select,coins,health);
    
    //Modifiers
    mods (skills, it, pAttck, pAglty, pLuck, health, effigy);
    
    do{ //Start of the game loop
        counter = 0;        //Special skill counter starts here
        mhealth = 15;       //Set the monster's health

        //Create the map:
        crtmap(map);
        //Fill the map with characters.
        fillmap(pmap,map,spawn,prow,pcol);
        //Player movement.
        movemnt(pmap,move,prow,pcol,cClass);
        
        //Battle starts here
        if (cClass=='='||cClass=='*'||cClass=='#'||cClass=='B'){ //Check the character of the map
            //Determine the type of monster that spawns
            type = who(cClass);
            if (cClass=='B'){ //If 'B' then initiate the boss parameters 
                //Set the boss check to true, set the boss health, and the boss attack value.
                boss=true; 
                mhealth = 50;
                mAttck = 2;
                cout<<"You are about to enter the boss room. There is a merchant waiting outside." << endl;
                cout<<"Welcome what would you like to buy?"<<endl;
                //Present the second shop.
                shop(it,items,used,select,coins,health);
                cout<<"The boss battle starts now!!"<<endl;
            }
            cout << "You are fighting a "<<type<<" type monster."<<endl;
            do{ //Battle Sequence Loop
                do {
                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                    cin >> input;  //Player inputs their move
                    cout << endl;
                }while (input!="dodge" && input!="attack" && input!="inventory");
                if (input=="attack"){ //If player input attack
                    cout<<endl;
                    //Roll the player and monster dice.
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
                    //Sort the player and monster dice.
                    marksort(pDice,n);
                    marksort(cDice,m);
                    //Compare the results
                    pWins = fight(pDice,cDice,cWins);
                    //Display the rolls, and the wins.
                    pntroll(pDice,cDice);
                    cout<<"You won: " << pWins << " rolls" << endl;
                    cout<<"The monster won: "<<cWins<< " rolls"<<endl;
                    //Determine who wins the attack and deal out the damage.
                    whowins(pWins,cWins,health,mhealth,pClass,cClass,pAttck,mAttck);
                    if ((counter % 3)==0 ){ //If counter is divisible by 3 then use special dice
                       //Sort and compare the special dice, then determine if the player wins. 
                       marksort(spDice,sn);
                       bubble(scDice,sm);
                       spWin=swin(spDice,scDice,spWins);
                       pntsrol(spDice,scDice);
                       cout<<"You won: "<<spWins<<" rolls"<<endl;
                       if (spWin == true){ // If the player won.
                           spAtck (mhealth); //Deal damage to the player.
                       }else cout<<"You failed your cast."<<endl;
                    }
                    //Display monster and player health
                    cout<<endl<<mhealth<<" "<<health<<endl;
                    cout<<endl;
                    counter+=1; //Add one to the counter
                }else if (input=="inventory"){ //If the player input "inventory"
                    //Player inventory
                    invtry(it,items,n,cClass,health,mhealth);
                }else{ //If the player input dodge.
                    //Player dodge function:
                    dChance = dodge (skills,ddge,pAglty);
                    //Roll the players and monster dice and sort them.
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);
                    marksort(pDice,n);
                    marksort(cDice,m);
                    //Compare the dice and determine who won.
                    pWins = fight(pDice,cDice,cWins);
                    ddge=rand()%99+1; //Counter attack chance.
                    if(dChance == true && ddge>=50){ //Counter attack was successful.
                        pWins += 3;
                        //Deal damage to the monster.
                        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
                        cout<<"You dodge safely and land a powerful hit"<<endl;
                    }else if (dChance == true && ddge<=50){//Counter attack not success full but dodge was.
                        cout << "You dodge safely!!"<<endl;
                    }else{ //Counter attack and dodge were not successful.
                        //Deal damage to the player
                        health = health - mdmg(cWins, pClass, cClass, mAttck); 
                        cout << "Your dodge attempt failed and you where hit." << endl;
                    }
                    //Display the players and monsters health
                    cout<<mhealth<<" "<<health<<endl; 
                }
                if(it[4]==true && health <= 0){ //If the player purchased the effigy items and died
                        health = effigy; //Reset the players health
                    }
                if (mhealth <= 0){  //Once the player has killed the monster.
                    //Player picks up loot.
                    loot (coin, point, pLuck, score, coins);
                }
            }while(health>0 && mhealth>0);  //End of battle sequence 
        }
    }while(boss==false || health<=0); // End of the game loop
    if (boss==true && mhealth<=0){ //If the player won
        cout<<endl<<endl<<endl;
        cout<<endl<<endl<<endl;
        cout<<endl<<endl<<endl<< "Congratulations you won." << endl;
        //Display the high-score and what the player's skills were.
        highscr(score);
        cout << "Your winning skill set up:" << endl;
        skTree(skills,skNames,mn);
    }else{ // If the player lost.
        cout<<"YOU LOST"<<endl;
    }
    
    //EXIT THE PROGRAM.
    return 0;
}

//Intro Screen:
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

//The Skill functions:
//Primary skill function:
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

//The skill tree:
void skTree (int skills[], string skNames[], short n){
    for (int i=0;i<n;i++){
        cout<<i+1<<". "<<setw(7)<<skNames[i]<<setw(4)<<skills[i]<<endl;
    }
}

//The skill point distributor:
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

//The health point distributor:
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

//Modifiers:
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

//The Shop Functions:
void shop(bool it[],string items[],int n,int select,int &coins,int &health){
    do{
        for(int i=0; i<n; i++){
            if (it[i])cout<<i+1<<". "<<items[i]<<endl;
            else cout<<i+1<<". "<<"Purchased"<<endl; 
        }
        cout<<"Type in 9 to fully heal yourself to a 100. for 10 coins"<<endl;
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
            case 9:
                health = 100;
                coins -= 5;
            case 10:
                cout<<"Thank you come again."<<endl;break;
            default: cout<<"You didn't input a selection"<<endl<<endl;
        }
    }while(!(coins < 5) && !(select==10));
}

//Player Class Selection:
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

//Map Functions:
//Create the map:
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

//Spawn type:
char spType(int spawn){
   spawn = rand()%5;
   if (spawn == 0 || spawn == 4) return '-';
   else if (spawn == 1) return '*';
   else if (spawn == 2) return '#'; 
   else if (spawn == 3) return '=';
}

//Fill the map with monsters:
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

//Movement function:
void movemnt(char pmap[][MAPCOL], string move, int &prow, int &pcol, char &mon){
    do{
        do{
            cout<<"Type in the direction of your turn (up,left,right)"<<endl;
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

//Map printer:
void prntmap(char pmap[][MAPCOL], int prow, int pcol){
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            cout << pmap[i][k];
            if(k==8) cout<<endl;
        }
    }
}

//Monster class setter:
string who(char cClass){
    if (cClass == '*') return "Holy";
    else if (cClass == '=') return "Ghost";
    else if (cClass == '#') return "Dark";
    else if (cClass == 'B') return "BOSS";
}

//Battle Functions:
//Wins:
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

//Fill the roll arrays:
void roll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    for (int i=0; i<sn; i++)spD[i]=rand()%12+1;
    for (int i=0; i<n; i++)pD[i]=rand()%12+1;
    for (int i=0; i<sm; i++)scD[i]=rand()%12+1;
    for (int i=0; i<m; i++)cD[i]=rand()%12+1;
}

//Print the normal roll arrays:
void pntroll(int pD[],int cD[], int m){
    cout << "            NORMAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<pD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout<<endl;
}

//Print the special roll arrays:
void pntsrol(int spD[],int scD[], int m){
    cout <<"            SPECIAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<spD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}


//Player damage calculation:
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

//Monster damage calculation:
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

//Determine who wins:
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

//Player inventory:
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

//Dodge chance:
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

//Calculate the special wins:
bool swin (int spDice [],int scDice [],int &spWins){
    spWins=0;
    for (int i=0; i<2; i++){
        if (spDice[i]>scDice[i]) spWins+=1; 
        else if (spDice[i]==scDice[i]) spWins+=1;
    }
    if (spWins>=2) return true;
    else return false;
}

//Special attack function:
void spAtck (int &mhealth){
    int x;
    cout<<"You unleash a powerful spell and remove half you enemies health"<<endl;
    x = mhealth/2;
    mhealth -= x;
}

//The loot function:
void loot (vector<short> &a,vector<short> &b,int pLuck,int &score,int &coins){
    int x = rand()%99 + 1, n, t;
    bool found1, found2;
    cout<<"You kill the monster!!"<<endl;
    if (x >= pLuck) n=15;
    else n=10;
    for (int i=0;i<n;i++){
        a[i]=rand()%9+1;
        b[i]=rand()%9+1;
    }
    bubble (a,n);
    select (b,n);
    cout<<"Time for some loot"<<endl;
    cout<<"Enter a number between 1 and 9; if it matches the list then you get extra money."<<endl;
    cin>>t;
    if(found1==true){
        cout<<"You guessed correctly"<<endl;
        coins+=5;
        cout<<"You now have: "<<coins<<" coins."<<endl;
    }else{
        cout<<"You guessed incorrectly"<<endl;
        coins+=3;
        cout<<"You now have: "<<coins<<" coins."<<endl;
    }    
    cout<<endl;
    found1=linear(a,n,t);
    cout<<"Enter a number between 1 and 9; if it matches the list then you get extra score."<<endl;
    cin>>t;
    found2=binary(b,n,t);
    if(found2==true){
        cout<<"You guessed correctly"<<endl;
        score+=300;
        cout<<"You now have: "<<score<<" Score points."<<endl;
    }else{
        cout<<"You guessed incorrectly"<<endl;
        score+=100;
        cout<<"You now have: "<<score<<" Score points."<<endl;
    }   
    cout << endl;
}


//The High-score function:
void highscr(int score){
    //Declaration of Variables
    ifstream in;
    ofstream out;
    string name, name1, buffer=" ";
    short score1;
    
    //Open High Score File
    in.open("HighScores.dat");
    in>>name1>>score1;
    
    in.close();
    in.clear();
    
    if (score > score1){
        cout<<endl;
        cout<<"You beat the pervious high-score"<<endl;
        cout<<"The pervious score was:" << endl;
        cout<<score1<<" Points"<<endl;
        cout<<"Your score is:"<<endl;
        cout<<score<<" Points"<<endl;
        out.open("HighScores.dat");
        //Change in high score
        cout<<"Input you name:";
        cin >> name;
        out<<name<<buffer<<score;
        cout<<endl<<endl<<endl<< "Final score summer:"<<endl;
        cout<<name<<"   "<<score<<" Points"<<endl;
        out.close();
        out.clear();
    }else{
        cout << "You didn't beat the pervious high-score"<<endl;
        cout<<name1<<"   "<< score1 <<endl;
    }    
}

//The sorting algorithms:
//Bubble sort with arrays
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

//Bubble sort with vector:
void bubble(vector<short> &a, int n){
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

//Select sort with vector
void select(vector<short> &b, int n){
    int minI, minV;     //Minimum Index, Minimum Value
    for(int s = 0; s < n-1; s++){
        minI = s;
        minV = b[s];
        for(int i = s+1; i<n; i++){
            if (b[i]<minV){
                minV = b[i];
                minI = i;
            }
        }
        b[minI] = b[s];
        b[s] = minV;
    }
}

//The Mark sort
void marksort(int a[],int size){
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

//Searching algorithm:
//Linear search:
bool linear(vector<short> &a, int n, int t){
    for (int i=0; i<n; i++){
        if (t == a[i]) return true;
    }
    return false;
}

//Binary Search
bool binary(vector<short> &a, int n, int t){
    int first = 0,             // First array element       
        last = 11 - 1,         // Last array element       
        middle,                // Mid point of search       
        pos = -1;              // Position of search value
    do{ 
        middle = (first+last)/2;    //Calculate the middle point
        if (a[middle]==t){
            pos = middle;
            return true;
        }
        else if (a[middle] > t) last = middle-1;
        else first = middle+1;
    }while (first <= last);
    return false;
}