#include <iostream>
using namespace std;

int pow(int n, int p) {
    return (p==0) ? 1 : n*pow(n, p-1);
}

int main() {
    int n;
    cout<<"Enter a negative number : ";
    cin>>n;

    n *= (-1);      //Converting the negative number into positive to find its binary representation

    int answer = 0;
    int i = 0;

    n = (~n);       // Getting the 1's compliment of the number
    n = n + 1;      // Adding 1 in order to obtain the 2's compliment of the number

    while(n != 0 && n != -1) {
        int bit = n & 1;

        answer = answer + (bit * pow(10,i));

        i++;
        n = n >> 1;
    }

    cout<<"Converted Binary Number : "<<answer<<endl;

    return 0;
}