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
};

int main() {
    Hero *h1 = new Hero();
    cout << "For h1 : " << endl;
    cout << "h1->health = " << h1->health << endl;
    cout << "h1->level = " << h1->level << endl;
    cout << "h1->name = " << h1->name << endl << endl;
    
    Hero *h2 = new Hero(30);
    cout << "For h2 : " << endl;
    cout << "h2->health = " << h2->health << endl;
    cout << "h2->level = " << h2->level << endl;
    cout << "h2->name = " << h2->name << endl << endl;

    Hero *h3 = new Hero(40, 'A');
    cout << "For h3 : " << endl;
    cout << "h3->health = " << h3->health << endl;
    cout << "h3->level = " << h3->level << endl;
    cout << "h3->name = " << h3->name << endl << endl;

    Hero *h4 = new Hero(50, 'B', "Akash");
    cout << "For h4 : " << endl;
    cout << "h4->health = " << h4->health << endl;
    cout << "h4->level = " << h4->level << endl;
    cout << "h4->name = " << h4->name << endl << endl;

    return 0;
}