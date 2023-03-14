#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        char *name;
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

        Hero(int health, char level, char *name) {
            this->health = health;
            this->level = level;
            this->name = name;
        }

        // Hero(Hero &temp) {
        //     this->health = temp.health;
        //     this->level = temp.level;
        //     this->name = temp.name;
        // }

        void print() {
            cout << "[Name : " << this->name << " , Health : ";
            cout << this->health << " , Level : " << this->level << "]" << endl;
        }
};

int main() {
    // cout << "Hello";
    Hero h1(80, 'A');
    char temp[6] = "Akash";
    strcpy(h1.name, temp);
    cout << "h1 before update : ";
    h1.print();
    
    Hero h2(h1);
    cout << "h2 before update : ";
    h2.print();
// cout << h1.name[0]
    h1.name[0] = 'B';
    
    cout << "h1 after update : ";
    h1.print();
    cout << "h2 after update : ";
    h2.print();

    return 0;
}