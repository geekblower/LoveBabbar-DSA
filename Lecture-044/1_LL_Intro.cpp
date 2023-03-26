#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    Node head(10);

    Node head2(20);
    head.next = &head2;

    cout << head.data << " & " << head.next->data << endl;

    Node *head3 = new Node(30);
    cout << head3->data << endl;

    return 0;
}