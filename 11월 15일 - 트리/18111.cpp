// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ci;

const int INF = 150000000; // 500*500*256*2 = 128000000

ci solution(int n, int m, int b, vector<vector<int>>&land) {
    ci ans = {INF, 0}; // 답 쌍 = { 걸리는 최소시간, 땅 높이 }
    
    for(int height=0; height<=256; height++) {
        int inventory=b, required_time=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int diff = land[i][j] - height;
                if(diff>0) {
                    // 양수일경우: 블럭을 제거하여 인벤토리에 넣는다 (2초)
                    required_time += 2*diff;
                } else {
                    // 음수일경우: 블럭을 꺼내서 위에 놓는다 (1초)
                    required_time += 1*-diff;
                }
                inventory += diff;
            }
        }
        
        if(inventory>=0 && ans.first>=required_time) {
            ans = {required_time, height};
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> land (n, vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> land[i][j];
    
    ci ans = solution(n, m, b, land);
    
    cout << ans.first << " " << ans.second;
    
    return 0;
}

/*
 */

