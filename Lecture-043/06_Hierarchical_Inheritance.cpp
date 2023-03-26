#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child1_property1;
    int child1_property2;
};

class C : public A {
    public:
    int child2_property1;
    int child2_property2;
};

int main() {
    B b1;
    C c1;
    
    b1.base_property1 = 50;
    b1.base_property2 = 55;
    b1.child1_property1 = 60;
    b1.child1_property2 = 65;

    c1.base_property1 = 10;
    c1.base_property2 = 15;
    c1.child2_property1 = 20;
    c1.child2_property2 = 25;

    cout << "b1.base_property1 : " << b1.base_property1 << endl;
    cout << "b1.base_property2 : " << b1.base_property2 << endl << endl;
    cout << "b1.child1_property1 : " << b1.child1_property1 << endl;
    cout << "b1.child1_property2 : " << b1.child1_property2 << endl << endl;
    
    cout << "c1.base_property1 : " << c1.base_property1 << endl;
    cout << "c1.base_property2 : " << c1.base_property2 << endl << endl;
    cout << "c1.child2_property1 : " << c1.child2_property1 << endl;
    cout << "c1.child2_property2 : " << c1.child2_property2 << endl << endl;

    return 0;
}