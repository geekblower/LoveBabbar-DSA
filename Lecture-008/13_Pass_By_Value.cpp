#include <iostream>
using namespace std;

void dummy(int n) {
    n++;
    cout<<"In dummy : n = "<<n<<endl;
}

int main() {
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    cout<<"Before call : n = "<<n<<endl;

    dummy(n);

    cout<<"After call : n = "<<n<<endl;

    return 0;
}