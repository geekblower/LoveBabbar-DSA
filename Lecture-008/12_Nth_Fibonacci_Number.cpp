#include <iostream>
using namespace std;

int NthFibNum(int n) {
    int a=0, b=1, c=-1;

    if(n<=2) {
        return n-1;
    }

    for(int i=2; i<n; i++) {
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n;

    cout<<"Enter the number of n : ";
    cin>>n;

    cout<<"Nth fibonacci number = "<<NthFibNum(n)<<endl;

    return 0;
}