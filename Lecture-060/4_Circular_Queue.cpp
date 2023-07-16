#include <bits/stdc++.h>
using namespace std;

class CQueue {
    int *arr;
    int size, front, rear;

    public:
    CQueue(int S) {
        size = S;
        arr = new int[size];
        front = rear = 0;
    }

    void push(int val) {
        // Overflow condition
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
            cout << "CQueue overflow!" << endl;
            return;
        } else if(front == -1) {
            // For first element
            front = rear = 0;
        } else if(rear == size-1 && front != 0) {
            // If front is in middle of the queue and rear is at the end
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = val;
    }

    void pop() {
        if(front == rear+1 || front == -1) {
            cout << "CQueue underflow!" << endl;
        } else if(front == rear) {
            front = rear = -1;
        } else if(front == size-1) {
            front = 0;
        } else {
            front++;
        }
    }

    int frontElement() {
        return (front==rear) ? -1 : arr[front];
    }

    int backElement() {
        return (front==rear) ? -1 : arr[rear-1];
    }

    int queueSize() {
        return (front==rear) ? 0 : (rear-front);
    }

    bool empty() {
        return (front==rear) ? true : false;
    }
};

int main() {
    CQueue q(10);
    q.push(11);

    cout << "Front element of q : " << q.frontElement() << endl;
    cout << "Back element of q : " << q.backElement() << endl;
    q.push(15);
    cout << "Front element of q : " << q.frontElement() << endl;
    cout << "Back element of q : " << q.backElement() << endl;

    q.push(23);
    q.push(30);

    cout << "Size of queue : " << q.queueSize() << endl;

    cout << endl << "Front before pop : " << q.frontElement() << endl;
    cout << "Back before pop : " << q.backElement() << endl;
    q.pop();    
    cout << "Front after pop : " << q.frontElement() << endl;
    cout << "Back after pop : " << q.backElement() << endl << endl;

    q.pop();
    q.pop();

    cout << "Size of queue : " << q.queueSize() << endl;

    q.pop();

    if(q.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}