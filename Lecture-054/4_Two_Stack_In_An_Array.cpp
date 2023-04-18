#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    public:
    int *arr;
    int limit1, limit2, maxSize;

    TwoStack(int size) {
        maxSize = size;
        arr = new int[size];
        limit1 = -1;
        limit2 = size;
    }

    // Insertion for Stack1 : Left to Right
    void push1(int data) {
        if(limit2-limit1 > 1) {
            limit1++;
            arr[limit1] = data;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }
    
    // Insertion for Stack2 : Right to Left
    void push2(int data) {
        if(limit2-limit1 > 1) {
            limit2--;
            arr[limit2] = data;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    void pop1() {
        if(limit1 == -1) {
            cout << "Stack underflow!" << endl;
        } else {
            limit1--;
        }
    }

    void pop2() {
        if(limit2 == maxSize) {
            cout << "Stack underflow!" << endl;
        } else {
            limit2++;
        }
    }
};

int main() {
    // Creation of stack
    TwoStack s(5);

    s.push1(23);
    s.push2(65);

    s.push1(94);
    s.push1(11);
    s.push1(32);

    s.pop2();
    s.pop1();
    s.pop1();

    return 0;
}