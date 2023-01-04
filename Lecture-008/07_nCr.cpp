#include <iostream>
using namespace std;

int factorial(int num) {
    int fact = 1;

    for(int i=1; i<=num; i++) {
        fact *= i;
    }

    return fact;
}

// nCr = n!/r!(n-r)!
int nCr(int n, int r) {
    int num = factorial(n);
    int denum = factorial(r) * factorial(n-r);

    int answer = num/denum;

    return answer;
}

int main() {
    int n, r;

    cout<<"Enter the value of n : ";
    cin>>n;

    cout<<"Enter the value of r : ";
    cin>>r;

    int answer = nCr(n, r);

    cout<<"Answer = "<<answer<<endl;

    return 0;
}