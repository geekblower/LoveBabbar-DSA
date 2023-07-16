#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b) {
    return (a==b) ? 0 : (a>b ? 1 : -1);
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median) {

    switch(signum(maxHeap.size(), minHeap.size())) {

        case 0 :
            if(element > median) {
                minHeap.push(element);
                median = minHeap.top();
            } else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

        case 1 : 
            if(element > median) {
                minHeap.push(element);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;
            
        case -1 :
            if(element > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
            } else {
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;

    }

}

vector<int> findMedian(vector<int>& arr, int N) {
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median = 0;

    for(int i=0; i<N; i++) {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}

int main() {
    int N;

    cout << "Enter the size of the array : ";
    cin >> N;
    vector<int> arr(N);

    cout << "Enter the elements of array : ";
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    vector<int> ans = findMedian(arr, N);

    cout << "Median : " << ans[ans.size()-1] << endl;

    return 0;
}