#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 5;

    cout << num << endl;

    // address of Operator
    cout << "Address of num : " << &num << endl;

    int *p1 = &num;
    cout << "Address stored at p1 : " << p1 << endl;
    cout << "Value at the address stored pointed by p1 : " << *p1 << endl;
    cout << "Size of p1 : " << sizeof(p1) << endl << endl;

    char ch = 'a';
    char *p2 = &ch;
    cout << "Address stored at p2 : " << p2 << endl;
    cout << "Value at the address stored pointed by p2 : " << *p2 << endl;
    cout << "Size of p2 : " << sizeof(p2) << endl << endl;

    float f = 1.3;
    float *p3 = &f;
    cout << "Address stored at p3 : " << p3 << endl;
    cout << "Value at the address stored pointed by p3 : " << *p3 << endl;
    cout << "Size of p3 : " << sizeof(p3) << endl << endl;

    double d = 5.1254;
    double *p4 = &d;
    cout << "Address stored at p4 : " << p4 << endl;
    cout << "Value at the address stored pointed by p4 : " << *p4 << endl;
    cout << "Size of p4 : " << sizeof(p4) << endl << endl;

    bool b = true;
    bool *p5 = &b;
    cout << "Address stored at p5 : " << p5 << endl;
    cout << "Value at the address stored pointed by p5 : " << *p5 << endl;
    cout << "Size of p5 : " << sizeof(p5) << endl << endl;

    // Copying a pointer
    int *p6 = p1;
    cout << "Address stored at p6 : " << p6 << endl;
    cout << "Value at the address stored pointed by p6 : " << *p6 << endl;
    cout << "Size of p6 : " << sizeof(p6) << endl; 

    return 0;
}