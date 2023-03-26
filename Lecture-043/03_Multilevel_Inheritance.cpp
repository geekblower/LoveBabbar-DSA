#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int base_property1;
    int base_property2;
};

class B : public A {
    public:
    int child_property1;
    int child_property2;
};

class C : public B {
    public:
    int new_child_property1;
    int new_child_property2;
};

int main() {
    C c1;
    
    c1.base_property1 = 10;
    c1.base_property2 = 15;
    c1.child_property1 = 20;
    c1.child_property2 = 25;
    c1.new_child_property1 = 30;
    c1.new_child_property2 = 35;

    cout << "c1.base_property1 : " << c1.base_property1 << endl;
    cout << "c1.base_property2 : " << c1.base_property2 << endl << endl;
    cout << "c1.child_property1 : " << c1.child_property1 << endl;
    cout << "c1.child_property2 : " << c1.child_property2 << endl << endl;
    cout << "c1.new_child_property1 : " << c1.new_child_property1 << endl;
    cout << "c1.new_child_property2 : " << c1.new_child_property2 << endl;

    return 0;
}