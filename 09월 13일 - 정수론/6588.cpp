// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void findPrime(vector<bool> &isPrime) {
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i<=1000000; i++) {
        for(int j=i+i; j<=1000000; j+=i) {
            isPrime[j] = false;
        }
    }
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<bool> isPrime(1000001, true);
    findPrime(isPrime);
    
    int n;
    while(true) {
        cin >> n;
        if(n==0) break;
        
        for(int i=3; i<n; i++) {
            if(isPrime[i] && isPrime[n-i]) {
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
        
    }
    
    
    return 0;
}

/*
 */
