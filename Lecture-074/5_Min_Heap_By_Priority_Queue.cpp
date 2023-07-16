#include <bits/stdc++.h>
using namespace std;


int main() {
    priority_queue<int, vector<int>, greater<int> > minHeap;

    minHeap.push(52);
    minHeap.push(50);
    minHeap.push(54);
    minHeap.push(40);
    minHeap.push(35);
    minHeap.push(65);

    cout << "Top element : " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;

    minHeap.pop();
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;

    if(minHeap.empty()) {
        cout << "Min Heap is empty!" << endl;
    }

    return 0;
}