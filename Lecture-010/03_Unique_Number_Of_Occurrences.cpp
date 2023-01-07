#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool uniqueOccurrences(int arr[], int size) {
    vector<int> count;
    
    //In-built function to sort the array
    sort(arr, arr+size);

    for(int i=0; i<size; i++) {
        int cnt = 0;
        int flag = arr[i];

        while(i<size && arr[i] == flag) {
            i++;
            cnt++;
        }
        i--;

        count.push_back (cnt);
    }

    sort(count.begin(), count.end());

    for(int i=0; i<count.size()-1; i++) {
        if(count[i] == count[i+1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int size;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    if(uniqueOccurrences(arr, size)) {
        cout<<"Number of occurrences of each value is the array is unique!"<<endl;
    } else {
        cout<<"Number of occurrences of each value is the array is not unique!"<<endl;
    }

    return 0;
}
