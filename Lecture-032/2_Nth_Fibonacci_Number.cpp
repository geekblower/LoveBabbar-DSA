#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n <= 2) {
        return n-1;
    }

    return fib(n-1) + fib(n-2);
}

int main() {
    int n;

    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Nth fibonacci number : " << fib(n) << endl;

    return 0;
}