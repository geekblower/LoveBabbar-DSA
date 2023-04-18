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

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool isPalindrome(Node* head) {
    Node* middle = getMiddle(head);
    middle = middle->next;
    middle = reverse(middle);

    Node* head1 = head;
    Node* head2 = middle;

    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return false;
        }

        head1 = head1->next;
        head2 = head2 ->next;
    }

    middle = reverse(middle);
    return true;
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