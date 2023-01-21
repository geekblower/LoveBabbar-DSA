#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for(int i=1; i<size; i++) {
        int temp = arr[i];
        int j;

        for(j=i-1; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }

        arr[j+1] = temp;
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

    insertionSort(arr, n);

    cout<<"\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
