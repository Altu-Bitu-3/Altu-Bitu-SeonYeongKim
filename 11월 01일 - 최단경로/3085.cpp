// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> candy;

int dx[] = {0, 1};
int dy[] = {1, 0};

int countCandy() {
    // 가장 긴 연속 사탕의 갯수 반환 함수
    int max_candy = 0;
    
    // i번째 행의 가장 긴 연속 갯수 구하기
    for(int i=0; i<n; i++) {
        char prev = candy[i][0];
        int cnt = 1;

        for(int j=1; j<n; j++) {
            if(prev == candy[i][j]) { // 연속
                cnt++;
                max_candy = max(max_candy, cnt);
            } else { // 불연속
                prev = candy[i][j];
                cnt = 1;
            }
        }
    }
    
    // i번째 열의 가장 긴 연속 갯수 구하기
    for(int j=0; j<n; j++) {
        char prev = candy[0][j];
        int cnt = 1;

        for(int i=1; i<n; i++) {
            if(prev == candy[i][j]) {
                cnt++;
                max_candy = max(max_candy, cnt);
            } else {
                prev = candy[i][j];
                cnt = 1;
            }
        }
    }
    
    return max_candy;
}

int solution() {
    int ans = countCandy();
    
    // 모든 사탕에 대해서
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            
            // 오른쪽이나 아래쪽 사탕과 교환
            for(int dir=0; dir<2; dir++) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                
                if(x>=n || y>=n)
                    continue;
                if(candy[i][j] == candy[x][y])
                    continue;
                
                swap(candy[i][j], candy[x][y]);
                ans = max(ans, countCandy());
                swap(candy[i][j], candy[x][y]); // 연속갯수 저장해주고 되돌리기
            }
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    candy.assign(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> candy[i][j];
    
    cout << solution();
    
    return 0;
}

/*
 */

