#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int product = 1;
    int sum = 0;

    while(n != 0) {
        int digit = n%10;

        product *= digit;
        sum += digit;

        n /= 10;
    }

    int answer = product - sum;

    cout<<"Required answer = "<<answer<<endl;
    
    return 0;
}