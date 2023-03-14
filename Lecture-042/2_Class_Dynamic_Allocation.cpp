#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
        string name;
        int health;
        char level;
};

int main() {
    Hero *h1 = new Hero;
    
    h1->name = "Akash Gautam";
    h1->health = 100;
    h1->level  = 'A';

    cout << "h1->name : " << h1->name << endl;
    cout << "h1->health : " << h1->health << endl;
    cout << "h1->level : " << h1->level << endl;

    return 0;
}