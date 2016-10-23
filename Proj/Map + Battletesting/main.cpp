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
    int monMove, pMove, mHealth, bHealth=25, hit, dodge, health, sneak;
    int agility, attck, luck, pLuck, pAglty, pAttck, points;
    string input1, input2, countAtt;
    string line, move, confirm;
    
    //Skill set-up:
    do{
        cout << "This is the skill setup tree:" << endl << "Here you will decide your what your character is best at" << endl << endl;
        agility = 5, attck = 5, luck = 2, health = 25, pLuck, pAglty, pAttck, points = 10;
        int w, x, y ,z, choice, remove, extra;
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
                        cout << endl << "How many points would you like to add points in to Attack. Current amount : " << attck << endl << "You have " << points;
                        cout << " points to spend." << endl;
                        cin >> x;
                    } while (x > points);
                    attck = attck + x;
                    points = points - x;
                    while (attck > 10 || attck < 5){
                        cout << "You have " << attck << " points in attack and you cannot have more than 10 points or less" << endl << "than 5 points in attack." << endl; 
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
                        cout << "Would you like to add points in to Agility. Current amount : " << agility << endl << "You have " << points << " points to spend." << endl;
                        cin >> y;
                    } while (y > points);
                    agility = agility + y;
                    points = points - y;
                    while (agility > 10 || agility < 5){
                        cout << "You have " << agility << " points in agility and you cannot have more than 10 points or less" << endl << "than 5 points in agility." << endl; 
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
                        cout << "Would you like to add points in to Health. Current amount : " << health << endl << "You have " << points << " points to spend." << endl;
                        cin >> z;
                    } while (z > points);
                    health = health + z;
                    points = points - z;
                    cout << "You have a total of " << health << " hit points." << endl;
                    break;
                case 4: 
                    do{
                        cout << "Would you like to add points in to luck. Current amount : " << luck << endl << "You have " << points << " points to spend." << endl;
                        cin >> w;
                    } while (w > points);
                    luck = luck + w;
                    points = points - w;
                    while (luck > 10 || luck < 2){
                        cout << "You have " << luck << " points in luck and you cannot have more than 10 points or less" << endl << "than 5 points in luck." << endl; 
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
        cout << "Attack: " << attck << " Points" << endl;
        cout << "Agility: " << agility << " Points" << endl;
        cout << "Luck: " << luck << " Points" << endl;
        cout << "Total Health: " << health << endl << endl;
        cout << "Are you happy with this ? If so type in yes if not type in no." << endl;
        do{
            cin >> confirm;
        } while(!(confirm == "Yes") && !(confirm == "yes") && !(confirm == "No") && !(confirm == "no"));

    } while (confirm == "No" || confirm == "no");
    
    //Modifiers:
    pAglty = 100 - (agility * 9);
    pAttck = 100 - (attck * 5);
    pLuck = 100 - (luck * 4);
    
    //Input values
    in.open("map.dat");
    in>>rows>>cols;
    cout<<"rows = "<<rows<<" cols = "<<cols<<endl;
    
    //Display Output / what is in the file to the output screen
    //In addition add in row numbers and column numbers for the user
    getline(in,line);
    for(int row=1;row<=rows;row++){
            getline(in,line);
            cout<<row<<" "<<line<<endl;
        }
        cout<<"  ";
        for(int col=1;col<=cols;col++){
            cout<<col;
        }
        cout<<endl;

        //Where do you want to place the player
        do{
            cout<<"Input the direction of your turn"<<endl;
            cin>>move;
            if (move == "up" || move == "Up") prow -= 1;
            else if (move == "down" || move == "Down") prow += 1;
            else if (move == "right" || move == "Right") pcol += 1;
            else if (move == "left" || move == "Left") pcol -= 1;
            cout<<"Player position in Y = "<<prow<<" Player position in X = "<<pcol<<endl;
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

            //Read back in the file
            in.close();
            in.clear();

            //Input values
            in.open("map.dat");
            in>>rows>>cols;
            cout<<"rows = "<<rows<<" cols = "<<cols<<endl;

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
            spawn = rand()%9 + 1;
            if (prow == 1 && pcol == 4){
                cout << "Boss battle !!" << endl;
                do{
                    do {
                        cout << "Input you move (attack or dodge):"<<endl;
                        cin >> input1;
                    }while (!(input1 == "dodge") && !(input1 == "Dodge") && !(input1 == "attack") && !(input1 == "Attack"));
                    if (input1 == "dodge" || input1 == "Dodge"){
                        dodge = rand()%90 + 11;
                        if (dodge >= pAglty){
                            cout << "Your dodge roll was " << dodge << "; enough to dodge." << endl;
                            pMove = 0;
                        }
                        else {
                            cout << "Your dodge roll was " << dodge << endl;
                            cout << "YOU FAILED YOUR DODGE YOU MUST ATTACK" << endl;
                            pMove = 1;
                        }
                    }
                    else pMove = 1;
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
                                bHealth -= 5; 
                            }
                        }
                        cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                    }
                    else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
                        cout << "YOU HIT THE MONSTER AND IT HIT YOU" << endl;
                        hit = rand()%90 + 11;
                        health -= 1;
                        if (hit >= pAttck){
                            cout << "Your critical hit roll was " << hit << endl;
                            cout << "IT WAS A CITICAL HIT" << endl;
                            bHealth -= 5;
                        }
                        else {
                            cout << "Your critical hit roll was " << hit << endl;
                            bHealth -= 3;
                        }
                        cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                    }
                    else {
                        cout << "THE MONSTER IS DAZED ! YOU ATTACK FOR FREE" << endl;
                        hit = rand()%90 + 11;
                        if (hit >= pAttck){
                            cout << "Your critical hit roll was " << hit << endl;
                            cout << "IT WAS A CITICAL HIT" << endl;
                            bHealth -= 3;
                        }
                        else {
                            cout << "Your critical hit roll was " << hit << endl;
                            bHealth -= 1;
                        }
                        cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                    }
                    if (bHealth < 0) {cout << "YOU KILLED THE BOSS" << endl;}
                    if (health < 0 ) {cout << "YOUR DIED" << endl;}
                }while (bHealth > 0 && health > 0);
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
                                cout << "Input you move (attack or dodge):"<<endl;
                                cin >> input1;
                            }while (!(input1 == "dodge") && !(input1 == "Dodge") && !(input1 == "attack") && !(input1 == "Attack"));
                            if (input1 == "dodge" || input1 == "Dodge"){
                                dodge = rand()%90 + 11;
                                if (dodge >= pAglty){
                                    cout << "Your dodge roll was " << dodge << "; enough to dodge." << endl;
                                    pMove = 0;
                                }
                                else {
                                    cout << "Your dodge roll was " << dodge << endl;
                                    cout << "YOU FAILED YOUR DODGE YOU MUST ATTACK" << endl;
                                    pMove = 1;
                                }
                            }
                            else pMove = 1;
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
                                        mHealth -= 2; 
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
                                }
                                else {
                                    cout << "Your critical hit roll was " << hit << endl;
                                    mHealth -= 1;
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
                                }
                                else {
                                    cout << "Your critical hit roll was " << hit << endl;
                                    mHealth -= 1;
                                }
                                cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                            }
                            if (mHealth < 0) {cout << "YOU KILLED THE MONSTER" << endl;}
                            if (health < 0 ) {cout << "YOUR DIED" << endl;}

                        }while (mHealth > 0 && health > 0);
                    }
                    else{
                        sneak = rand()%90 + 11;
                        if (sneak >= pLuck){
                            cout << "You snuck by." << endl;
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
        }while (health > 0 || bHealth);
    //Exit Program
    return 0;
}