/////////////////////////////////////////////////////////////////////
// Name: Gilbert Almanza + Zander Leone
// Date: 11/24/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Holds objects funtions, such as constructors,
//                      getters, setters, etc.
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "monsterbattle.h"
using namespace std;


Monster:: Monster(){
    name = "";
    health = 100;
}
Monster:: Monster(string newName){
    name = newName;
    health = 100;
}
    
void Monster:: attack(string p2Name, int dam) {
    cout << name << " dealt " << dam << " damage to " << p2Name << "!" << endl << endl;
}
void Monster:: healing(int heal) {
    cout << name << " restores " << heal << " health!" << endl << endl;
}
void Monster:: checkStats() const{
    cout << "Monster name: " << name << endl;
    cout << "Monster health: " << health << endl;
}

string Monster:: getName() const {
    return name;
}
void Monster:: setName(string newName) {
    name = newName;
}
    
int Monster:: getHealth() const {
    return health;
}
void Monster:: setHealth(int newHealth) {
    health = newHealth;
}