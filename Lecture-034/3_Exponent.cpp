#include <bits/stdc++.h>
using namespace std;

int exponentialPower(int num, int power) {
    if(power == 0) {
        return 1;
    }

    int temp = exponentialPower(num, power/2);

    if(power&1) {
        return num * temp * temp;
    } else {
        return temp * temp;
    }
}

int main() {
    int num, power;

    cout << "Enter the number : ";
    cin >> num;
    
    cout << "Enter the power : ";
    cin >> power;

    cout << num << " ^ " << power << "  :  " << exponentialPower(num, power) << endl;
    
    return 0;
}