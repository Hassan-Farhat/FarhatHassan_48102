/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Hassan
 *
 * Created on October 16, 2016, 4:55 PM
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string confirm;
    do{
        cout << "This is the skill setup tree:" << endl << "Here you will decide your what your character is best at" << endl << endl;
        int agility = 5, attck = 5, luck = 2, health = 25, pLuck, pAglty, pAttck, points = 10;
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
    

    return 0;
}

