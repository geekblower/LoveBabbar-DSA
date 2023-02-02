#include <iostream>
using namespace std;

int sqrt(int n) {
    int start = 0;
    int end = n-1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;

        long long temp = (long long) mid * mid;

        if(temp == n) {
            return mid;
        }

        if(temp < n) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        
    }

    return ans;
}

int main() {
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    int answer = sqrt(num);

    cout<<"Required square root : "<<answer<<endl;

    return 0; 
}