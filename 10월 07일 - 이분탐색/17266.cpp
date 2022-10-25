// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가로등의 최소 길이
int minHeight(int n, int m, vector<int>&lightPos) {
    
    // 가로등 간격의 최댓값
    int maxDist=0;
    for(int i=1; i<m; i++)
        maxDist = max(maxDist, lightPos[i]-lightPos[i-1]);
    
    // 최대 가로등 간격 <= height*2 가 되게 하는 최소 height 값 구하기
    int height = 0;
    while(true) {
        height++;
        
        // 0~첫번째가로등위치 까지 비출 수 있는가?
        if(height < lightPos[0])
            continue;
        // 마지막가로등위치~n 까지 비출 수 있는가?
        if(height < n-lightPos[m-1])
            continue;
        
        // 가로등 사이 거리들을 다 비출 수 있는가?
        int range = height*2; // 가로등이 비출 수 있는 범위
        if(range < maxDist)
            continue;
        
        // 조건을 다 만족햇다면
        break;
    }
    
    return height;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> lightPos(m, 0); // i번째 가로등의 위치
    for(int i=0; i<m; i++)
        cin >> lightPos[i];
    
    cout << minHeight(n, m, lightPos);
    
    return 0;
}

/*
 */
