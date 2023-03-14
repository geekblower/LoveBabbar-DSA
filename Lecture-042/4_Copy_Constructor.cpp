#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        string name;
        int health;
        char level;

        Hero() {
        }

        Hero(int health) {
            this->health = health;
        }

        Hero(int health, char level) {
            this->health = health;
            this->level = level;
        }

        Hero(int health, char level, string name) {
            this->health = health;
            this->level = level;
            this->name = name;
        }

        Hero(Hero &temp) {
            this->health = temp.health;
            this->level = temp.level;
            this->name = temp.name;
        }

        void print() {
            cout << "[Name : " << this->name << " , Health : ";
            cout << this->health << " , Level : " << this->level << "]" << endl;
        }
};

int main() {
    Hero *h1 = new Hero(80, 'A', "Akash");
    cout << "For h1 : ";
    h1->print();
    
    Hero *h2 = new Hero(*h1);
    cout << "For h2 : ";
    h2->print();

    Hero h3(*h2);
    cout << "For h3 : ";
    h3.print();

    return 0;
}