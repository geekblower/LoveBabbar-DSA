#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        string name;
        int health;
        char level;

        Hero() {
            cout << "\tConstructor Called !" << endl;
        }

        Hero(int health) {
            cout << "\tConstructor Called !" << endl;
            this->health = health;
        }

        Hero(int health, char level) {
            cout << "\tConstructor Called !" << endl;
            this->health = health;
            this->level = level;
        }

        Hero(int health, char level, string name) {
            cout << "\tConstructor Called !" << endl;
            this->health = health;
            this->level = level;
            this->name = name;
        }

        ~Hero() {
            cout << "\tDestructor Called !" << endl;
        }

        void print() {
            cout << "[Name : " << this->name << " , Health : ";
            cout << this->health << " , level : " << this->level;
            cout << "]" << endl;
        }
};

int main() {

    // Dynamic Allocation
    Hero *h1 = new Hero(150, 'A', "Akash");
    h1->print();
    delete h1;      // Calling destructor manually

    cout << endl;

    // Static Allocation
    Hero h2(250, 'G', "Gautam");
    h2.print();
    // Destructor called automatically

    return 0;
}