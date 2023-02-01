#include <iostream>
using namespace std;

/*
bool isPossibleSolution(int arr[], int n, int m, int solution) {

    int i=0;

    while(i<n && m!=0) {
        int sum = 0;

        while(i<n && sum<solution) {
            sum += arr[i++];
        }

        if(sum > solution) {
            i--;
            sum -= arr[i];
            m--;
        }
    }

    return (m) ? true : false;

}
*/

bool isPossibleSolution(int arr[], int n, int m, int solution) {

    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++) {
        if(pageSum + arr[i] <= solution) {
            pageSum += arr[i];
        } else {
            studentCount++;

            if(studentCount > m || arr[i] > solution) {
                return false;
            }

            pageSum = arr[i];
        }
    }

    return true;

}

int allocateBooks(int arr[], int n, int m) {
    int answer = -1;
    int start = 0;
    int end = 0;

    // Finding sum of elements of the array
    for(int i=0; i<n; i++) {
        end += arr[i];
    }

    while(start <= end) {
        int mid = start + (end-start)/2;

        if(isPossibleSolution(arr, n, m, mid)) {
            answer = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return answer;
}

int main() {
    int size, stud;
    int arr[100];

    cout<<"Enter the total number of books : ";
    cin>>size;

    cout<<"Enter the array of pages : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the number of students : ";
    cin>>stud;

    int minMaxPage = allocateBooks(arr, size, stud);

    cout<<"Minimum of maximum alloted pages = "<<minMaxPage<<endl;

    return 0;
}