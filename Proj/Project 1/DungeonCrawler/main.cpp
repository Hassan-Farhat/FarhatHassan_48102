/*
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 24, 2016, 5:46 PM
 * Purpose : This is a Dungeon crawling game.
 */

#include <iostream>   //Input/Output objects
#include <fstream>    //File I/O
#include <string>     //String Library
#include <cstdlib>    //Random number
#include <ctime>      //Used to set random number seed
#include <iomanip>    //Used for in the scoreboard
#include <cmath>      //Used in calculating final score

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast <unsigned int> (time(0)));
    
    //Declaration of Variables:
    //File streaming variables:
    ifstream in;
    ofstream out;
    int rows,cols,     // Rows and Columns of the map.
        prow=7,pcol=1; // Player Row and Player Column on the map.
    string line,move;  // Line (used to display the row) and move (user input).
    //Battle Variables:
    short monMove,pMove,              //Monster's move, Player's Move.
          mHealth,bHealth=25,health,  //Monster's Health, Boss's Health, Player Health.
          crit,dodge,sneak,           //Critical hit chance, Dodge, Sneak.
          spawn;                      //Spawn chance of monsters
    string input1,input2,     //Input1 (User action in a fight), Input2 (User decision to sneak).
           countAtt,confirm,  //Counter Attack, and confirm (User decision to confirm).  
           use;               //Use (user input to use an item).
    //User skill set up:
    short agility,attck,luck,   //Agility, Attack, Luck.
          pLuck,pAglty,pAttck;  //Player Luck, Player Agility, Player Attack (These are used in the modifiers).
    //Shop Variables:
    char select;         //Select an item for purchase, (start) used to start the game
        //These are booleans used to check availability in the store.
    bool it1 = true, it2 = true, 
         it3 = true, it4 = true, 
         it5 = true, it6 = true, it7 = true;
    short eHealth, loot, coins = 10;   //Effigy health storage, loot (chance), and number of coins.
    string item4="Shield", item6="Holy Spell", item7="Bow"; //Usable items Item1, Item2, Item3.
    //Score Variables:
    short kills = 0;        //Number of monster kills.
    float points = 0.0f;    //Number of points.
    string name, start;
    
    //The Introscreen:
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
    
    //Skill Set-Up:
    do{  //Confirmation loop starts here.
        cout << "This is the skill setup tree:" << endl 
        << "Here you will decide your attributes:" << endl << endl;
        agility = 5, attck = 5, luck = 2, health = 25, //Standard point distribution.
        points = 10;                     //Number of spendable points.
        short w, x, y ,z,                //Checking/Calculation values.
              choice, remove, extra;     //Choice (selection of skill), Remove (to remove points), extra (used in calculations).            
        do{ //Skill Set-Up loop starts here
            cout << "What would you like to level up?" << endl << endl;
            cout << "Type 1 to level up attack (max 10 min 5)" << endl;
            cout << "Type 2 to level up agility (max 10 min 5)" << endl;
            cout << "Type 3 to level up health" << endl;
            cout << "Type 4 to up luck (max 10 min 2)" << endl << endl;
            cout << "You have a total of " << points << " left to add" << endl;
            cin >> choice; //Input the skill to level up.
            switch (choice){
                case 1: //Attack selected.
                    do{
                        cout << endl << "How many points would you like to add points in to Attack. Current amount : " << attck << 
                             endl << "You have " << points;
                        cout << " points to spend." << endl;
                        cin >> x; //Storage of points to add.
                    } while (x > points);   //Check to to ensure value if valid.
                    attck = attck + x;      //Add points to Attack.
                    points = points - x;    //Remove stored points from total.
                    while (attck > 10 || attck < 5){ //Checking to see if Attack is in Valid range.
                        cout << "You have " << attck << " points in attack and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in attack." << endl; 
                        if (attck > 10) { //Calculations that correct to many attack points.
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            attck = attck - remove;
                            points = points + remove;
                        }
                        else if (attck < 5){ //Calculations that correct to few attack points.
                            extra = 5 - attck;  
                            attck = 5;
                            points = points - extra;
                            cout << "Your attack was too low it has been reset to 5." << endl;
                        }
                    }   //End of Check
                    cout << endl << "You have a total of " << attck << " points in attack" << endl << endl;
                    break;
                case 2: //Agility Selected
                    do{
                        cout << "How many points would you like to add to Agility. Current amount : " << agility << endl << "You have " << points 
                             << " points to spend." << endl;
                        cin >> y;   //Storage of points to add.
                    } while (y > points);   //Check to to ensure value if valid.
                    agility = agility + y;  //Add Points to Agility.
                    points = points - y;    //Remove stored points from total.
                    while (agility > 10 || agility < 5){    //Check to see if Agility is in range.
                        cout << "You have " << agility << " points in agility and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in agility." << endl; 
                        if (agility > 10) { //Correction of too many points in Agility.
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            agility = agility - remove;
                            points = points + remove;
                        }
                        else if (agility < 5){  //Correction of too few points in Agility.
                            extra = 5 - agility;
                            agility = 5;
                            points = points - extra;
                            cout << "Your agility was too low it has been reset to 5." << endl;
                        }
                    }   //End of check
                    cout << "You have a total of " << agility << " points in agility" << endl;
                    break;
                case 3: //Health Selected
                    do{
                        cout << "How many points would you like to add to Health. Current amount : " << health << endl << "You have " 
                             << points << " points to spend." << endl;
                        cin >> z;   //Storage of points to add.
                    } while (z > points);   //Check to ensure valid number was entered.
                    health = health + z;    //Add points to Health.
                    points = points - z;    //Remove Stored points.
                    cout << "You have a total of " << health << " hit points." << endl;
                    break;
                case 4: //Luck Selected
                    do{
                        cout << "How many points would you like to add to luck. Current amount : " << luck << endl << "You have " 
                             << points << " points to spend." << endl;
                        cin >> w;   //Storage of points to add.
                    } while (w > points);   //Check to ensure valid number was entered. 
                    luck = luck + w;        //Add points to Luck.
                    points = points - w;    //Remove stored points from total.
                    while (luck > 10 || luck < 2){  //Check to see if number of points add is in the range.
                        cout << "You have " << luck << " points in luck and you cannot have more than 10 points or less" << endl 
                             << "than 5 points in luck." << endl; 
                        if (luck > 10) {    //Correction of too many points in Luck.
                            cout << "Please input how many you would like to remove?" << endl;
                            cin >> remove;
                            luck = luck - remove;
                            points = points + remove;
                        }
                        else if (luck < 2){ //Correction of too few points in Luck.
                            extra = 2 - luck;
                            luck = 2;
                            points = points - extra;
                            cout << "Your luck was too low it has been reset to 5." << endl;
                        }
                    }
                    cout << "You have a total of " << luck << " points in luck." << endl;
                    break;
            }
        }while (points > 0);  //End of Skill Set-Up loop
        //Display to skills
        cout << "Your current skill set is such:" << endl << endl;
        cout << "Attack:       " << setw(2) << attck << " Points" << endl;
        cout << "Agility:      " << setw(2) << agility << " Points" << endl;
        cout << "Luck:         " << setw(2) << luck << " Points" << endl;
        cout << "Total Health: " << setw(2) << health << " HP"<< endl << endl;
        cout << "Are you happy with this ? If so type in yes if not type in no." << endl;
        do{
            cin >> confirm;
        } while(!(confirm == "Yes") && !(confirm == "yes") && !(confirm == "No") && !(confirm == "no")); 
    } while (confirm == "No" || confirm == "no"); //End of confirmation loop
    
    //The Camp shop:
    cout << "Before you go on your journey this is the camp shop" << endl;
    cout << "Everything costs 5 coins" << endl << endl;
    do{ //The Store Loop
        //Boolean values comes into play. They decide if item is to be displayed.
        if (it1)cout << "A. Steel Sword (increase in Attack)" << endl;
        else cout << "A. Purchased" << endl;
        if (it2)cout << "B. Rabbit's Foot (increase Luck)" << endl;
        else cout << "B. Purchased" << endl;
        if (it3)cout << "C. Armor (increase Health)" << endl;
        else cout << "C. Purchased" << endl;
        if (it4)cout << "D. Shield (can be used in combat to gain HP)" << endl;
        else cout << "D. Purchased" << endl;
        if (it5)cout << "E. Human Effigy (revives player)" << endl;
        else cout << "E. Purchased" << endl;
        if (it6)cout << "F. Holy Spell (Deals damage to boss half of the time)" << endl;
        else cout << "F. Purchased" << endl;
        if (it7)cout << "G. Bow (Deal damage from a far safely)" << endl; 
        else cout << "G. Purchased" << endl;
        cout << "What would you like to purchase? " << coins << " Coins to spend" <<endl;
        cout << "Type in the capital letter before the item" << endl;
        cout << "You can leave by typing in L" << endl;
        cin >> select;  //User decides what items to be purchased.
        switch (select){
            case 'A': //Purchase/Selection of Item1
                coins = (it1)? coins-=5 : coins = coins; 
                it1 = false;break;
            case 'B': //Purchase/Selection of Item2
                coins = (it2)? coins-=5 : coins = coins;
                it2 = false;break;
            case 'C': //Purchase/Selection of Item3
                coins = (it3)? coins-=5 : coins = coins;
                it3 = false;break;
            case 'D': //Purchase/Selection of Item4
                coins = (it4)? coins-=5 : coins = coins;
                it4 = false;break;
            case 'E': //Purchase/Selection of Item5
                coins = (it5)? coins-=5 : coins = coins;
                it5 = false;break;
            case 'F': //Purchase/Selection of Item6
                coins = (it6)? coins-=5 : coins = coins;
                it6 = false;break;
            case 'G': //Purchase/Selection of Item7
                coins = (it7)? coins-=5 : coins = coins;
                it7 = false;break;
            default: cout << "You didn't input a selection" <<endl;
        }
        cout << endl;
    }while(!(coins < 5) && !(select == 'L')); //End of store loop
    
    //Modifiers:
    pAglty = 100 - (agility * 9);   
    pAttck = 100 - (attck * 5);
    pLuck = 100 - (luck * 4);
    if(it1 == false) pAttck = 100 - ((attck+1) * 5);
    if(it2 == false) pLuck = 100 - ((luck+2) * 4);
    if(it3 == false) health = health + 5;
    eHealth = health;               //Effigy stores total health
    
    //Map Construction/Movement:
    in.open("map.dat"); //Open map file
    in>>rows;           //input rows   
    
    //Display Output : Map
    getline(in,line);   
    for(int row=1;row<=rows;row++){
            getline(in,line);
            cout<<line<<endl;
    }
    
    cout << endl << "Welcome Adventurer you are currently at base camp (C on the map)" << endl;
    cout << "To win beat the boss (B on the map), GOOD LUCK." << endl;
    cout << "To start type in up!" << endl;
    
    //Player input for movement 
    do{ //Main Loop
        //Player inputs direction of movement.
        cout<<"Input the direction of your turn (up,left,right)"<<endl;
        cin>>move;
        //Determine player location on map
        if (move == "up" || move == "Up") prow -= 1;
        else if (move == "right" || move == "Right") pcol += 1;
        else if (move == "left" || move == "Left") pcol -= 1;

        //Clear the screen for next map
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl << endl << endl << endl << endl << endl << endl;

        //Read back in the file
        in.close();
        in.clear();

        //Input values and open map file
        in.open("map.dat");
        in>>rows;

        //Display Player movement on map and read into the Player(map) file
        out.open("player.dat"); //Open player file
        getline(in,line);
        for(int row = 1;row <= rows;row++){ //Construction of map
            getline(in,line);
            if(row == prow && (line[pcol] == 'O')){ //Movement validity check
                line[pcol]='P';
            }
            else if (row == prow && line[pcol] == 'X'){  //Movement validity check
                if (move == "up" || move == "Up") prow += 1;
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
        
    //Spawn Chance:
        spawn = rand()%9 + 1;
        
    //Battle sequences:
        //Boss Spawns
        if (prow == 1 && pcol == 4){ //Player is in the last room, Boss will spawn
            //Shop before the boss:
            cout << "You see a looming door in front of you." << endl;
            cout << "There is also a lost merchant.";
            cout << "He does not look human." << endl;
            cout << "He asks if you see anything you like." << endl;
            if (coins >= 5){ //if player has 5 or more coins
                do{ //Shop Loop
                    cout << "Everything costs 5 coins" << endl;
                    cout << "You have" << coins << "coins" << endl;
                    if (it4)cout << "A. Shield" << endl;
                    else cout << "A. Purchased" << endl;
                    if (it5)cout << "B. Human Effigy" << endl;
                    else cout << "B. Purchased" << endl;
                    if (it6)cout << "C. Holy Spell" << endl;
                    else cout << "C. Purchased" << endl;
                    if (it7)cout << "D. Bow" << endl; 
                    else cout << "D. Purchased" << endl;
                    cout << "What would you like to purchase? " << coins << " Coins to spend";
                    cout << endl << "Type in the letter before the item" << endl;
                    cin >> select;
                    switch (select){
                        case 'A': //Purchase/Selection of item4
                            coins = (it4)? coins-=5 : coins = coins; 
                            it4 = false;break;
                        case 'B': //Purchase/Selection of item5
                            coins = (it5)? coins-=5 : coins = coins;
                            it5 = false;break;
                        case 'C': //Purchase/Selection of item6
                            coins = (it6)? coins-=5 : coins = coins;
                            it6 = false;break;
                        case 'D': //Purchase/Selection of item7
                            coins = (it7)? coins-=5 : coins = coins;
                            it7 = false;break;
                        default: cout << "You didn't input a valid selection"<<endl;
                    }
                }while(!(coins < 5) && !(select == 'L')); //End of shop loop
            }
            else { //If player cannot afford to purchase anything
                cout << "He scoffs at your lack or funds" << endl;
            }
            
            //Clear the Screen
            cout << endl << endl << endl << endl << endl << endl << endl <<endl;
            
            cout << "You open the doors and there stands a 7 foot tall Knight.";
            cout << endl << "He raises his sword and you prepare yourself." << endl;
            cout << "You only have 8 turns to kill this boss" << endl;
            
            //Boss fight:
            for (int turns = 1; (turns <= 8) && (health > 0) && (bHealth > 0); turns++){
                cout << "Turn :" << turns << endl;
                do {
                    cout << "Input you move (attack, dodge, inventory):"<<endl;
                    cin >> input1;  //Player inputs their move
                    cout << endl;
                }while (!(input1 == "dodge") && !(input1 == "attack") && !(input1 == "inventory"));
                
                //Player accesses inventory
                if (input1 == "inventory"){
                    if(it4 == true && it6 == true && it7 == true) {
                        cout << "You have no items" << endl;
                    }
                    else { //If player has items
                        cout << "Input the name exactly of the item you would like to use" << endl;
                        cout << "If you don't want to use any item type in leave" << endl;
                        if (it4 == false)cout << item4 << endl;
                        if (it6 == false)cout << item6 << endl;
                        if (it7 == false)cout << item7 << endl;
                        do{ 
                            getline(cin,use);   //Player inputs what item they wish to use
                        }while (!(use == item4) && !(use == item6) && !(use == item7) && !(use == "leave"));
                        //Use the item the player choose
                        if((it4 == false) && (use == item4)){
                            it4 = true;
                            cout << "You gain 3 more hit-points" << endl;
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
                    } //Close inventory
                    do {
                        cout << "Input you move (attack, dodge):"<<endl;
                        cin >> input1;  //Player inputs their move
                        cin.clear();
                        cin.ignore();
                    }while (!(input1 == "dodge") && !(input1 == "attack"));
                } 
                //User choose to dodge
                if (input1 == "dodge"){
                    dodge = rand()%90 + 11;
                    if (dodge >= pAglty){ //Dodge was successful
                        cout << "Your dodge roll was " << dodge << "; enough to dodge!" << endl;
                        points = points + 0.3;
                        pMove = 0;
                    }
                    else {  //Dodge failed
                        cout << "Your dodge roll was " << dodge << endl;
                        cout << "YOU FAILED YOUR DODGE YOU MUST ATTACK" << endl;
                        pMove = 1;
                    }
                }
                //User choose to attack
                else{
                    pMove = 1;
                }
                //Bosses move:
                monMove = rand()%9 + 1;
                int mMove = monMove%4;
                //Processing of moves in relation to one another:
                //Successful Dodge:
                if ( (mMove == 1 || mMove == 2 || mMove == 3) && pMove == 0){
                    cout << "YOU DODGED !" << endl;
                    cout << "DO YOU WANT TO TRY TO ATTACK ? (This is risky) (enter yes to attack)" << endl;
                    cin >> countAtt;
                    if (countAtt == "Yes" || countAtt == "yes") {
                        int cAtt = rand()%90 + 11;   //Player counter attack
                        int cMAtt = rand()%90 + 11;  //Monster counter attack
                        //Determine if player counter attack hit:
                        if (cAtt <= 50 && cMAtt >= 50){
                            cout << "YOUR COUNTER ATTACK FAILED AND YOU WERE HIT" << endl;
                            health -= 5;
                        }
                        else if (cAtt <= 50 && cMAtt <= 50){
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
                //Both the boss and player attack
                else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
                    cout << "YOU HIT THE BOSS AND IT HIT YOU" << endl;
                    crit = rand()%90 + 11;
                    health -= 3;
                    if (crit >= pAttck){ //Check for critical hit
                        cout << "Your critical hit roll was " << crit << endl;
                        cout << "IT WAS A CITICAL HIT" << endl;
                        bHealth -= 5;
                        points += 2;
                    }
                    else {
                        cout << "Your critical hit roll was " << crit << endl;
                        bHealth -= 3;
                        points += 1;
                    }
                    cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                }
                //Dazed boss (free attack):
                else {
                    cout << "THE BOSS IS DAZED ! YOU ATTACK FOR FREE" << endl;
                    crit = rand()%90 + 11;
                    if (crit >= pAttck){ //Check for critical hit
                        cout << "Your critical hit roll was " << crit << endl;
                        cout << "IT WAS A CITICAL HIT" << endl;
                        bHealth -= 3;
                        points += 2;
                    }
                    else {
                        cout << "Your critical hit roll was " << crit << endl;
                        bHealth -= 2;
                        points += 1;
                    }
                    cout << endl << "Your health = " << health << endl << "Boss's health = " << bHealth << endl;
                }
                //Boss has been slain
                if (bHealth <= 0) { 
                    cout << "YOU KILLED THE BOSS" << endl;
                    points += 100;
                }
                //Player was slain with effigy
                if (it5 == false && health <= 0){
                    cout << "Your human effigy shudders" << endl;
                    cout << "Your health is refilled" << endl;
                    health = eHealth;   //Reset player health
                    it5 = true;         //Reset effigy
                }
                //Player was slain without effigy
                if (health <= 0) cout << "YOU ARE DEAD" << endl;
                //If you ran out of number of turns:
                if (turns > 8) {
                    health = 0;
                    cout << "The boss uses his ultimate and you die" << endl;
                }
            } 
        }//Boss fight ends here
        //Monster (normal) fight:
        else { 
            if (spawn <=6){  //Monster has spawned
                mHealth = 3;  //Monster health is set to 3 hp
                cout << "MONSTER HAS SPAWNED PREPARE" << endl;
                do{
                    cout << "You do you want to engage or sneak : " << endl;
                    cin >> input2;     //Player decides to sneak or engage  
                }while(!(input2 == "engage") && !(input2 == "Engage") && !(input2 == "sneak") && !(input2 == "Sneak"));
                //Player input sneak:
                if (input2 == "sneak" || input2 == "Sneak"){
                    sneak = rand()%90 + 11;
                    if (sneak >= pLuck){ //Sneak was successful
                        cout << "You snuck by." << endl;
                        points += 1.8;
                    }
                    else {  //Sneak was no successful
                        cout << "You alerted the monster." << endl;
                        input2 = "engage";
                    }
                }
                if (input2 == "engage" || input2 == "Engage"){ //Player choose to engage
                    do{ //Start of battle
                        do {
                            cout << "Input you move (attack, dodge, inventory):"<<endl;
                            cin >> input1; //Player inputs their move
                            cout << endl;
                        }while (!(input1 == "dodge") && !(input1 == "attack") && !(input1 == "inventory"));
                        //Player accessed their inventory:
                        if (input1 == "inventory"){
                            if(it4 == true && it6 == true && it7 == true) {
                                cout << "You have no items" << endl;
                            }
                            else{ //If player has items
                                cout << "Input the name of the item you would like to use" << endl;
                                cout << "If you don't want to use any item type in leave" << endl;
                                if (it4 == false)cout << item4 << endl;
                                if (it6 == false)cout << item6 << endl;
                                if (it7 == false)cout << item7 << endl;
                                do{ 
                                    getline(cin,use); //Player inputs what item they wish to use
                                }while (!(use == item4) && !(use == item6) && !(use == item7) && !(use == "leave"));
                                //Use the item the player choose:
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
                            } //Close inventory
                            do {
                                cout << "Input you move (attack, dodge):"<<endl;
                                cin >> input1;  //Player inputs their move
                                cin.clear();
                                cin.ignore();
                            }while (!(input1 == "dodge") && !(input1 == "attack"));
                        }   
                        //Player choose to dodge:
                        if(input1 == "dodge"){
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
                        //Player choose to attack:
                        else{
                            pMove = 1;
                        }
                        //Monsters move:
                        monMove = rand()%9 + 1;
                        int mMove = monMove%4;
                        //Processing of moves in relation to one another:
                        //Successful Dodge:
                        if ( (mMove == 1 || mMove == 2 || mMove == 3) && pMove == 0){
                            cout << "YOU DODGED !" << endl;
                            cout << "DO YOU WANT TO TRY TO ATTACK ? (This is risky) (enter yes to attack)" << endl;
                            cin >> countAtt;
                            if (countAtt == "Yes" || countAtt == "yes") {
                                int cAtt = rand()%90 + 11;  //Player counter attack
                                int cMAtt = rand()%90 + 11; //Monster counter attack
                                //Determine if player counter attack hit:
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
                        //You and the monster both attack    
                        else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
                            cout << "YOU HIT THE MONSTER AND IT HIT YOU" << endl;
                            crit = rand()%90 + 11;
                            health -= 1;
                            if (crit >= pAttck){ //Check for critical hit
                                cout << "Your critical hit roll was " << crit << endl;
                                cout << "IT WAS A CITICAL HIT" << endl;
                                mHealth -= 3;
                                points += 2;
                            }
                            else {
                                cout << "Your critical hit roll was " << crit << endl;
                                mHealth -= 1;
                                points += 1;
                            }
                            cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                        }
                        //The monster is dazed (free attack)
                        else {
                            cout << "THE MONSTER IS DAZED ! YOU ATTACK FOR FREE" << endl;
                            crit = rand()%90 + 11;
                            if (crit >= pAttck){ //Check for critical hit
                                cout << "Your critical hit roll was " << crit << endl;
                                cout << "IT WAS A CITICAL HIT" << endl;
                                mHealth -= 3;
                                points += 2;
                            }
                            else {
                                cout << "Your critical hit roll was " << crit << endl;
                                mHealth -= 1;
                                points += 1;
                            }
                            cout << endl << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
                        }
                        //Player dies but has effigy
                        if (it5 == false && health == 0){
                            cout << "Your human effigy shudders" << endl;
                            cout << "Your health is refilled" << endl;
                            health = eHealth;
                            it5 = true;
                        }
                        //Monster is slain
                        if (mHealth <= 0){
                            short cLoot = 0; //Number of coins you loot
                            cout << "YOU KILLED THE MONSTER" << endl;
                            loot = rand()%90 + 11;
                            coins = (loot >= pLuck)? coins+=3,cLoot = 3: coins+=2, cLoot = 2;
                            cout << "You looted " << cLoot 
                                    << " coins" << endl;
                            points += 8.3;
                            kills += 1;
                        }
                        //Player dies with no effigy
                        if (health <= 0 ) cout << "YOU ARE DEAD" << endl;
                    }while (mHealth > 0 && health > 0); //End of battle loop
                }
            }
            else{
                cout << "YOU ARE CLEAR KEEP MOVING" << endl;
            }
        }
        //Close the file
        in.close();
        out.close();
    }while (health > 0 && bHealth > 0); //End of main loop
    
    //Display score board:
    if (health > 0 && bHealth < 0) {
        cin.ignore();
        cout << "YOU WON CONGRADULATIONS" << endl;
        cout << "Enter your name for the score board: ";
        getline(cin,name);
        cout << endl << endl << endl << endl << endl << endl << endl <<endl;
        cout << endl << endl << endl << endl << endl << endl << endl <<endl;
        cout << endl << endl << endl << endl << endl << endl << endl <<endl;
        cout << endl << endl << endl << endl << endl << endl << endl <<endl;

        cout << name << " is the winner" << endl;
        cout << setprecision(2) << fixed << endl;
        cout << name <<"'s skills were: " << endl;
        cout << "Attack:       " << setw(2) << attck << " Points" << endl;
        cout << "Agility:      " << setw(2) << agility << " Points" << endl;
        cout << "Luck:         " << setw(2) << luck << " Points" << endl;
        cout << "Total Health: " << setw(2) << health << endl << endl;
        cout << name << " had :" << setw(2) << kills << " monster kills" << endl;
        cout << name << " had a final score of " << setw(2) << sqrt(points) << " points" << endl;
    }
    else {
        cout << "You lost" << endl;
    }
    
    //Exit Program
    return 0;
}