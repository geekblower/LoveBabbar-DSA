#include <iostream>
using namespace std;

int pow(int n, int p) {
    return (p==0) ? 1 : n*pow(n, p-1);
}

int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int answer = 0;
    int i = 0;

    while(n != 0) {
        int digit = n % 10;

        if(digit == 1) {
            answer = answer + pow(2,i);
        }

        i++;
        n /= 10;
    }

    cout<<"Converted Binary Number : "<<answer<<endl;

    return 0;
}