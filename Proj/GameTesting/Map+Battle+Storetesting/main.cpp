/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 15, 2016, 12:07 PM
 * Purpose : Testing map mechanics
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <fstream>    //File I/O
#include <string>     //String Library
#include <cstdlib>    //Random number
#include <ctime>      //Used to set random number seed
#include <iomanip>
#include <cmath>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast <unsigned int> (time(0)));
    
    //Declaration of Variables
    ifstream in;
    ofstream out;
    int rows,cols,prow=7, pcol=1, spawn;
    short monMove, pMove, mHealth, bHealth=25, hit, dodge, health, sneak, 
          eHealth, loot;
    short agility, attck, luck, pLuck, pAglty, pAttck, kills;
    string input1, input2, countAtt;
    string line, move, confirm, use;
    char select;
    int coins = 5;
    bool it1 = true, it2 = true, it3 = true, it4 = true, it5 = true, 
         it6 = true, it7 = true;
    string item4="Shield", item6="Holy Spell", item7="Bow";
    float points = 0;
    
    //Skill set-up:
    do{
        cout << "This is the skill setup tree:" << endl 
        << "Here you will decide your attributes:" << endl << endl;
        agility = 5, attck = 5, luck = 2, health = 25, pLuck, pAglty, pAttck, 
        points = 10;
        short w, x, y ,z, choice, remove, extra;
        do{
            cout << "What would you like to level up?" << endl << endl;
            cout << "Type 1 to level up attack (max 10 min 5)" << endl;
            cout << "Type 2 to level up agility (max 10 min 5)" << endl;
            cout << "Type 3 to level up health" << endl;
            cout << "Type 4 to up luck (max 10 min 2)" << endl << endl;
            cout << "You have a total of " << points << " left to add" << endl;
            cin >> choice;
            switch (choice){
                case 1:
                    do{
                        cout << endl << "How many points would you like to add points in to Attack. Current amount : " << attck << 
                             endl << "You have " << points;
                        cout << " points to spend." << endl;
                        cin >> x;
                    } while (x > points);
                    attck = attck + x;
                    points = points - x;
                    while (attck > 10 || attck < 5){
                        cout << "You have " << attck << " points in attack and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in attack." << endl; 
                        if (attck > 10) {
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            attck = attck - remove;
                            points = points + remove;
                        }
                        else if (attck < 5){
                            extra = 5 - attck;
                            attck = 5;
                            points = points - extra;
                            cout << "Your attack was too low it has been reset to 5." << endl;
                        }
                    }
                    cout << endl << "You have a total of " << attck << " points in attack" << endl << endl;
                    break;
                case 2:
                    do{
                        cout << "Would you like to add points in to Agility. Current amount : " << agility << endl << "You have " << points 
                             << " points to spend." << endl;
                        cin >> y;
                    } while (y > points);
                    agility = agility + y;
                    points = points - y;
                    while (agility > 10 || agility < 5){
                        cout << "You have " << agility << " points in agility and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in agility." << endl; 
                        if (agility > 10) {
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            agility = agility - remove;
                            points = points + remove;
                        }
                        else if (agility < 5){
                            extra = 5 - agility;
                            agility = 5;
                            points = points - extra;
                            cout << "Your agility was too low it has been reset to 5." << endl;
                        }
                    }
                    cout << "You have a total of " << agility << " points in agility" << endl;
                    break;
                case 3:
                    do{
                        cout << "Would you like to add points in to Health. Current amount : " << health << endl << "You have " 
                             << points << " points to spend." << endl;
                        cin >> z;
                    } while (z > points);
                    health = health + z;
                    points = points - z;
                    cout << "You have a total of " << health << " hit points." << endl;
                    break;
                case 4: 
                    do{
                        cout << "Would you like to add points in to luck. Current amount : " << luck << endl << "You have " 
                             << points << " points to spend." << endl;
                        cin >> w;
                    } while (w > points);
                    luck = luck + w;
                    points = points - w;
                    while (luck > 10 || luck < 2){
                        cout << "You have " << luck << " points in luck and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in luck." << endl; 
                        if (luck > 10) {
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            luck = luck - remove;
                            points = points + remove;
                        }
                        else if (luck < 2){
                            extra = 2 - luck;
                            luck = 2;
                            points = points - extra;
                            cout << "Your luck was too low it has been reset to 5." << endl;
                        }
                    }
                    cout << "You have a total of " << luck << " points in luck." << endl;
                    break;
            }
        }while (points > 0);
        cout << "Your current skill set is such:" << endl << endl;
        cout << "Attack:" << setw(2) << attck << " Points" << endl;
        cout << "Agility:" << setw(2) << agility << " Points" << endl;
        cout << "Luck:" << setw(2) << luck << " Points" << endl;
        cout << "Total Health:" << setw(2) << health << endl << endl;
        cout << "Are you happy with this ? If so type in yes if not type in no." << endl;
        do{
            cin >> confirm;
        } while(!(confirm == "Yes") && !(confirm == "yes") && !(confirm == "No") && !(confirm == "no"));

    } while (confirm == "No" || confirm == "no");
    
    //The camp shop:
    cout << "Before you go on your journey this is the cape shop" << endl;
    do{
        if (it1)cout << "A. Steel Sword" << endl;
        else cout << "A. Purchased" << endl;
        if (it2)cout << "B. Rabbit's Foot" << endl;
        else cout << "B. Purchased" << endl;
        if (it3)cout << "C. Armor" << endl;
        else cout << "C. Purchased" << endl;
        if (it4)cout << "D. Shield" << endl;
        else cout << "D. Purchased" << endl;
        if (it5)cout << "E. Human Effigy" << endl;
        else cout << "E. Purchased" << endl;
        if (it6)cout << "F. Holy Spell" << endl;
        else cout << "F. Purchased" << endl;
        if (it7)cout << "G. Bow" << endl; 
        else cout << "G. Purchased" << endl;
        cout << "What would you like to purchase?" << coins << " Coins" <<endl;
        cout << "Type in the letter before the item" << endl;
        cin >> select;
        switch (select){
            case 'A': 
                coins = (it1)? coins-=5 : coins = coins; 
                it1 = false;break;
            case 'B':
                coins = (it2)? coins-=5 : coins = coins;
                it2 = false;break;
            case 'C':
                coins = (it3)? coins-=5 : coins = coins;
                it3 = false;break;
            case 'D':
                coins = (it4)? coins-=5 : coins = coins;
                it4 = false;break;
            case 'E':
                coins = (it5)? coins-=5 : coins = coins;
                it5 = false;break;
            case 'F':
                coins = (it6)? coins-=5 : coins = coins;
                it6 = false;break;
            case 'G':
                coins = (it7)? coins-=5 : coins = coins;
                it7 = false;break;
            default: cout << "You didn't input a selection" <<endl;
        }
    }while(!(coins < 5) && !(confirm == "Leave" || confirm == "leave"));
    
    //Modifiers:
    eHealth = health;
    pAglty = 100 - (agility * 9);
    pAttck = 100 - (attck * 5);
    pLuck = 100 - (luck * 4);
    if(it1 == false) pAttck = 100 - ((attck+2) * 5);
    if(it2 == false) pLuck = 100 - ((luck+2) * 4);
    if(it3 == false) health = 25 + 5;
    
    //Input values
    in.open("map.dat");
    in>>rows>>cols;
    
    //Display Output / what is in the file to the output screen
    getline(in,line);
    for(int row=1;row<=rows;row++){
            getline(in,line);
            cout<<line<<endl;
        }
    
    //Where do you want to place the player
    do{
        cout<<"Input the direction of your turn"<<endl;
        cin>>move;
        if (move == "up" || move == "Up") prow -= 1;
        else if (move == "down" || move == "Down") prow += 1;
        else if (move == "right" || move == "Right") pcol += 1;
        else if (move == "left" || move == "Left") pcol -= 1;
        cout<<"Player position in Y = "<<prow<<" Player position in X = "<<pcol<<endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;

        //Read back in the file
        in.close();
        in.clear();

        //Input values
        in.open("map.dat");
        in>>rows>>cols;

        //Display Output and write to the player file
        out.open("player.dat");
        getline(in,line);
        for(int row = 1;row <= rows;row++){
            getline(in,line);
            if(row == prow && (line[pcol] == 'O')){
                line[pcol]='P';
            }
            if (row == prow && line[pcol] == 'X'){
                if (move == "up" || move == "Up") prow += 1;
                else if (move == "down" || move == "Down") prow -= 1;
                else if (move == "right" || move == "Right") {
                    pcol -= 1;
                    line[pcol]='P';
                }
                else if (move == "left" || move == "Left"){
                    pcol += 1;
                    line[pcol]='P';
                }
            }
            cout<<line<<endl;
            out<<line;
        }
        cout<<endl;
        //Spawn chance:
        spawn = rand()%9;
        if (prow == 1 && pcol == 4){
            cout << "You see a looming door in front of you." << endl;
            cout << "There is also a lost merchant.";
            cout << "He does not look human." << endl;
            cout << "He asks you if you see anything you like." << endl;
            do{
                if (it4)cout << "A. Shield" << endl;
                else cout << "A. Purchased" << endl;
                if (it5)cout << "B. Human Effigy" << endl;
                else cout << "B. Purchased" << endl;
                if (it6)cout << "C. Holy Spell" << endl;
                else cout << "C. Purchased" << endl;
                if (it7)cout << "D. Bow" << endl; 
                else cout << "D. Purchased" << endl;
                cout << "What would you like to purchase?" << coins << " Coins";
                cout << endl << "Type in the letter before the item" << endl;
                cin >> select;
                switch (select){
                    case 'A': 
                        coins = (it4)? coins-=5 : coins = coins; 
                        it4 = false;break;
                    case 'B':
                        coins = (it5)? coins-=5 : coins = coins;
                        it5 = false;break;
                    case 'C':
                        coins = (it6)? coins-=5 : coins = coins;
                        it6 = false;break;
                    case 'D':
                        coins = (it7)? coins-=5 : coins = coins;
                        it7 = false;break;
                    default: cout << "You didn't input a valid selection"<<endl;
                }
            }while(!(coins < 5) && !(confirm == "Leave" || confirm == "leave"));
            cout << endl << endl << endl << endl << endl << endl << endl <<endl;
            cout << endl << endl << endl << endl << endl << endl << endl <<endl;
            cout << endl << endl << endl << endl << endl << endl << endl <<endl;
            cout << endl << endl << endl << endl << endl << endl << endl <<endl;
            
            cout << "You open the doors and there stands a 7 foot tall Knight";
            cout << " He raises his sword and you prepare yourself." << endl;
            for (int turns = 0; (turns < 10) && (health > 0) && (bHealth > 0); turns++){
                do {
                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                    cin >> input1;
                    cin.ignore();
                }while (!(input1 == "dodge") && !(input1 == "attack") && !(input1 == "inventory"));
                
                if (input1 == "inventory"){
                    if(it4 == true && it6 == true && it7 == true) {
                        cout << "You have no items" << endl;
                    }
                    else {
                        cout << "Input the name of the item you would like to use" << endl;
                        cout << "You you wont want to use any type in anything" << endl;
                        if (it4 == false)cout << item4 << endl;
                        if (it6 == false)cout << item6 << endl;
                        if (it7 == false)cout << item7 << endl;
                        do{ 
                            getline(cin,use);
                        }while (!(use == item4) && !(use == item6) && !(use == item7));
                        if((it4 == false) && (use == item4)){
                            it4 = true;
                            cout << "You game 3 more hit-points" << endl;
                            health += 3;
                        }
                        else if ((it6 == false) && (use == item6)){
                            short chance = rand()%9 + 1;
                            it6 = true;
                            if (chance%2){
                                cout << "Holy spell worked! YOU DEAL 10 dmg" <<endl;
                                bHealth -= 10;
                            }
                            else { 
                                cout << "The spell failed" << endl;
                            }
                        }
                        else if ((it7 == false) && (use == item7)){
                            cout << "You shoot the boss with your bow." << endl;
                            bHealth -= 5;
                            cout << "Boss health = " << bHealth << endl;
                        }
                    }
                    do {
                        cout << "Input you move (attack, dodge):"<<endl;
                        cin >> input1;
                        cin.clear();
                        cin.ignore();
                    }while (!(input1 == "dodge") && !(input1 == "attack"));
                }
                else if (input1 == "dodge"){
                    dodge = rand()%90 + 11;
                    if (dodge >= pAglty){
                        cout << "Your dodge roll was " << dodge << "; enough to dodge!" << endl;
                        points = points + 0.3;
                        pMove = 0;
                    }
                    else {
                        cout << "Your dodge roll was " << dodge << endl;
                        cout << "YOU FAILED YOUR DODGE YOU MUST ATTACK" << endl;
                        pMove = 1;
                    }
                }
                else{
                    pMove = 1;
                }
                monMove = rand()%9 + 1;
                int mMove = monMove%4;
                if ( (mMove == 1 || mMove == 2 || mMove == 3) && pMove == 0){
                    cout << "YOU DODGED !" << endl;
                    cout << "DO YOU WANT TO TRY TO ATTACK ? (This is risky) (enter yes to attack)" << endl;
                    cin >> countAtt;
                    if (countAtt == "Yes" || countAtt == "yes") {
                        int cAtt = rand()%90 + 11;
                        int cMAtt = rand()%90 + 11;
                        if (cAtt <= 40 && cMAtt >= 50){
                            cout << "YOUR COUNTER ATTACK FAILED AND YOU WERE HIT" << endl;
                            health -= 5;
                        }
                        else if (cAtt <= 40 && cMAtt <= 50){
                            cout << "YOUR COUNTER ATTACK FAILED BUT YOU WERE NOT HIT" << endl;
                        }
                        else{
                            cout << "YOUR COUNTER ATTACK HIT" << endl;
                            bHealth -= 6;
                            points += 1.5;
                        }
                    }
                    cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                }
                else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
                    cout << "YOU HIT THE BOSS AND IT HIT YOU" << endl;
                    hit = rand()%90 + 11;
                    health -= 3;
                    if (hit >= pAttck){
                        cout << "Your critical hit roll was " << hit << endl;
                        cout << "IT WAS A CITICAL HIT" << endl;
                        bHealth -= 5;
                        points += 2;
                    }
                    else {
                        cout << "Your critical hit roll was " << hit << endl;
                        bHealth -= 3;
                        points += 1;
                    }
                    cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                }
                else {
                    cout << "THE BOSS IS DAZED ! YOU ATTACK FOR FREE" << endl;
                    hit = rand()%90 + 11;
                    if (hit >= pAttck){
                        cout << "Your critical hit roll was " << hit << endl;
                        cout << "IT WAS A CITICAL HIT" << endl;
                        bHealth -= 3;
                        points += 2;
                    }
                    else {
                        cout << "Your critical hit roll was " << hit << endl;
                        bHealth -= 1;
                        points += 1;
                    }
                    cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                }
                if (bHealth < 0) {
                    cout << "YOU KILLED THE BOSS" << endl;
                    points += 50;
                }
                if (it5 == false && health < 0){
                    cout << "Your human effigy shudders" << endl;
                    cout << "Your health is refilled" << endl;
                    health = eHealth;
                    it5 = true;
                }
                if (health < 0 ) {cout << "YOU ARE DEAD" << endl;}
            }
        }
        else {
            if (spawn%2==0){
                int c;
                mHealth = 3;
                cout << "MONSTER HAS SPAWNED PREPARE" << endl;
                do{
                    cout << "You do you want to engage or sneak : " << endl;
                    cin >> input2;   
                }while(!(input2 == "engage") && !(input2 == "Engage") && !(input2 == "sneak") && !(input2 == "Sneak"));
                do{
                    if (input2 == "engage" || input2 == "Engage"){
                        c = 1;
                        do{
                            do {
                                cout << "Input you move (attack, dodge, inventory):"<<endl;
                                cin >> input1;
                            }while (!(input1 == "dodge") && !(input1 == "attack") && !(input1 == "inventory"));
                           
                            if (input1 == "inventory"){
                                if(it4 == true && it6 == true && it7 == true) {
                                    cout << "You have no items" << endl;
                                }
                                else{
                                    cout << "Input the name of the item you would like to use" << endl;
                                    cout << "You you wont want to use any type in anything" << endl;
                                    if (it4 == false)cout << item4 << endl;
                                    if (it6 == false)cout << item6 << endl;
                                    if (it7 == false)cout << item7 << endl;
                                    do{ 
                                        getline(cin,use);
                                    }while (!(use == item4) && !(use == item6) && !(use == item7));
                                    if((it4 == false) && (use == item4)){
                                        it4 = true;
                                        health += 3;
                                    }
                                    else if ((it6 == false) && (use == item6)){
                                        cout << "You can only use this item on the boss." << endl;
                                    }
                                    else if ((it7 == false) && (use == item7)){
                                        cout << "You shoot the monster with your bow." << endl;
                                        mHealth -= 2;
                                        cout << "Monster's health = " << mHealth << endl;
                                    }
                                }
                                do {
                                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                                    cin >> input1;
                                    cin.clear();
                                    cin.ignore();
                                }while (!(input1 == "dodge") && !(input1 == "attack"));
                            }
                            
                            else if(input1 == "dodge" || input1 == "Dodge"){
                                dodge = rand()%90 + 11;
                                if (dodge >= pAglty){
                                    cout << "Your dodge roll was " << dodge << "; enough to dodge." << endl;
                                    pMove = 0;
                                    points += 0.3;
                                }
                                else {
                                    cout << "Your dodge roll was " << dodge << endl;
                                    cout << "YOU FAILED YOUR DODGE YOU MUST ATTACK" << endl;
                                    pMove = 1;
                                }
                            }
                            else{
                                pMove = 1;
                            }
                            monMove = rand()%9 + 1;
                            int mMove = monMove%4;
                            if ( (mMove == 1 || mMove == 2 || mMove == 3) && pMove == 0){
                                cout << "YOU DODGED !" << endl;
                                cout << "DO YOU WANT TO TRY TO ATTACK ? (This is risky) (enter yes to attack)" << endl;
                                cin >> countAtt;
                                if (countAtt == "Yes" || countAtt == "yes") {
                                    int cAtt = rand()%90 + 11;
                                    int cMAtt = rand()%90 + 11;
                                    if (cAtt <= 40 && cMAtt >= 50){
                                        cout << "YOUR COUNTER ATTACK FAILED AND YOU WERE HIT" << endl;
                                        health -= 2;
                                    }
                                    else if (cAtt <= 40 && cMAtt <= 50){
                                        cout << "YOUR COUNTER ATTACK FAILED BUT YOU WERE NOT HIT" << endl;
                                    }
                                    else{
                                        cout << "YOUR COUNTER ATTACK HIT" << endl;
                                        mHealth -= 3; 
                                        points += 1.5;
                                    }
                                }
                                cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                        }
                            
                        else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
                            cout << "YOU HIT THE MONSTER AND IT HIT YOU" << endl;
                            hit = rand()%90 + 11;
                            health -= 1;
                            if (hit >= pAttck){
                                cout << "Your critical hit roll was " << hit << endl;
                                cout << "IT WAS A CITICAL HIT" << endl;
                                mHealth -= 3;
                                points += 2;
                            }
                            else {
                                cout << "Your critical hit roll was " << hit << endl;
                                mHealth -= 1;
                                points += 1;
                            }
                            cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                        }
                        else {
                            cout << "THE MONSTER IS DAZED ! YOU ATTACK FOR FREE" << endl;
                            hit = rand()%90 + 11;
                            if (hit >= pAttck){
                                cout << "Your critical hit roll was " << hit << endl;
                                cout << "IT WAS A CITICAL HIT" << endl;
                                mHealth -= 3;
                                points += 2;
                            }
                            else {
                                cout << "Your critical hit roll was " << hit << endl;
                                mHealth -= 1;
                                points += 1;
                            }
                            cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                        }
                        if (it5 == false && health == 0){
                            cout << "Your human effigy shudders" << endl;
                            cout << "Your health is refilled" << endl;
                            health = eHealth;
                            it5 = true;
                        }
                        if (mHealth < 0){
                            cout << "YOU KILLED THE MONSTER" << endl;
                            loot = rand()%90 + 11;
                            coins = (loot >= pLuck)? coins += 2 : coins++;
                            cout << "You looted " << coins << endl;
                            points += 8.3;
                            kills += 1;
                        }
                        if (health < 0 ) {cout << "YOU ARE DEAD" << endl;}

                    }while (mHealth > 0 && health > 0);
                }
                else{
                    sneak = rand()%90 + 11;
                    if (sneak >= pLuck){
                        cout << "You snuck by." << endl;
                        points += 1.8;
                        c = 1;
                    }
                    else {
                        cout << "You alerted the monster." << endl;
                        c = 0;
                        input2 = "engage";
                    }
                }
            } while(c==0);
        }
        else{
            cout << "YOU ARE CLEAR KEEP MOVING" << endl;
        }
    }
        
        //Close the file
        in.close();
        out.close();
    }while (health > 0 && bHealth > 0);
    
    //Score board
    points = sqrt(points);
    cout << points << endl;
    cout << "YOU WON" << endl;
    //Exit Program
    return 0;
}