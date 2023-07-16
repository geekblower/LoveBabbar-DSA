#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* next;

    public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    int *arr;
    int size, front, rear;

    public:
    Queue(int S) {
        size = S;
        arr = new int[size];
        front = rear = 0;
    }

    void push(int val) {
        if(rear == size-1) {
            cout << "Queue overflow!" << endl;
        } else {
            arr[rear++] = val;
        }
    }

    void pop() {
        if(front == rear) {
            cout << "Queue underflow!" << endl;
        } else {
            front++;

            if(front == rear) {
                front = rear = 0;
            }
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
    Queue q(10);
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