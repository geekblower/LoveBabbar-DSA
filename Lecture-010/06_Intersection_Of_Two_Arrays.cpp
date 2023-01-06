#include <iostream>
using namespace std;

void inputArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void intersectionArray(int arr1[], int arr2[], int size1, int size2) {
    int i=0, j=0;

    while(i<size1 && j<size2) {
        if(arr1[i] < arr2[j]) {
            i++;
        }

        if(arr1[i] > arr2[j]) {
            j++;
        }

        if(arr1[i] == arr2[j]) {
            cout<<arr1[i]<<" ";
            
            while(arr1[i] == arr2[j]) {
                i++;
                j++;
            }
        }
    }
}

int main() {
    int size1, size2;
    int arr1[100], arr2[100];

    cout<<"Enter the size of first array : ";
    cin>>size1;

    cout<<"Enter the elements of first array : ";
    inputArray(arr1, size1);

    cout<<"Enter the size of second array : ";
    cin>>size2;

    cout<<"Enter the elements of second array : ";
    inputArray(arr2, size2);

    cout<<"Intersection elements of these two arrays : ";
    intersectionArray(arr1, arr2, size1, size2);

    return 0;
}