#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sumArray(vector<int> a1, vector<int> a2) {
    vector<int> sum;
    int n = a1.size()-1;
    int m = a2.size()-1;
    int carry = 0;

    while(n>=0 && m>=0) {
        int temp = a1[n--] + a2[m--] + carry;
        sum.push_back(temp%10);
        carry = temp/10;
    }

    while(n >= 0) {
        int temp = a1[n--] + carry;
        sum.push_back(temp%10);
        carry = temp/10;
    }

    while(m >= 0) {
        int temp = a2[m--] + carry;
        sum.push_back(temp%10);
        carry = temp/10;
    }

    if(carry) {
        sum.push_back(carry);
    }

    reverse(sum.begin(), sum.end());
    return sum;    
}

int main() {
    int size1, size2;
    vector<int> arr1;
    vector<int> arr2;

    cout<<"Enter the size of first array : ";
    cin>>size1;

    cout<<"Enter the elements of first array : ";
    for(int i=0; i<size1; i++) {
        int temp;
        cin>>temp;
        arr1.push_back (temp);
    }

    cout<<"Enter the size of second array : ";
    cin>>size2;

    cout<<"Enter the elements of second array : ";
    for(int i=0; i<size2; i++) {
        int temp;
        cin>>temp;
        arr2.push_back (temp);
    }

    vector<int> sum = sumArray(arr1, arr2);
    
    cout<<"Sum of the arrays : ";
    for(int i:sum) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
