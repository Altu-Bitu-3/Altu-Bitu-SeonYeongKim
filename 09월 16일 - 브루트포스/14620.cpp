// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> p;

int n;
vector<vector<int>> input;
vector<vector<p>> successPos;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

// 주어진 벡터에 있는 씨앗들이 꽃을 피웠을 때 땅 가격을 구하는 함수
int calcSum(vector<p> v) {
    int sum = 0;
    
    for(int i=0; i<3; i++) {
        p cur = v[i];
        
        sum += input[cur.first][cur.second];  // 씨앗 위치 땅값 더하고
        
        // 위치가 주어진 씨앗의 꽃 피우기
        for(int dir=0; dir<4; dir++) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            
            sum += input[x][y];  // 꽃잎 위치 땅값 더하고
        }
    }
    
    return sum;
}

// 세 좌표에 씨앗을 심었을 때 꽃 개화가 성공하는지 리턴
bool isSucceed(vector<p> &seedpos) {
    vector<vector<bool>> flowerPos (n, vector<bool>(n,false));
    
    // 꽃 위치 벡터에 씨앗 위치 표시
    for(int i=0; i<3; i++)
        flowerPos[seedpos[i].first][seedpos[i].second] = true;
    
    // 꽃 피우기
    for(int i=0; i<3; i++) {
        p cur = seedpos[i];
        
        // (씨앗의 상하좌우에 위치 표시)
        for(int dir=0; dir<4; dir++) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            
            // 꽃이 땅을 벗어난다면
            if(x<0 || x>=n || y<0 || y>=n)
                return false;
            
            // 이미 꽃이 있어서 겹친다면
            if(flowerPos[x][y])
                return false;
            
            flowerPos[x][y] = true;
        }
    }
    
    return true;
}

int solution () {
    // permutation으로 조합을 구하기 위한 임시 배열
    int tot = n*n;
    vector<bool> tmp(tot, false);
    tmp[tot-1] = tmp[tot-2] = tmp[tot-3] = true;
    
    do{
        vector<p> seedPos;
        // 조합으로 씨앗 위치가 될수 있는 좌표들 구해서 seedPos 벡터에 넣기
        for(int i=0; i<tot; i++) {
            if(tmp[i])
                seedPos.push_back({i/n, i%n});
        }
        
        // 씨앗 심기에 성공하면 successPos에 넣기
        if(isSucceed(seedPos))
            successPos.push_back(seedPos);
        
    } while (next_permutation(tmp.begin(), tmp.end()));
    
    // 각 조합의 땅값들의 최솟값 구하기
    int minCost = 3001;
    for(int i=0; i<successPos.size(); i++) {
        int curCost = calcSum(successPos[i]);
        if(curCost < minCost) {
            minCost = curCost;
        }
    }
    
    return minCost;
}
int main() {
    cin >> n;
    input.assign(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> input[i][j];
    
    cout << solution();
}

/*
 */
