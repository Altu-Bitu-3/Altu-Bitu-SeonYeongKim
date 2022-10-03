// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int lis(int n, vector<int>&a) {
    vector<int>dp (n,1);  // dp[i] : a[i]로 끝나는 가장 큰 수열
    
    for(int i=0; i<n; i++){
        int tmpMax = 0;
        
        for(int j=0; j<i; j++) {
            if(a[j]<a[i] && tmpMax<dp[j])
                // 현재 수 a[i]보다 작은 숫자를 찾고 해당 숫자가 전까지의 문자열 갯수 dp[j] 의 최댓값찾기
                tmpMax = dp[j];
        }
        
        dp[i] += tmpMax;
    }
    
    int maxDp = dp[0];
    for(int i=1; i<n; i++)
        if(maxDp < dp[i])
            maxDp = dp[i];
    
    return maxDp;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << lis(n, a);
    
    return 0;
}

/*
 */
