#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findDuplicate(int arr[], int size) {
    int ans = 0;
    for(int i=0; i<size; i++) {
        ans = ans ^ arr[i];
    }

    for(int i=1; i<size; i++) {
        ans = ans ^ i;
    }

    return ans;
}

int main() {
    int size;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Duplicate element in he array : "<<findDuplicate(arr, size)<<endl;

    return 0;
}