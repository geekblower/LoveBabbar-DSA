#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }

    for(int i=2; i<=n/2; i++) {
        if(n%i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;

    cout << "Enter the number : ";
    cin >> num;

    if(isPrime(num)) {
        cout << "Prime!" << endl;
    } else {
        cout << "Not Prime!" << endl;
    }

    return 0;
}