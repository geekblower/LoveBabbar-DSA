#include <bits/stdc++.h>
using namespace std;

class Human {
    public:
    int height;
    int weight;
    int age;
};

class Male : public Human {

};

class Female : protected Human {

};

int main() {
    Male m;

    cout << "m.height : " << m.height << endl;
    cout << "m.weight : " << m.weight << endl;
    cout << "m.age : " << m.age << endl;

    Female f;
    // Not possible
    // cout << "f.height : " << f.height << endl;
    // cout << "f.weight : " << f.weight << endl;
    // cout << "f.age : " << f.age << endl;

    return 0;
}