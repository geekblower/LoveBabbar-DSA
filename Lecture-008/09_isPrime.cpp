#include <iostream>
using namespace std;

bool isPrime(int num) {
    for(int i=2; i<num; i++) {
        if(num%i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    if(isPrime(n)) {
        cout<<"Prime number!"<<endl;
    } else {
        cout<<"Not a prime number!"<<endl;
    }

    return 0;
}