#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        string name;
        int health;
        char level;

        static int time;

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

        static int random() {
            return time;
        }
};

int Hero::time = 10;

int main() {

    cout << "Hero::time -> " << Hero::time << endl;

    cout << "Hero::random() -> " << Hero::random() << endl;

    return 0;
}