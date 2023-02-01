#include <iostream>
using namespace std;

bool isPossibleSolution(int boards[], int n, int k, int solution) {

    int painterCount = 1;
    int boardSum = 0;

    for(int i=0; i<n; i++) {
        if(boardSum + boards[i] <= solution) {
            boardSum += boards[i];
        } else {
            painterCount++;

            if(painterCount > k || boards[i] > solution) {
                return false;
            }

            boardSum = boards[i];
        }
    }

    return true;

}

int paintersPartition(int boards[], int n, int k) {
    int answer = -1;
    int start = 0;
    int end = 0;

    for(int i=0; i<n; i++) {
        end += boards[i];
    }

    while(start <= end) {
        int mid = start + (end-start)/2;

        if(isPossibleSolution(boards, n, k, mid)) {
            answer = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return answer;
}

int main() {
    int size, painters;
    int boards[100];

    cout<<"Enter the total number of boards : ";
    cin>>size;

    cout<<"Enter the length of boards : ";
    for(int i=0; i<size; i++) {
        cin>>boards[i];
    }

    cout<<"Enter the number of painters : ";
    cin>>painters;

    int solution = paintersPartition(boards, size, painters);

    cout<<"Minimum of maximum time taken = "<<solution<<endl;

    return 0;
}