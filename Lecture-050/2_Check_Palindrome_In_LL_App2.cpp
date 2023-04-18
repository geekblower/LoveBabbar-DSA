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
    
    cout << "Singly List : ";
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

bool isPalindrome(Node* head) {
    Node* copy = NULL;
    Node* temp = head;
   
    while(temp != NULL) {
        insertAtHead(copy, temp->data);
        temp = temp->next;
    }
    // No need to reverse as inserting at head position has already reversed the list.

    bool flag = true;
    temp = copy;

    while(head != NULL) {
        if(head->data != temp->data) {
            flag = false;
            break;
        }

        head = head->next;
        temp = temp->next;
    }

    while(copy != NULL) {
        Node* target = copy;
        copy = copy->next;
        delete target;
    }

    return flag;
}

int main() {
    Node *head = NULL;

    insertAtHead(head, 54);
    insertAtHead(head, 67);
    insertAtHead(head, 34);
    insertAtHead(head, 99);
    insertAtHead(head, 34);
    insertAtHead(head, 67);
    insertAtHead(head, 54);

    printList(head);

    if(isPalindrome(head)) {
        cout << "List is palindrome!" << endl;
    } else {
        cout << "List is not palindrome!" << endl;
    }

    return 0;
}