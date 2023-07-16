#include <iostream>
#include <queue>
using namespace std;

int main() {

    deque<int> q;
    q.push_front(11);
    q.push_back(14);


    cout << "Front element of q : " << q.front() << endl;
    cout << "Back element of q : " << q.back() << endl;
    // q.push(15);
    // cout << "Front element of q : " << q.front() << endl;
    // cout << "Back element of q : " << q.back() << endl;

    // q.push(23);
    // q.push(30);

    // cout << "Size of queue : " << q.size() << endl;

    // cout << endl << "Front before pop : " << q.front() << endl;
    // cout << "Back before pop : " << q.back() << endl;
    // q.pop();    
    // cout << "Front after pop : " << q.front() << endl;
    // cout << "Back after pop : " << q.back() << endl << endl;

    // q.pop();
    // q.pop();

    // cout << "Size of queue : " << q.size() << endl;

    // q.pop();

    // if(q.empty()) {
    //     cout << "Queue is empty!" << endl;
    // } else {
    //     cout << "Queue is not empty!" << endl;
    // }

    return 0;
}