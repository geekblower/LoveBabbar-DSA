#include <bits/stdc++.h>
using namespace std;

int firstPosition(int arr[], int start, int end, int key) {
    if(start > end) {
        return -1;
    }

    int mid = start + (end-start)/2;
    int ans = -1;

    if(arr[mid] == key) {
        ans = mid;
        int temp = firstPosition(arr, start, mid-1, key);
        return (temp != -1) ? temp : ans;
    }

    if(arr[mid] > key) {
        return firstPosition(arr, start, mid-1, key);
    } else {
        return firstPosition(arr, mid+1, end, key);
    }

    return ans;
}

int lastPosition(int arr[], int start, int end, int key) {
    if(start > end) {
        return -1;
    }

    int mid = start + (end-start)/2;
    int ans = -1;

    if(arr[mid] == key) {
        ans = mid;
        int temp = lastPosition(arr, mid+1, end, key);
        return (temp != -1) ? temp : ans;
    }
    
    if(arr[mid] > key) {
        return lastPosition(arr, start, mid-1, key);
    } else {
        return lastPosition(arr, mid+1, end, key);
    }

    return ans;
}

int main() {
    int n, element;
    int arr[100];

    cout << "Enter the size of the array : ";
    cin >> n;

    cout << "Enter the elements of tha array : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for : ";
    cin >> element;
    
    int first = firstPosition(arr, 0, n-1, element);
    int last = lastPosition(arr, 0, n-1, element);

    cout << "First position : " << first << endl;
    cout << "Last position  : " << last << endl;

    return 0;
}