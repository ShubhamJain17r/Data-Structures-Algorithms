// Count Primes

// https://leetcode.com/problems/count-primes?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    0 <= n <= 5 * 10^6
*/

#include<bits/stdc++.h>

using namespace std;

/*
Mark every multiple of prime as not prime.
*/

int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    for (long long i = 2; i * i < n; i++) {       // TC : O(n log(log n))
        if (isPrime[i] == false) 
            continue;
        for (long long j = i * i; j < n; j += i) {  // we start from i*i as i * k (k < i) is already marked by numbers before i
            isPrime[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i] == true) cnt++;
    }
    
    return cnt;
}