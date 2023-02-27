#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    // Base case
    if(n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

int main() {
    int num;

    cout << "Enter the number : ";
    cin >> num;

    cout << "Factorial of " << num << " : " << factorial(num) << endl;

    return 0;
}