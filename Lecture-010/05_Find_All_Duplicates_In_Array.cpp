#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void findDuplicates(int nums[], int size) {
    sort(nums, nums+size);

    for(int i=0; i<size-1; i++) {
        if(nums[i] == nums[i+1]) {
            cout<<nums[i]<<" ";
            i++;
        }
    }
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

    cout<<"All duplicate elements of array : ";
    findDuplicates(arr, size);

    return 0;
}
