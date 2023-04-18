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

Node* findMiddle(Node* head) {
    Node* fast = head->next;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* mergeLL(Node* head1, Node* head2) {
    if(head1==NULL || head2==NULL) {
        return (head1==NULL) ? head2 : head1;
    }

    Node* answer = new Node(-1);
    Node* temp = answer;

    while(head1!=NULL && head2!=NULL) {
        if(head1->data < head2->data) {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    if(head1 != NULL) {
        temp->next = head1;
    }

    if(head2 != NULL) {
        temp->next = head2;
    }

    return answer->next;
}

Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node* mid = findMiddle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeLL(left, right);
}

int main() {
    Node *head = new Node(5);

    insertAtHead(head, 44);
    insertAtHead(head, 32);
    insertAtHead(head, 19);
    insertAtHead(head, 76);
    insertAtHead(head, -3);
    insertAtHead(head, 0);
    insertAtHead(head, 62);

    cout << "Before sorting : ";
    printList(head);

    head = mergeSort(head);

    cout << "After sorting : ";
    printList(head);

    return 0;
}