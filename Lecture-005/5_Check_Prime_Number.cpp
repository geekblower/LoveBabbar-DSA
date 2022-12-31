#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    bool isPrime = true; 

    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            cout<<"Not a prime number!"<<endl;
            isPrime = false;
            break;
        }
    }

    if(isPrime) {
        cout<<"Prime number!"<<endl;
    }

    return 0;
}