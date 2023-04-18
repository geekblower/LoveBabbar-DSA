#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public:
    Node* head;
    int count;

    Stack() {
        head = NULL;
        count = 0;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        count++;
    }

    void pop() {
        if(head == NULL) {
            cout << "Stack underflow!" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
        }
    }

    bool isEmpty() {
        return (head == NULL) ? true : false;
    }

    int size() {
        return count;
    }

    int top() {
        return (head == NULL) ? -1 : head->data;
    }
};

int main() {
    // Creation of stack
    Stack s;

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