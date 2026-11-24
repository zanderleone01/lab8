/////////////////////////////////////////////////////////////////////
// Name: Gilbert Almanza + Zander Leone
// Date: 11/24/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Holds class members, and member funtion
//                      prototypes.
/////////////////////////////////////////////////////////////////////

#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H
using namespace std;

class Monster {
private:
    string name;
    int health;
    
public:
    Monster();
    Monster(string newName);
    
    void attack(string p2Name, int dam);
    void healing(int heal);
    void checkStats() const;
    
    string getName() const;
    void setName(string newName);
    int getHealth() const;
    void setHealth(int newHealth);
};
    
#endif