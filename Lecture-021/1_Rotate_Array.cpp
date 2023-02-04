#include <iostream>
#include <vector>
using namespace std;

void rotateArray(vector<int> &arr, int k) {
    vector<int> temp(arr);

    for(int i=0; i<temp.size(); i++) {
        int target = (i+k) % arr.size();
        temp[target] = arr[i];
    }

    arr = temp;
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

    cout<<"Enter the target index : ";
    cin>>k;

    cout<<"Before rotate : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    rotateArray(arr, k);
    
    cout<<"After rotate : ";
    for(int i:arr) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}