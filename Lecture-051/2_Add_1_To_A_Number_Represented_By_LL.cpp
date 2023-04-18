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

void printList(Node* head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* addOne(Node *head) {
    head = reverse(head);
    Node* temp = head;
    Node* answer = NULL;
    int carry = 1;

    while(temp!=NULL || carry!=0) {
        int val = 0;
        if(temp != NULL) {
            val = temp->data;
        }

        int sum = val + carry;
        insertAtHead(answer, sum%10);
        carry = sum / 10;

        if(temp != NULL) {
            temp = temp->next;
        }
    }
    
    head = reverse(head);
    return answer;
}

int main() {
    Node *head = NULL;

    insertAtHead(head, 9);
    insertAtHead(head, 9);
    insertAtHead(head, 9);

    Node *sum = addOne(head);

    cout << "List : ";
    printList(head);
    cout << "Sum : ";
    printList(sum);

    return 0;
}