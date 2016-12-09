/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on December 6, 2016, 4:19 PM
 * Purpose: This is a dungeon crawler game
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
void instruc (string &);
void prntskl(string [], int []);
void mods(int [],bool [], float &, int &, int &, int &, int &);
void skTree (int [], string [], short);
void skillcal (int[], string [], int, short, int&);
void skillcal (int[], string [], short, int&);
void skill (int [], string [], int, int, short, short);
void crtmap(char[][MAPCOL]);
void invtry(bool [], string [], short, char, int &, int &);
void fillmap(char[][MAPCOL], char[][MAPCOL], int, int, int);
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
bool isdodge (int [],int,int);
bool isswin  (int[], int[], int &);
bool islinear (vector<short>, int, int);
bool isbinary (vector<short>, int, int);
int  fight(int[], int[], int &, int = 3);
int movemnt(char[][MAPCOL],string, int &, int &, char &);
short  dmg(int, char, char, float);
short  mdmg(int, char, char, float);
string who(char);

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
    int points = 10, min,                //Number of spendable points, and minimum of each skill.
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
        spWins,scWins,                //Computer and player special wins.
        turns;                        //Number of times the user moves
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
        turns = movemnt(pmap,move,prow,pcol,cClass);
        
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
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m); //Roll the player and computer dice
                    marksort(pDice,n);      //Sort the player's normal dice
                    marksort(cDice,m);      //Sort the computer's normal dice
                    pWins = fight(pDice,cDice,cWins);   //Compare the dice and determine who wins each round
                    pntroll(pDice,cDice);               //Print the dice
                    //Display the wins
                    cout<<"You won: " << pWins << " rolls" << endl;
                    cout<<"The monster won: "<<cWins<< " rolls"<<endl;
                    whowins(pWins,cWins,health,mhealth,pClass,cClass,pAttck,mAttck); //Determine the overall winner and deal out the damage
                    if ((counter % 3)==0 ){ //If counter is divisible by 3 then use special dice
                       marksort(spDice,sn);         //Sort the player's special dice
                       bubble(scDice,sm);           //Sort the computer's special dice
                       spWin=isswin(spDice,scDice,spWins); //Compare the dice and determine who wins each round
                       pntsrol(spDice,scDice);           //Print the dice
                       //Display the wins
                       cout<<"You won: "<<spWins<<" rolls"<<endl;
                       if (spWin == true){ // If the player won.
                           spAtck (mhealth); //Deal damage to the monster.
                       }else cout<<"You failed your cast."<<endl;
                    }
                    //Display monster and player health
                    cout<<endl<<mhealth<<" "<<health<<endl;
                    cout<<endl;
                    counter+=1; //Add one to the counter
                }else if (input=="inventory"){ //If the player input "inventory"
                    invtry(it,items,n,cClass,health,mhealth); //Player inventory
                }else{ //If the player input dodge.
                    dChance = isdodge (skills,ddge,pAglty);   //Player dodge function
                    roll(spDice,sn,pDice,n,scDice,sm,cDice,m);  //Roll the player and computer dice
                    marksort(pDice,n);      //Sort the player's normal dice
                    marksort(cDice,m);      //Sort the computer's normal dice
                    pWins = fight(pDice,cDice,cWins);   //Compare the dice and determine who won.
                    ddge=rand()%99+1;                   //Counter attack chance.
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
        cout << "It took you: "<<turns<<" moves to finish the game."<<endl;
        cout << "Your winning skill set up:" << endl;
        skTree(skills,skNames,mn);
    }else{ // If the player lost.
        cout<<"YOU LOST"<<endl;
    }
    
    //EXIT THE PROGRAM.
    exit(1);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   intro   ****************************************
//Purpose:  Display the introduction screen
//Inputs:   start
//  start: a string used to start the game
//Output:  None
//******************************************************************************
void intro (string start){
    cout << "    ==================================================================" << endl;
    cout << "                Welcome to Dungeon Crawler Version 2" << endl;
    cout << "              Created by Hassan Farhat for CSC-5 48102" << endl;
    cout << "            If you want to read a quick guide type in guide"<<endl;
    cout << "                  When you are ready type in start" << endl;
    cout << "    ==================================================================" << endl;
    do{
        cin >> start;
        if(start == "guide") instruc(start);
    }while (start!= "start");
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   instruc   ****************************************
//Purpose:  Display the instructions of the game
//Inputs:   start
//  start: a string used to start the game
//Output:  The users answer or reference value of start
//******************************************************************************
void instruc(string & start){
    cout<<"Welcome to Dungeon Crawler Version 2!"<<endl;
    cout<<"Here is a quick guide to teach you the basics of how your" 
        <<endl<< "class selection effects you:(This is important)" <<endl;
    cout<<"You and the monsters in this game will be one of three"<<endl<<
        "classes:"<<endl;
    cout<<"(*) or Paladin (Holy class)"<<endl;
    cout<<"(#) or Demon-Hunter (Dark class)"<<endl;
    cout<<"(=) or Necromancer (Ghost class)"<<endl<<endl;
    cout<<"These classes interact as follows:"<<endl;
    cout<<"Ghost beats Holy beats Dark beats Ghost."<<endl<<endl;
    cout<<"Go have some fun!!"<<endl;
    cout<<"Type in start to begin"<<endl;
    do{
        cin >> start;
    }while (!(start == "start"));
}

//The Skill functions:
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************   skill   ****************************************
//Purpose:  Allows the user to set up there skills
//Inputs:  skills : An array that store the skill values
//         skNames: An array that stores the skill names
//          points: Number of spendable points
//             min: The minimum number of points
//               n: The utilized portion of the array.
//          choice: The users selection for the skill
//Output:  the new values of the skills
//******************************************************************************
void skill(int skills[], string skNames[], int points, int min, short n, short choice){
    cout << "This is the skill setup tree:" << endl 
    << "Here you will decide your attributes:" << endl << endl;
    do{ //Skill Set-Up loop starts here
        skTree(skills,skNames,n);
        cout << "What skill would you like to rank up?" << endl;
        cout << "You have " << points << " left to upgrade." << endl;
        cout << "Type in the number before the skill." << endl;
        cout << "The max for each skill is 10"<<endl;
        do{ 
            cin >> choice;  //User inputs their choice
        }while (choice > 4);
        switch (choice){        //Send user to the correct skill based on input.
            case 1:             //User selected agility.
                min=6;          //Set the minimum value for the skill.
                //Add and remove points from the skill (in a function).
                skillcal(skills,skNames,min,choice,points);
                //Display the name of the skill and what is in it.
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1]
                <<" in it."<<endl<<endl;
                break;
            case 2:             //User selected attack.
                min=7;          //Set the minimum value for the skill.
                skillcal(skills,skNames,min,choice,points);               //Add and remove points from the skill (in a function).
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1] //Display the name of the skill and what is in it.
                <<" in it."<<endl<<endl;
                break;
            case 3:             //User selected luck.
                min=2;          //Set the minimum value for the skill.
                skillcal(skills,skNames,min,choice,points);               //Add and remove points from the skill (in a function).
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1] //Display the name of the skill and what is in it.
                <<" in it."<<endl<<endl;
                break;
            case 4:             //User selected Health.
                skillcal(skills,skNames,choice,points);                   //Add and remove points from the skill (in a function).
                cout<<endl<<skNames[choice-1]<< " has "<<skills[choice-1] //Display the name of the skill and what is in it.
                <<" in it."<<endl<<endl;
                break;
        }
    }while (points > 0);  //End of Skill Set-Up loop
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************   skTree   ***************************************
//Purpose:  Displays the skills and their values
//Inputs:  skills : An array that store the skill values
//         skNames: An array that stores the skill names
//               n: The utilized portion of the array.
//Output:  None
//******************************************************************************
void skTree (int skills[], string skNames[], short n){
    //Display the skill tree
    for (int i=0;i<n;i++){
        cout<<i+1<<". "<<setw(7)<<skNames[i]<<setw(4)<<skills[i]<<endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   skillcal   ***************************************
//Purpose:  Calculates the skill values based on user input
//Inputs:   skills: An array that store the skill values
//         skNames: An array that stores the skill names
//          points: Number of spendable points
//             min: The minimum number of points
//          choice: The users selection for the skill
//Output:  The new value of the skill 
//******************************************************************************
void skillcal (int skills[],string skNames[],int min,short choice,int &points){
    int x, remove, extra;       //x,remove, and extra are holder values.
    do{
        cout<<endl<<"How many points would you like to add in to "
            <<skNames[choice-1]<<endl<<"You have "<<points<< " to spend."<<endl;
        cin >> x;   //Storage of points to add.
    }while (x > points);
    skills[choice-1] += x; //Add points to the skill in the array. 
    points -= x;           //Subtract added points.
    while (skills[choice-1] > 10 || skills[choice-1] < min){ //Start check.
        cout<<"You have "<<skills[choice-1]<<" points in "<<skNames[choice-1];
        cout<<endl<<"you cannot have more than 10 point or less than "<<min
            <<" points."<<endl;
        if (skills[choice-1] > 10){ //If points exceed the maximum.
            //Ask the user to remove some points and add them back to the total.
            cout<<"Please input how many you would like to remove?"<<endl;
            cin>>remove;
            skills[choice-1] = skills[choice-1] - remove;
            points = points + remove;
        }
        else if (skills[choice-1] < min){ //If the points are less than the minimum.
            //Calculations that correct to few points.
            extra = min - skills[choice-1];  
            skills[choice-1] = min;
            points = points - extra;
            cout<<"Your " << skNames[choice-1] << " was too low it has been "
                <<"reset to "<< min << endl;
        }
    }   //End of Check
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   skillcal   ***************************************
//Purpose:  Calculates the health skill value
//Inputs:   skills: An array that store the skill values
//         skNames: An array that stores the skill names
//          points: Number of spendable points
//          choice: The users selection for the skill
//Output:  The new value of the skill 
//******************************************************************************
void skillcal (int skills[], string skNames[], short choice, int &points){
    int x; //A holder value
    do{
        cout<<endl<<"How many points would you like to add in to "
            <<skNames[choice-1]<<endl<<"You have "<<points<<" to spend."<<endl;
        cin >> x; //Storage of points to add.
    }while (x > points);
    skills[choice-1] += x;   //Add points to health.
    points -= x;             //Remove added points from total.
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  mods  *****************************************
//Purpose:  Calculates the skill values based on user input
//Inputs:   skills: An array that store the skill values
//              it: A boolean array that store the states of the items
//         pAttack: The players usable attack value
//          pAglty: The player modifier value for dodge
//           pLuck: The player modifier value for luck
//          health: The player's health
//          effigy: This variable store the players health and is a usable item
//Output:  All the modifier values that are used in the game
//******************************************************************************
void mods (int skills[],bool it[],float &pAttck,int &pAglty,int &pLuck,int &health, int &effigy){
    //Set health, attack, agility and luck based on points and items
    health = skills[3];
    effigy = health;
    pAttck = skills[1] / 2;
    pAglty = 100 - (skills[0] * 9);   
    pLuck = 100 - (skills[2] * 4);
    //If any items where purchased:
    if(it[2] == false) pLuck = 100 - ((skills[2]+2) * 4);
    if(it[3] == false) health = skills[3] + 5;
    if(it[5] == false) pAttck = (skills[1]+1)/ 2;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  shop  *****************************************
//Purpose:  A shop where the user can buy items from
//Inputs:   skills: An array that store the skill values
//              it: A boolean array that store the states of the items
//           items: An array that stores the names of each item
//               n: Utilization of the array
//          select: An int used for user select
//           coins: The amount of coins the use has
//          health: The players health
//Output:  The item arrays, an updated player wallet, and updated player health
//******************************************************************************
void shop(bool it[],string items[],int n,int select,int &coins,int &health){
    do{ //Start of shop loop
        //Display the store
        for(int i=0; i<n; i++){
            if (it[i])cout<<i+1<<". "<<items[i]<<endl;
            else cout<<i+1<<". "<<"Purchased"<<endl; 
        }
        cout<<"Type in 9 to fully heal yourself to a 100. for 10 coins"<<endl;
        cout<<"You currently have "<<coins<<" coins."<<endl; 
        cout<<"Type in the number before the item to buy it."<<endl;
        cout<<"Each item costs 5 coins."<<endl;
        cout<<"You can leave by typing in 10"<<endl;
        cin>>select;        //User makes a selection
        cout<<endl;
        switch (select){    //Show selection switch case Shield 
            case 1:  //User purchased shield
                coins = (it[0])? coins-=5 : coins = coins; 
                it[0] = false;break;
            case 2: //User purchased Holy spell
                coins = (it[1])? coins-=5 : coins = coins;
                it[1] = false;break;
            case 3: //User purchased Armor
                coins = (it[2])? coins-=5 : coins = coins;
                it[2]= false;break;
            case 4: //User purchased Sword
                coins = (it[3])? coins-=5 : coins = coins;
                it[3] = false;break;
            case 5: //User purchased Human Effigy
                coins = (it[4])? coins-=5 : coins = coins;
                it[4] = false;break;
            case 6: //User purchased Rabbit's Foot
                coins = (it[5])? coins-=5 : coins = coins;
                it[5] = false;break;
            case 7: //User purchased Bow
                coins = (it[6])? coins-=5 : coins = coins;
                it[6] = false;break;
            case 9: //User purchased Health refill
                health = 100;
                coins -= 10;
            case 10:
                cout<<"Thank you come again."<<endl;break;
            default: cout<<"You didn't input a selection"<<endl<<endl;
        }
    }while(!(coins < 5) && !(select==10)); //End of shop loop
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  clsslct  ****************************************
//Purpose:  Allow the player to choose their class
//Inputs:   None
//Output:  returns the players class
//******************************************************************************
char clsslct(){
    string clss; //Class selection value
    cout <<"What class would you like to use?"<<endl;
    cout <<"1. Paladin      (Holy type class)"<<endl
         <<"2. Necromancer  (Ghost type class)"<<endl
         <<"3. Demon-Hunter (Dark type class)"<<endl;
    do{
        cout << "Please type in the full name of the class" << endl;
        cin >> clss; //User input their class
    } while(clss!="Paladin" && clss!="Necromancer" && clss!="Demon-Hunter");
    
    //Return the class
    if (clss == "Paladin") return 'H';
    else if (clss == "Necromancer") return 'G';
    else if (clss == "Demon Hunter") return 'D';
}

//Map Functions:
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  crtmap  ****************************************
//Purpose:  Create the standard map
//Inputs:   map:a character array that stores the standard game map
//Output:   The map array (reference)
//******************************************************************************
void crtmap(char map[][MAPCOL]){
    //Fill the standard map
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            if(i==0 && (k==0 || k==8)) map[i][k]='|';
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  spType  ****************************************
//Purpose:  Determine what monster ill spawn
//Inputs:   spawn: The type of monster that will spawn
//Output:   returns a specific character
//******************************************************************************
char spType(int spawn){
    //Fill the standard map with Monsters
   spawn = rand()%5;
   if (spawn == 0 || spawn == 4) return '-';
   else if (spawn == 1) return '*';
   else if (spawn == 2) return '#'; 
   else if (spawn == 3) return '=';
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  fillmap  ***************************************
//Purpose:  Fills the map array with chars 
//Inputs:   pmap: The player map array
//           map: The standard map array
//         spawn: The type of monster that will spawn
//          prow: The players row coordinate
//          pcol: The players col coordinates
//Output:   pmap, map
//******************************************************************************
void fillmap(char pmap[][MAPCOL], char map[][MAPCOL], int spawn, int prow, int pcol){
    for (int i=0; i<7; i++){ //Loops that fills the map with characters
            for (int k=0; k<9; k++){
                if(map[i][k]=='-' || map[i][k]=='*' || map[i][k]=='#')
                    map[i][k] = spType(spawn); //Calls the spawn type function.
            }
        }
    //Copy the standard map on to the display map.
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            if (i!=prow || k!=pcol) pmap[i][k]= map[i][k];
        }
    }
    //Display the display map.
    for (int i=0; i<7; i++){
        for (int k=0; k<9; k++){
            cout << pmap[i][k];
            if(k==8) cout<<endl;
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  movement  ***************************************
//Purpose:  Allows player movement
//Inputs:   pmap: The player map array
//          move: Variable used for player movement
//          prow: The players row coordinate
//          pcol: The players col coordinates
//           mon: the monster type        
//Output:   prow, pcol, mon, pmap
//******************************************************************************
int movemnt(char pmap[][MAPCOL], string move, int &prow, int &pcol, char &mon){
    static int turns = 0;
    do{
        cout<<"Type in the direction of your turn (up,left,right)"<<endl;
        cin>>move; //User inputs their move
    }while(move!="up" && move!="left" && move!="right");
    //Determine player location on map
    if (move == "up" || move == "Up") prow -= 1;
    else if (move == "right" || move == "Right") pcol += 1;
    else if (move == "left" || move == "Left") pcol -= 1;
    if (pmap[prow][pcol]=='|'){
        if (move == "up" || move == "Up") prow += 1;
        else if (move == "right" || move == "Right") pcol -= 1;
        else if (move == "left" || move == "Left") pcol += 1;
    }
    mon = pmap[prow][pcol]; 
    pmap[prow][pcol] = 'P'; //Set player location
    turns+=1;
    return turns;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*******************************  who  ****************************************
//Purpose:  Sends back the name of the monster class 
//Inputs:   cClass      
//Output:   return class type in written text
//******************************************************************************
string who(char cClass){
    //Determine the monster's character and return its class type.
    if (cClass == '*') return "Holy";
    else if (cClass == '=') return "Ghost";
    else if (cClass == '#') return "Dark";
    else if (cClass == 'B') return "BOSS";
}

//Battle Functions:
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  fight  ****************************************
//Purpose:  Fills the map array with chars 
//Inputs:   cClass      
//Output:   return class type in written text
//******************************************************************************
int  fight(int pD[],int cD[],int &cWins,int m){
    int pWins=0;    //Player wins
        cWins=0;    //Computer wins
    for (int i=0; i<m; i++){ //For loop used to compare the dice
        if (pD[i]>cD[i]) pWins+=1;       //If user wins add to player wins
        else if (pD[i]<cD[i]) cWins+=1;  //If computer wins add to computer wins
        else{       //If the computer wins 
            pWins+=1;   //Add to player wins
            cWins+=1;   //Add to computer wins
        }
    }
    return pWins;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  roll  ****************************************
//Purpose:  Fill in the roll arrays
//Inputs:   spD: Array for special dice of the player
//           sn: The utilization of the spD.
//           pD: Array for the normal dice of the player
//            n: The utilization of the pD.
//          scD: Array for special dice of the player
//           sm: The utilization of the scD.
//           cD: Array for the normal dice of the player
//            m: The utilization of the cD.
//Output:   spD,pD,scD,cD
//******************************************************************************
void roll(int spD[],int sn,int pD[],int n,int scD[],int sm,int cD[],int m){
    //Fill the dice arrays 
    for (int i=0; i<sn; i++)spD[i]=rand()%12+1;
    for (int i=0; i<n; i++)pD[i]=rand()%12+1;
    for (int i=0; i<sm; i++)scD[i]=rand()%12+1;
    for (int i=0; i<m; i++)cD[i]=rand()%12+1;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  pntroll  ****************************************
//Purpose:  Print the roll arrays
//Inputs:   pD : The player normal dice array
//          cD : The computer's normal dice array
//Output:   pD,cD
//******************************************************************************
void pntroll(int pD[],int cD[], int m){
    //Print the normal dice.
    cout << "            NORMAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<pD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<cD[i];
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  pntsrol  ****************************************
//Purpose:  Print the special roll arrays
//Inputs:   spD: Array for special dice of the player
//          scD: Array for special dice of the player
//Output:   spD,scD
//******************************************************************************
void pntsrol(int spD[],int scD[], int m){
    //Print the special dice.
    cout <<"            SPECIAL DICE" << endl;
    cout << "Your rolls:  ";
    for (int i=0; i<m; i++)cout<<setw(3)<<spD[i];
    cout << endl<< "Enemy rolls: ";
    for (int i=0; i<m; i++)cout<<setw(3)<<scD[i];
    cout<<endl;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  dmg  ******************************************
//Purpose:  Determine how much damage will be dealt
//Inputs:   wins: The number of time the player won a roll
//        pClass: The player's class
//        cClass: The computer's class
//        pAttck: The players usable attack value
//Output:   returns the amount of damage that will be dealt
//******************************************************************************
short  dmg(int wins, char pClass, char cClass, float pAttck){
    int damage = wins * pAttck;  //The damage that will be dealt.
    if (pClass=='D' && cClass=='*') return damage/2;      //Return the damage value          
    else if (pClass=='D' && cClass=='=') return damage+3; //Return the damage value 
    else if (pClass=='H' && cClass=='#') return damage+3; //Return the damage value 
    else if (pClass=='H' && cClass=='=') return damage/2; //Return the damage value 
    else if (pClass=='G' && cClass=='#') return damage/2; //Return the damage value 
    else if (pClass=='G' && cClass=='*') return damage+3; //Return the damage value 
    else return damage;                                   //Return the damage value 
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  mdmg  *****************************************
//Purpose:  Determine how much damage will be dealt
//Inputs:   wins: The number of time the monster won a roll
//        pClass: The player's class
//        cClass: The computer's class
//        mAttck: The monster's attack value
//Output:   returns the amount of damage that will be dealt
//******************************************************************************
short  mdmg(int wins, char pClass, char cClass, float mAttck){
    int damage = (wins * mAttck + 0.5);  //The damage that will be dealt.
    if (cClass=='#' && pClass=='H') return damage/2;      //Return the damage value
    else if (cClass=='#' && pClass=='G') return damage+3; //Return the damage value
    else if (cClass=='*' && pClass=='D') return damage+3; //Return the damage value
    else if (cClass=='*' && pClass=='G') return damage/2; //Return the damage value
    else if (cClass=='=' && pClass=='D') return damage/2; //Return the damage value
    else if (cClass=='=' && pClass=='H') return damage+3; //Return the damage value
    else return damage;                                   //Return the damage value
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  whowins  ***************************************
//Purpose:  Determine who wins the fight
//Inputs:  pwins: The number of time the player won a roll
//         cwins: The number of time the monster won a roll
//        health: The player's health
//       mhealth: The monster's health
//        pClass: The player's class
//        cClass: The computer's class
//        mAttck: The monster's attack value
//Output:   health, mhealth
//******************************************************************************
void whowins(int pWins,int cWins,int &health, int &mhealth,char pClass,char cClass,float pAttck,float mAttck){
    if (pWins>cWins){ //If the player has more round wins
        //Deal damage to the monster
        cout<<"You attack"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
    }else if (pWins<cWins){ //If the player has less round wins
        //Deal damage to the player
        cout<<"The monster successfully attacks"<<endl;
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }else{ //If the player has 
        //Deal damage to the player and  monster
        cout<<"You both hit each other"<<endl;
        mhealth = mhealth - dmg(pWins, pClass, cClass, pAttck);
        health = health - mdmg(cWins, pClass, cClass, mAttck);
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  invtry  ***************************************
//Purpose:  Display and allow the player to use items they purchased
//Inputs:  it: Boolean array that stores the active values of the item
//      items: String array that stores the names of the items
//          n: The utilization of the arrays
//     cClass: The Computers class
//     health: The player's health
//    mHealth: The monster's health
//Output:   health, mhealth
//******************************************************************************
void invtry(bool it[], string items[], short n, char cClass, int &health, int &mHealth){
    string use;   //Inventory user value
    cout << "Input the name exactly of the item you would like to use" << endl;
    cout << "If you don't want to use any item type in leave" << endl;
    if (it[0] == false)cout <<"- "<< items[0] << endl;   //Shield
    if (it[1] == false)cout <<"- "<<items[1] << endl;    //Holy Spell
    if (it[6] == false)cout <<"- "<<items[6] << endl;    //Bow
    if (it[0]==true&&it[1]==true&&it[6]==true) cout<<"You have no items."<<endl;
    do{ 
        getline(cin,use);   //Player inputs what item they wish to use
    }while (use!=items[0] && use!=items[1] && use!=items[6] && use!="leave");
    if(it[0]==false && use==items[0]){ //Player chose to use the shield
        //Set item boolean to false and activate the item
        it[0]=false;
        cout<<"You gain 10 points of health"<<endl;
        health += 10;
    }else if(it[1]==false && use==items[1]){ //Player chose to use the shield
        if(cClass=='B'){    //If the boss is active 
            //Set item boolean to false
            short chance = rand()%9 + 1;
            it[1] = true;
            if (chance%2){ //If the chance is true
                //Activate the item
                cout << "Holy spell worked! YOU DEAL 10 dmg" <<endl;
                mHealth -= 10;
            }else {
                cout << "The spell failed" << endl;
            }
        }else {
            cout<<"This item can only be used in the boss battle."<<endl;
        }
    }else if(it[6]==false && use==items[6]){
        if (cClass=='B'){ //If the boss is active
            //Set item boolean to false and activate the item
            it[6]=true;
            cout << "You shoot at the boss and deal 8 damage" << endl;
            mHealth-=8;
        }else { //If the boss is inactive
            //Set item boolean to false and activate the item
            it[6]=true;
            cout << "You kill the monster with a brilliant shot" << endl;
            mHealth = 0;
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  isdodge  ***************************************
//Purpose:  Determine if the player dodged
//Inputs:   skills: The array that stores the players skills values
//            ddge: Variable that uses a random number used to determine if the player dodges
//          pAglty: The player's modifier value for agility
//Output:   returns a true or false boolean . (the player dodges or they don't)
//******************************************************************************
bool isdodge (int skills[], int ddge,int pAglty){
    ddge = rand()%99+1+(skills[2]/2); //Calculate dodge chance
    if (ddge >= pAglty){ //If dodge chance is greater than agility 
        cout << "You successfully dodged." << endl;
        return true; //return true
    }else { //If dodge chance is less than agility
        cout << "The dodge failed." << endl;
        return false; //return false
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  isswin  ***************************************
//Purpose:  Determine of the player won the special rolls
//Inputs:  spDice: Array for the player's special dice
//         scDice: Array for the computer's special dice
//         spWins: the player's special wins
//Output:   returns a true or false boolean value
//******************************************************************************
bool isswin (int spDice [],int scDice [],int &spWins){
    spWins=0;   //Set the wins to 0
    for (int i=0; i<2; i++){ //Loop to check each dice.
        if (spDice[i]>scDice[i]) spWins+=1; //If user wins add to player wins 
        else if (spDice[i]==scDice[i]) spWins+=1; //If computer wins add to computer wins
    }
    if (spWins>=2) return true; //If the player wins are greater than or equal to two then return true
    else return false;      //Else return false
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  spAtck  ***************************************
//Purpose:  Reduce the monster's health by half
//Inputs:  mhealth : The monsters health
//Output:   mhealth
//******************************************************************************
void spAtck (int &mhealth){
    cout<<"You unleash a powerful spell and remove half you enemies health"<<endl;
    //Remove half of the monsters health.
    mhealth = mhealth/2; 
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//******************************  loot  ****************************************
//Purpose:  Determine how much loot the player gets 
//Inputs:   a : Vector that stores random number from with number from 1 to 9
//          b : Vector that stores random number from with number from 1 to 9
//          pLuck : The player Luck modifier 
//          scores: The player's score
//          coins : The player's amount of coins
//Output:   a,b,score,coins
//******************************************************************************
void loot (vector<short> &a,vector<short> &b,int pLuck,int &score,int &coins){
    int x = rand()%99 + 1, 
            n, //Size of vector utilization
            t; //User input
    bool found1, found2; //Boolean found values
    cout<<"You kill the monster!!"<<endl;
    if (x >= pLuck) n=15; //If x greater than luck n=15
    else n=10;  //else n=10
    for (int i=0;i<n;i++){  //Fill the 2 vectors
        b[i]=rand()%9+1;
    }
    //Sort the two vectors
    bubble (a,n);
    select (b,n);
    //User enters first guess value.
    cout<<"Time for some loot"<<endl;
    cout<<"Enter a number between 1 and 9; if it matches the list then you get extra money."<<endl;
    cin>>t;
    //Search the list
    found1=islinear(a,n,t);
    if(found1==true){ //If first guess was correct
        //Add 5 coins to the total coin amount.
        cout<<"You guessed correctly"<<endl;
        coins+=5;
        cout<<"You now have: "<<coins<<" coins."<<endl;
    }else{ //else
        //Add 3 coins to the total coin amount.
        cout<<"You guessed incorrectly"<<endl;
        coins+=3;
        cout<<"You now have: "<<coins<<" coins."<<endl;
    }    
    cout<<endl;
    cout<<"Enter a number between 1 and 9; if it matches the list then you get extra score."<<endl;
    cin>>t;
    //Search the list
    found2=isbinary(b,n,t);
    if(found2==true){ //If second guess was correct
        //Add 300 coins to the total coin amount.
        cout<<"You guessed correctly"<<endl;
        score+=300;
        cout<<"You now have: "<<score<<" Score points."<<endl;
    }else{
        //Add 100 coins to the total coin amount.
        cout<<"You guessed incorrectly"<<endl;
        score+=100;
        cout<<"You now have: "<<score<<" Score points."<<endl;
    }   
    cout << endl;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*****************************  highscr  **************************************
//Purpose:  Display the player's score
//Inputs:   score : Player's score
//Output:   None
//******************************************************************************
void highscr(int score){
    //Declaration of Variables
    ifstream in;
    ofstream out;
    string name, name1, buffer=" ";
    short score1;
    
    //Open High Score File
    in.open("HighScores.dat");
    in>>name1>>score1; //Pull in the name and the score from the file
    
    //Close and clear
    in.close();
    in.clear();
    
    if (score > score1){ //If the user beat the previous score
        //Display both players score and the one stored
        cout<<endl;
        cout<<"You beat the pervious high-score"<<endl;
        cout<<"The pervious score was:" << endl;
        cout<<score1<<" Points"<<endl;
        cout<<"Your score is:"<<endl;
        cout<<score<<" Points"<<endl;
        //Open the file
        out.open("HighScores.dat");
        //Change the name and high score
        cout<<"Input you name:";
        cin >> name;
        out<<name<<buffer<<score;
        //Display the player's score.
        cout<<endl<<endl<<endl<< "Final score summer:"<<endl;
        cout<<name<<"   "<<sqrt(score)<<" Points"<<endl;
        //Close and clear the file
        out.close();
        out.clear();
    }else{//Else 
        //User enters name and their score is displayed
        cout << "You didn't beat the pervious high-score"<<endl;
        cout<<"Input you name:";
        cin >> name;
        cout<<name1<<"   "<< sqrt(score1) <<endl;
    }    
}

//The sorting algorithms:
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  Bubble  ****************************************
//Purpose:  Sort the random list
//Inputs:   a: The array that holds dice
//          n: The utilization of the array
//Output:   a
//******************************************************************************
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  Bubble  ****************************************
//Purpose:  Sort the random list
//Inputs:   a: The random list (vector)
//          n: The utilization of the array
//Output:   a
//******************************************************************************
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  select  ****************************************
//Purpose:  Sort the random list
//Inputs:   b: The random list (vector)
//          n: The utilization of the array
//Output:   a
//******************************************************************************
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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//****************************  marksort  ****************************************
//Purpose:  Sort the random list
//Inputs:   a: The array that holds dice
//          size: The utilization of the array
//Output:   a
//******************************************************************************
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
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  islinear  ***************************************
//Purpose:  Sort the random list
//Inputs:   a: The random list (vector)
//          n: The utilization of the array
//          t: The player's guess
//Output:   return true, or false
//******************************************************************************
bool islinear(vector<short> a, int n, int t){
    for (int i=0; i<n; i++){
        if (t == a[i]) return true;
    }
    return false;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//***************************  isbinear  ***************************************
//Purpose:  Sort the random list
//Inputs:   a: The random list (vector)
//          n: The utilization of the array
//          t: The player's guess
//Output:   return true, or false
//******************************************************************************
bool isbinary(vector<short> a, int n, int t){
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