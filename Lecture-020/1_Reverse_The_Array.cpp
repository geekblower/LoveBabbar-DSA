#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int start = 0;
    int end = arr.size()-1;

    while(start <= end) {
        swap(arr[start++], arr[end--]);
    }
}

int main() {
    int size;
    vector<int> arr;

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        int temp;
        cin>>temp;
        arr.push_back (temp);
    }

    cout<<"Before reverse operation : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    reverseArray(arr);
    
    cout<<"After reverse operation : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}