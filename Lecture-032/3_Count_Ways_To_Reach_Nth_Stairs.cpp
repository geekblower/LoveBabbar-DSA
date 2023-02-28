#include <bits/stdc++.h>
using namespace std;

int distinctWays(int stairs) {
    if(stairs < 0) {
        return 0;
    }

    if(stairs == 0) {
        return 1;
    }

    return distinctWays(stairs-1) + distinctWays(stairs-2);
}

int main() {
    int stairs;

    cout << "Enter the number of stairs : ";
    cin >> stairs;

    int ways = distinctWays(stairs);

    cout << "Total number of distinct ways : " << ways << endl;

    return 0;
}