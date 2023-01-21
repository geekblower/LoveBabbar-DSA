#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int minIndex = i;

        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
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

    selectionSort(arr, n);

    cout<<"\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
