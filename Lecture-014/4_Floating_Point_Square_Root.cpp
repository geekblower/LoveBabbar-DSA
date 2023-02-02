#include <iostream>
using namespace std;

int sqrtInteger(int n) {
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

double sqrtPrecision(int n, int count, int prevSol) {
    double factor = 1;
    double answer = prevSol;

    for(int i=0; i<count; i++) {
        factor = factor / 10;

        double temp = answer;

        while(temp*temp < n) {
            answer = temp;
            temp += factor;
        }
    }

    return answer;
}

int main() {
    int num;
    cout<<"Enter the number : ";
    cin>>num;

    int tempAnswer = sqrtInteger(num);
    double answer = sqrtPrecision(num, 3, tempAnswer);

    cout<<"Required square root : "<<answer<<endl;

    return 0; 
}