#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x) {
    int ans = 0;

    while(x != 0) {
        if((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
            return 0;
        }

        int digit = x%10;

        ans = (ans*10) + digit;

        x /= 10;
    }

    return ans;
}

int main() {
    int n;

    cout<<"Enter the number to reverse : ";
    cin>>n;

    int rev = reverse(n);

    cout<<"Reversed number = "<<rev<<endl;

    return 0;
}