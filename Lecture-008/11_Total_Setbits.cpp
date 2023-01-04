#include <iostream>
using namespace std;

int countSetbits(int n) {
    int count = 0;

    while(n != 0) {
        if(n&1 == 1) {
            count++;
        }
        
        n = n>>1;
    }

    return count;
}

int main() {
    int a, b;

    cout<<"Enter the value of a : ";
    cin>>a;

    cout<<"Enter the value of b : ";
    cin>>b;

    int totalSetbits = countSetbits(a) + countSetbits(b);

    cout<<"Total count of setbits = "<<totalSetbits<<endl;

    return 0;
}