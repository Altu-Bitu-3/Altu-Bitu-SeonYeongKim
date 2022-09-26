// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> input;
vector<bool> isVisit;  // 지역 i의 방문 여부
vector<int> cost;  // 가능한 이동 비용들

void recur(int start, int cur, int cnt, int sum){
    // n개 지역을 전부 방문했고, 출발지로 돌아갈 수 있다면
    if(cnt==n && input[cur][start]!=0) {
        sum += input[cur][start];
        cost.push_back(sum);
        return;
    }
    
    for(int i=0; i<n; i++) { // 다음 행선지 찾기
        if(isVisit[i] || input[cur][i]==0)  // 이미 방문했거나 갈 수 없다면 패스
            continue;
        isVisit[i] = true;
        recur(start, i, cnt+1, sum+input[cur][i]);
        isVisit[i] = false;
    }
}

int solution() {
    for(int i=0; i<n; i++) {
        isVisit[i] = true;
        recur(i,i,1,0);
        isVisit[i] = false;
    }
    
    sort(cost.begin(), cost.end());
    int minCost = cost[0];
    
    return minCost;
}

int main() {
    cin >> n;
    input.assign(n, vector<int>(n,0));
    isVisit.assign(n, false);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> input[i][j];

    cout << solution();
    
    return 0;
}

/*
 */
