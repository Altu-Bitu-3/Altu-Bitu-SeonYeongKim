// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int maxWine(int n, vector<int>&wine) {
    vector<int> dp(n,0);
    
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    
    for(int i=2; i<n; i++) {
        dp[i] = max(dp[i-2], dp[i-3]+wine[i-1]) + wine[i];
        dp[i] = max(dp[i-1], dp[i]);
    }
    
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> wine(n,0);
    for(int i=0; i<n; i++)
        cin >> wine[i];
    
    cout << maxWine(n, wine);
    
    return 0;
}

/*
 */
