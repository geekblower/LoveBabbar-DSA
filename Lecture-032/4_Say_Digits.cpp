#include <bits/stdc++.h>
using namespace std;

string names[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string sayDigits(int num) {
    if(num < 10) {
        return names[num] + " ";
    }

    string solution = sayDigits(num/10);
    solution += names[num%10];
    solution += " ";

    return solution;
}

int main() {
    int num;

    cout << "Enter the number : ";
    cin >> num;

    cout << sayDigits(num) << endl;
    return 0;
}