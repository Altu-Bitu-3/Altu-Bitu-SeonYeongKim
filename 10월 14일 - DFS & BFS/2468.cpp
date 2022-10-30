// Authored by : seondal
// Co-authored by : -

//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int land[102][102];
int maxArea = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> land[i][j];
    
    for(int rain=0; rain<100; rain++){
        // 비에 잠긴다
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(land[i][j] <= rain) land[i][j]=0;
        
        // 초기화
        int area = 0;
        bool vis[102][102] = {false};

        // 안전영역 갯수 세기
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(land[i][j] == 0) continue; // 잠겼으면 패스
                if(vis[i][j]) continue; // 이미 방문했으면 패스
                
                area++;
                queue<pair<int, int>> q;
                q.push({i,j});
                vis[i][j] = true;
                
                while(!q.empty()){
                    auto c = q.front();
                    q.pop();
                    
                    for(int dir=0; dir<4; dir++){
                        int x = c.first + dx[dir];
                        int y = c.second + dy[dir];
                        
                        if(x<0 || x>=n || y<0 || y>=n) continue;
                        if(vis[x][y] || land[x][y]==0) continue;
                        
                        q.push({x,y});
                        vis[x][y] = true;
                    }
                }
                
            }
        }
        if(maxArea < area) maxArea = area;
    }
    
    cout << maxArea;
}
    
/**/
