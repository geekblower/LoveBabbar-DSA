#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> arr, int n) {
    unordered_map<int, int> M;

    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        M[arr[i]]++;
        maxi = max(maxi, M[arr[i]]);
    }

    for(int i=0; i<n; i++) {
        if(M[arr[i]] == maxi) {
            return arr[i];
        }
    }
}

int main() {
    vector<int> arr;

    cout << "Enter the elements of arr (-1 to stop) : ";
    int data;
    cin >> data;
    while(data != -1) {
        arr.push_back(data);
        cin >> data;
    }

    int ans = maximumFrequency(arr, arr.size());

    cout << "Elemnet with maximum frequency : " << ans << endl;
    return 0;
}