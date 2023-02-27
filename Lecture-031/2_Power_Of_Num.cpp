#include <bits/stdc++.h>
using namespace std;

int power(int num, int pow) {
    // Base case
    if(pow == 0) {
        return 1;
    }

    return num * power(num, pow-1);
}

int main() {
    int num, pow;

    cout << "Enter the number and its power : ";
    cin >> num >> pow;

    cout << num << "^" << pow << " : " << power(num, pow) << endl;
    
    return 0;
}