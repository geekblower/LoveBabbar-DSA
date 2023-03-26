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

class D : public B, public C {
    public:
    int new_child_property1;
    int new_child_property2;
};

int main() {
    D d1;
    
    d1.B::base_property1 = 50;
    d1.B::base_property2 = 55;
    d1.C::base_property1 = 60;
    d1.C::base_property2 = 65;
    d1.child1_property1 = 70;
    d1.child1_property2 = 75;
    d1.child2_property1 = 80;
    d1.child2_property2 = 85;
    d1.new_child_property1 = 90;
    d1.new_child_property2 = 95;

    cout << "d1.B::base_property1 : " << d1.B::base_property1 << endl;
    cout << "d1.B::base_property2 : " << d1.B::base_property2 << endl << endl;
    cout << "d1.C::base_property1 : " << d1.C::base_property1 << endl;
    cout << "d1.C::base_property2 : " << d1.C::base_property2 << endl << endl;
    cout << "d1.child1_propertn y1 : " << d1.child1_property1 << endl;
    cout << "d1.child1_property2 : " << d1.child1_property2 << endl << endl;
    cout << "d1.child2_property1 : " << d1.child2_property1 << endl;
    cout << "d1.child2_property2 : " << d1.child2_property2 << endl << endl;
    cout << "d1.new_child_property1 : " << d1.new_child_property1 << endl;
    cout << "d1.new_child_property2 : " << d1.new_child_property2 << endl;

    return 0;
}