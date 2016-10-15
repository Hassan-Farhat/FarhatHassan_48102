/* 
 * File:   main.cpp
 * Author: Hassan Farhat
 * Created on October 15, 2016, 1:19 PM
 * Purpose : Battle test 
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//User libraries

//Global Constants

//Functional Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Seed random number:
    srand(static_cast <unsigned int> (time(0)));
    
    //Declare variables:
    int monMove, pMove, health=15, mHealth = 3, hit;  
    int agility = 5, attck = 5, pAglty, pAttck, points = 4; 
    string input, countAtt;
    
    //Character skill creation:
    do {
        int x, y;
        do{
            cout << "Would you like to add points in to Attack." << endl << "You have " << points << " points to spend." << endl;
            cin >> x;
        } while (x > points);
        attck = attck + x;
        points = points - x;
        if (points > 0){
            do{
                cout << "Would you like to add points in to Agility." << endl << "You have " << points << " points to spend." << endl;
                cin >> y;
            } while (y > points);
            agility = agility + y;
            points = points - y;
        }
        
        if (points == 0){
            cout << "OUT OF POINTS" << endl;
        }
    } while (points > 0);
    
    //Battle:
    do{
        cout << "Input you move (attack or dodge):"<<endl;
        cin >> input;
        if (input == "dodge"){ pMove = 0;
        }
        else pMove = 1;
        monMove = rand()%9 + 1;
        int mMove = monMove%4;
        if ( (mMove == 1 || mMove == 2 || mMove == 3) && pMove == 0){
            cout << "YOU DODGED !" << endl;
            cout << "DO YOU WANT TO TRY TO ATTACK ? (This is risky) (yes or no)" << endl;
            cin >> countAtt;
            if (countAtt == "Yes" || countAtt == "yes") {
                int cAtt = rand()%90 + 11;
                int cMAtt = rand()%90 + 11;
                if (cAtt <= 40 && cMAtt >= 50){
                    cout << "YOUR COUNTER ATTACK FAILED AND YOU WERE HIT" << endl;
                    health -= 3;
                }
                else if (cAtt <= 40 && cMAtt <= 50){
                    cout << "YOUR COUNTER ATTACK FAILED BUT YOU WERE NOT HIT" << endl;
                }
                else{
                    cout << "YOUR COUNTER ATTACK HIT" << endl;
                    mHealth -= 2; 
                }
            }
            cout << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
        }
        else if ((mMove == 1 || mMove == 2 || mMove == 3) && pMove == 1){
            cout << "YOU HIT THE MONSTER AND IT HIT YOU" << endl;
            hit = rand()%90 + 11;
            health -= 2;
            if (hit >= 80){
                cout << "IT WAS A CITICAL HIT" << endl;
                mHealth -= 3;
            }
            else {
                mHealth -= 1;
            }
            cout << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
        }
        else {
            cout << "THE MONSTER IS DAZED ! YOU ATTACK FOR FREE" << endl;
            hit = rand()%90 + 11;
            if (hit >= 80){
                cout << "IT WAS A CITICAL HIT" << endl;
                mHealth -= 3;
            }
            else {
                mHealth -= 1;
            }
            cout << "Your health = " << health << endl << "Monster's health = " << mHealth << endl;
        }
        }while (mHealth > 0 && health > 0);
    return 0;
}

