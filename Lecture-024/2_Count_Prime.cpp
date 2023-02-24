#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
int countPrime(int n) {
    int count = 0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++) {
        if(prime[i]) {
            count++;

            for(int j=2*i; j<n; j+=i) {
                prime[j] = false;
            }
        }
    }

    return count;
}

int main() {
    int num;

    cout << "Enter the number : ";
    cin >> num;

    cout << "Total count of prime numbers from 1 to num : " << countPrime(num) << endl;

    return 0;
}