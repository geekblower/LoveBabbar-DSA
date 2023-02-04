#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int start = m+1;
    int end = arr.size()-1;

    while(start <= end) {
        swap(arr[start++], arr[end--]);
    }
}

int main() {
    int size, m;
    vector<int> arr;

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        int temp;
        cin>>temp;
        arr.push_back (temp);
    }

    cout<<"Enter the target index : ";
    cin>>m;

    cout<<"Before reverse operation : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    reverseArray(arr, m);
    
    cout<<"After reverse operation : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}