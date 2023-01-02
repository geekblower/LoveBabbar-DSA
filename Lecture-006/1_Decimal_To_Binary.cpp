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
        int bit = n & 1;

        answer = answer + (bit * pow(10,i));

        i++;
        n = n >> 1;
    }

    cout<<"Converted Binary Number : "<<answer<<endl;

    return 0;
}