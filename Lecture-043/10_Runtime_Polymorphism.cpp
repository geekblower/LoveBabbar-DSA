#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    void func() {
        cout << "Inside Parent Class" << endl;
    }
};

class B : public A {
    public:
    void func() {
        cout << "Inside Child Class" << endl;
    }
};

int main() {
    A obj1;
    B obj2;

    obj1.func();
    obj2.func();

    return 0;
}