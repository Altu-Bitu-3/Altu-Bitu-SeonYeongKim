// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCandy(int n, int m, vector<vector<int>> &candy) {
    vector<vector<int>> dp (n, vector<int>(m,0)); // dp[i][j] = {i,j} 까지 올때 얻을 수 있는 사탕의 최대 갯수
    
    // 0번째 행과 0번쨰 열 (=올 수 있는 길이 한가지밖에 없는 경우들) 구해놓기
    dp[0][0] = candy[0][0];
    for(int i=1; i<m; i++)
        dp[0][i] = candy[0][i] + dp[0][i-1];
    for(int i=1; i<n; i++)
        dp[i][0] = candy[i][0] + dp[i-1][0];
    
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            // {i,j}에 올 수 있는 세가지 길 중 최댓값 구하기
            vector<int> tmp;
            tmp.push_back(dp[i-1][j]);
            tmp.push_back(dp[i][j-1]);
            tmp.push_back(dp[i-1][j-1]);

            sort(tmp.begin(), tmp.end());
            
            dp[i][j] = candy[i][j] + tmp[2];
        }
    }

    return dp[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> candy (n, vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> candy[i][j];
    
    cout << maxCandy(n, m, candy);
    
    return 0;
}

/*
 */
