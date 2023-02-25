#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int *p1 = &n;
    int **p2 = &p1;

    cout << "n : " << n << endl;
    cout << "&n : " << &n << endl << endl;

    cout << "p1 : " << p1 << endl;
    cout << "&p1 : " << &p1 << endl;
    cout << "*p1 : " << *p1 << endl << endl;

    cout << "p2 : " << p2 << endl;
    cout << "*p2 : " << *p2 << endl;
    cout << "&p2 : " << &p2 << endl;
    cout << "**p2 : " << **p2 << endl;

    return 0;
}