#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int *arr;
    int limit, maxSize;

    Stack(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        limit = -1;
    }

    void push(int data) {
        if(limit == maxSize-1) {
            cout << "Stack overflow!" << endl;
            return;
        }

        limit++;
        arr[limit] = data;
    }

    void pop() {
        if(limit == -1) {
            cout << "Stack underflow!" << endl;
        } else {
            limit--;
        }
    }

    bool isEmpty() {
        return (limit < 0) ? true : false;
    }

    int size() {
        return limit+1;
    }

    int top() {
        return (limit < 0) ? -1 : arr[limit];
    }
};

int main() {
    // Creation of stack
    Stack s(10);

    // Push operation
    s.push(10);
    s.push(61);

    // Size operation
    cout << "Current size of stack : " << s.size() << endl;

    // Peek operation
    cout << "Top element : " << s.top() << endl;

    // Pop operation
    s.pop();

    cout << "Current size of stack : " << s.size() << endl;
    cout << "Top element : " << s.top() << endl;

    if(s.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    s.pop();
    
    if(s.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    cout << "Current size of stack : " << s.size() << endl;
    return 0;
}