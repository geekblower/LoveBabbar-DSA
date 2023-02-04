#include <iostream>
#include <vector>
using namespace std;

bool checkSortedRotated(vector<int> arr) {
    int count = 0;

    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i] > arr[i+1]) {
            count++;
        }
    }

    if(arr[arr.size()-1] > arr[0]) {
        count++;
    }

    return (count == 1) ? true : false;
}

int main() {
    int size, k;
    vector<int> arr;

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        int temp;
        cin>>temp;
        arr.push_back (temp);
    }

    if(checkSortedRotated(arr)) {
        cout<<"Entered array is a sorted and rotated array!"<<endl;
    } else {
        cout<<"Entered array is not a sorted and rotated array!"<<endl;
    }

    return 0;
}