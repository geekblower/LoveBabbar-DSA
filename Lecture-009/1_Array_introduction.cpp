#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout<<"Printing array : ";

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main() {
    int arr[15] = {0};

    printArray(arr, 15);

    cout<<"Size of array = "<<sizeof(arr)<<endl;
    cout<<"Length of array = "<<sizeof(arr) / sizeof(int)<<endl;


    return 0;
}