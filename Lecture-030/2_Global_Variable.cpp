#include <bits/stdc++.h>
using namespace std;

int a = 100;

void func1() {
    cout << "In func1 - a : " << a << endl;
}

void func2() {
    cout << "In func2 - a : " << a << endl;
}

int main() {
    
    cout << "In main  - a : " << a << endl;

    func1();
    func2();

    return 0;
}