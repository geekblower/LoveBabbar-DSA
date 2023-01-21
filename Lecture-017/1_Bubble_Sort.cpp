#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i=1; i<size; i++) {

        for(int j=0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }

    }
}

int main() {
    int n;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"\nArray before sorting : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    bubbleSort(arr, n);

    cout<<"\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
