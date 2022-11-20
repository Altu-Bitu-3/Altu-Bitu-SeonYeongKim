// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


bool isArtPoint(int k, vector<vector<int>>&graph) {
    // 트리는 사이클이 없으므로 맨 끝점을 제외한 모든 정점이 단절점
    
    if(graph[k].size() >= 2)
        // 인접그래프에서 graph[k].size = 연결된 정점의 갯수
        // 연결된 정점의 갯수가 2개 이상이라면 해당 정점을 없애도 연결된 정점만큼 그래프가 생긴다 !
        return true;
    
    return false;
}

bool isArtBridge() {
    // 트리는 사이클이 없으므로 모든 간선이 단절선
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, a,b, q, t,k;
    cin >> n;
    vector<vector<int>> graph(n+1);
    while(--n) { // 인접그래프 만들기
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> q;
    bool ans;
    while(q--) {
        cin >> t >> k;
        
        if(t==1)
            ans = isArtPoint(k, graph);
        else // t==2
            ans = isArtBridge();
        
        if(ans)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}

/*
 */

