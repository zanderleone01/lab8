/////////////////////////////////////////////////////////////////////
// Name: Gilbert Almanza + Zander Leone
// Date: 11/24/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Two players can name and battle monsters,
//                      using objects for funtions such as attacks,
//                      healing, checking stats, etc.
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "monsterbattle.h"
using namespace std;


void printMenu1(int playNum) {
    cout << "Please select an option Player " << playNum <<":" << endl;
    cout << " (1) Name your monster" << endl;
    cout << " (2) Forfiet" << endl;
    cout << endl << "Enter your choice: ";
}
void printMenu2(int playNum){
    cout << "What's your move Player " << playNum <<"? Enter a number:" << endl;
    cout << " (1) Attack Opponent" << endl;
    cout << " (2) Heal Self" << endl;
    cout << " (3) Check Stats" << endl;
    cout << " (4) Change Monster Name" << endl;
    cout << " (5) Forfiet" << endl;
    cout << endl << "Enter your choice: ";
}

void processInput(Monster& p1Mon, Monster& p2Mon, int menuInput) {
    int healthMod = 0;
    string newName = "";
    
    if (menuInput == 1) {
        cout << "Enter damage dealt: ";
        cin >> healthMod;
        if (healthMod < 0) {
            healthMod = 0;
        }
        p1Mon.attack(p2Mon.getName(), healthMod);
        p2Mon.setHealth(p2Mon.getHealth() - healthMod);
    }
    else if (menuInput == 2) {
        cout << "Enter health restored: ";
        cin >> healthMod;
        if (healthMod < 0) {
            healthMod = 0;
        }
        p1Mon.healing(healthMod);
        p1Mon.setHealth(p1Mon.getHealth() + healthMod);
        
    }
    else if (menuInput == 3){
        cout << endl << "These are your current stats: " << endl;
        p1Mon.checkStats();
        cout << endl << "These are the opponent's current stats: " << endl;
        p2Mon.checkStats();
        cout << endl;
    }
    else if (menuInput == 4){
        cout << "Enter the new name you would like: ";
        cin >> newName;
        p1Mon.setName(newName);
        cout << "Ok! Your monster's new name is now: " << p1Mon.getName() << endl << endl;
    }
    else {
        p1Mon.setHealth(0);
    }
}


int main()
{
    string inputName = "";
    int menuInput = 0;
    Monster p1Mon(inputName);
    Monster p2Mon(inputName);
    
    cout << "Welcome to Monster Battle!" << endl;
    
    printMenu1(1);
    cin >> menuInput;
    if (menuInput == 1) {
        cout << "Enter P1's Monster's name: ";
        cin >> inputName;
        p1Mon.setName(inputName);
    }
    else {
        p1Mon.setHealth(0);
    }
    
    if (p1Mon.getHealth() > 0) {
        cout << endl; 
        printMenu1(2);
        cin >> menuInput;
        if (menuInput == 1) {
            cout << "Enter P2's Monster's name: ";
            cin >> inputName;
            p2Mon.setName(inputName);
        }
        else {
            p2Mon.setHealth(0);
        }
    }
    
    if (p1Mon.getHealth() > 0 && p2Mon.getHealth() > 0){
        cout << endl << p1Mon.getName() << " vs. " << p2Mon.getName() << endl << endl;
    }
    
    while (p1Mon.getHealth() > 0 && p2Mon.getHealth() > 0) {
        printMenu2(1);
        cin >> menuInput;
        processInput(p1Mon, p2Mon, menuInput);
        
        if (p2Mon.getHealth() > 0 && p1Mon.getHealth() > 0) {
            printMenu2(2);
            cin >> menuInput;
            processInput(p2Mon, p1Mon, menuInput);
        }
    }
    
    
    if (p1Mon.getHealth() > p2Mon.getHealth()) {
        cout << endl << "Congrats! Player 1 wins!" << endl;
    }
    else {
        cout << endl << "Congrats! Player 2 wins!" << endl;
    }

    return 0;
}