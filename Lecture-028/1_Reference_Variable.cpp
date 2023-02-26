#include <bits/stdc++.h>
using namespace std;

void update1(int j) {
    j++;
}

void update2(int &j) {
    j++;
}

int main() {
    int i = 5;

    int &j = i;

    cout << i << endl;
    update1(i);
    cout << i << endl;
    update2(i);
    cout << i << endl;

    return 0;
}