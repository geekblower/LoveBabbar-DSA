#include <iostream>
#include <limits.h>
using namespace std;

bool isPowerOfTwo(int n) {
    int power = 1;

    for(int i=0; i<31; i++) {
        if(power == n) {
            return true;
        }

        if(power < INT_MAX/2) {
            power *= 2;
        }
    }

    return false;
}

int main() {
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    if(isPowerOfTwo(n)) {
        cout<<n<<" is a power of two!"<<endl;
    } else {
        cout<<n<<" is not a power of two!"<<endl;
    }

    return 0;
}