#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int sum = 1;

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    cout<<a<<" "<<b<<" ";

    for(int i=2; i<n; i++) {
        sum = a + b;
        cout<<sum<<" ";
        a = b;
        b = sum;
    }
    
    return 0;
}