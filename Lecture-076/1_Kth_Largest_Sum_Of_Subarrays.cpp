#include <bits/stdc++.h>
using namespace std;

// int KthLargestSumOfSubarrays(vector<int> arr, int K) {
//     vector<int> sumStore;
//     int size = arr.size();

//     for(int i=0; i<size; i++) {
//         int temp = 0;
//         for(int j=i; j<size; j++) {
//             temp += arr[j];
//             sumStore.push_back(temp);
//         }
//     }

//     sort(sumStore.begin(), sumStore.end());
//     return sumStore[sumStore.size() - K];
// }

int KthLargestSumOfSubarrays(vector<int> arr, int K) {
    priority_queue<int, vector<int>, greater<int> > sumStore;
    int size = arr.size();

    for(int i=0; i<size; i++) {
        int temp = 0;
        for(int j=i; j<size; j++) {
            temp += arr[j];
            
            if(sumStore.size() < K) {
                sumStore.push(temp);
            } else {
                if(temp > sumStore.top()) {
                    sumStore.pop();
                    sumStore.push(temp);
                }
            }
        }
    }

    return sumStore.top();
}

int main() {
    vector<int> arr;

    cout << "Enter the elements of array (-1 to stop) : ";
    int temp;
    cin >> temp;
    do {
        arr.push_back(temp);
        cin >> temp;
    } while(temp != -1);

    int K;
    cout << "Enter the value of K : ";
    cin >> K;

    int largestSum = KthLargestSumOfSubarrays(arr, K);

    cout << "The kth largest sum of subarrays : " << largestSum;

    return 0;
}