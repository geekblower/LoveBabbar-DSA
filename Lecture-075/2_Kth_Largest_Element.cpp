#include <bits/stdc++.h>
using namespace std;

int KthLargest(vector<int> arr, int K) {
    priority_queue<int, vector<int>, greater<int> > Heap;

    for(int i=0; i<K; i++) {
        Heap.push(arr[i]);
    }

    for(int i=K; i<arr.size(); i++) {
        if(arr[i] > Heap.top()) {
            Heap.pop();
            Heap.push(arr[i]);
        }
    }

    return Heap.top();
}

int main() {
    vector<int> arr;

    cout << "Enter the elements of array (-1 to stop) : ";
    int temp;
    cin >> temp;
    while(temp != -1) {
        arr.push_back(temp);
        cin >> temp;
    }

    int K;
    cout << "Enter the value of K : ";
    cin >> K;

    int answer = KthLargest(arr, K);

    cout << "Kth largest elements : " << answer<< endl;

    return 0;
}