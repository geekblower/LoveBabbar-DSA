#include <bits/stdc++.h>
using namespace std;
// N - No of stack
// S - Size of array
// Q - No of queries
class NStack {
    int *arr, *top, *next;
    int freeSpot;

    public:
    NStack(int N, int S) {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        // Initialising top
        for(int i=0; i<N; i++) {
            top[i] = -1;
        }

        // Initialising next
        for(int i=0; i<S-1; i++) {
            next[i] = i+1;
        }
        next[S-1] = -1;     // Last index of next

        // Initialising freeSpot
        freeSpot = 0;
    }

    bool push(int X, int M) {
        // Check Overflow
        if(freeSpot == -1) {
            return false;
        }

        // Step 1 : Find Index
        int index = freeSpot;

        // Step 2 : Update Freespot
        freeSpot = next[index];

        // Step 3 : Insert in Array
        arr[index] = X;
   
        // Step 4 : Update Next
        next[index] = top[M-1];

        // Step 5 : Update Top
        top[M-1] = index;

        return true;
    }

    int pop(int M)  {
        // Check Overflow
        if(top[M-1] == -1) {
            return -1;
        }

        // Step 1 : Find Index
        int index = top[M-1];

        // Step 2 : Update Top
        top[M-1] = next[index];

        // Step 3 : Update Next
        next[index] = freeSpot;

        // Step 4 : Update Freespot
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    NStack nst(3, 6);

    if(nst.push(10, 1)) cout << "TRUE\n"; else cout << "FALSE\n";
    if(nst.push(20, 1)) cout << "TRUE\n"; else cout << "FALSE\n";
    if(nst.push(30, 2)) cout << "TRUE\n"; else cout << "FALSE\n";
    
    cout << "Popped : " << nst.pop(1) << endl;
    cout << "Popped : " << nst.pop(2) << endl;

    return 0;
}