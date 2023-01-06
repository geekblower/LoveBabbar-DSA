#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool uniqueOccurrences(int arr[], int size) {

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

    if(uniqueOccurrences(arr, size)) {
        cout<<"Number of occurrences of each value is the array is unique!"<<endl;
    } else {
        cout<<"Number of occurrences of each value is the array is not unique!"<<endl;
    }

    return 0;
}