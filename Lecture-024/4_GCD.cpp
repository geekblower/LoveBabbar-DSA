#include <bits/stdc++.h>
using namespace std;

// Euclid's Algorithm
// gcd(a,b) = gcd(a-b,b)
// gcd(a,b) = gcd(a%b,b)
/*
int gcd(int n1, int n2) {
    int a=n1, b=n2;
    if(n1<n2) {
        swap(a, b);
    }

    while(a && b) {
        a %= b;
        swap(a, b);
    }

    return (a) ? a : b;
}
*/

int gcd(int n1, int n2) {
    if(n1 == 0) {
        return n2;
    }

    if(n2 == 0) {
        return n1;
    }

    while(n1 != n2) {
        if(n1 > n2) {
            n1 -= n2;
        } else {
            n2 -= n1;
        }
    }

    return n1;
}

int main() {
    int num1, num2;

    cout << "Enter the numbers : ";
    cin >> num1 >> num2;

    cout << "GCD : " << gcd(num1, num2) << endl;

    return 0;
}