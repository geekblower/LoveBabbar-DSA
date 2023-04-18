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
    Node* temp = head;
    vector<int> newList;

    while(temp != NULL) {
        newList.push_back (temp->data);
        temp = temp->next;
    }

    int start = 0;
    int end = newList.size() - 1;

    while(start < end) {
        if(newList[start] != newList[end]) {
            return false;
        }

        start++;
        end--;
    }

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