#include <iostream>
using namespace std;

int main() {
    int size, sum=0;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the element of the array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
        sum += arr[i];
    }

    cout<<"Sum of all elements of the array = "<<sum<<endl;

    return 0;
}