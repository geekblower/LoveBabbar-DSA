#include <bits/stdc++.h>
using namespace std;

void headCounting(int num) {
    // Base case
    if(num == 0) {
        return;
    }

    // Recursive relation
    headCounting(num-1);

    // Processing
    cout << num << " ";
}

void tailCounting(int num) {
    // Base case
    if(num == 0) {
        return;
    }

    // Processing
    cout << num << " ";

    // Recursive relation
    tailCounting(num-1);
}

int fib(int num) {
    if(num <= 2) {
        return num-1;
    }

    int ans = fib(num-1) + fib(num-2);
    cout << ans << " ";

    return ans;
}

int main() {
    int num;

    cout << "Enter the number : ";
    cin >> num;

    cout << "Head Counting : ";
    headCounting(num);
    cout << endl;

    cout << "Tail Counting : ";
    tailCounting(num);
    cout << endl;

    return 0;
}