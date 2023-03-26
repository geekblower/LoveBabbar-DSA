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

int main() {
    B b1;
    
    b1.base_property1 = 10;
    b1.base_property2 = 15;
    b1.child_property1 = 20;
    b1.child_property2 = 25;

    cout << "b1.base_property1 : " << b1.base_property1 << endl;
    cout << "b1.base_property2 : " << b1.base_property2 << endl;
    cout << "b1.child_property1 : " << b1.child_property1 << endl;
    cout << "b1.child_property2 : " << b1.child_property2 << endl;

    return 0;
}