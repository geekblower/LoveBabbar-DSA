#include <bits/stdc++.h>
using namespace std;

void Rev_Queue_App1(queue<int> &Q) {
    stack<int> temp;

    while(!Q.empty()) {
        temp.push(Q.front());
        Q.pop();
    }

    while(!temp.empty()) {
        Q.push(temp.top());
        temp.pop();
    }
}

void print(queue<int> Q) {
    while(!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }

    cout << endl;
}

int main() {
    queue<int> Q;

    Q.push(77);
    Q.push(65);
    Q.push(98);
    Q.push(46);
    Q.push(32);

    cout << "Before reverse : ";
    print(Q);

    Rev_Queue_App1(Q);

    cout << "Before reverse : ";
    print(Q);
}