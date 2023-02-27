#include <bits/stdc++.h>
using namespace std;

inline int getMax(int a, int b) {return (a>b) ? a : b;}

int main() {
    int a, b;

    cout << "Enter the value of a & b : ";
    cin >> a >> b;

    cout << "Maximum number : " << getMax(a, b) << endl;
    return 0;
}