#include <bits/stdc++.h>
using namespace std;


int main() {
    priority_queue<int> maxHeap;

    maxHeap.push(52);
    maxHeap.push(50);
    maxHeap.push(54);
    maxHeap.push(40);
    maxHeap.push(35);
    maxHeap.push(65);

    cout << "Top element : " << maxHeap.top() << endl;

    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;

    maxHeap.pop();
    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;

    if(maxHeap.empty()) {
        cout << "Max Heap is empty!" << endl;
    }

    return 0;
}