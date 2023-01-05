#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key) {
            return true;
        }
    }

    return false;
}

int main() {
    int size, key;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the element of the array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the key to search for : ";
    cin>>key;

    if(linearSearch(arr, size, key)) {
        cout<<"Element found in the array!"<<endl;
    } else {
        cout<<"Element not found in the array!"<<endl;
    }

    return 0;
}