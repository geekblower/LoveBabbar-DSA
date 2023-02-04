#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &arr) {
    for(int i=0, zero=0; i<arr.size(); i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[zero]);
            zero++;
        }
    }
}

int main() {
    int size;
    vector<int> arr;

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        int temp;
        cin>>temp;
        arr.push_back (temp);
    }

    cout<<"Before shifting zeroes : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    moveZeroes(arr);
    
    cout<<"After shifting zeroes : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}