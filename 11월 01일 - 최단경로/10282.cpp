// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

const int INF = 100000000;

ci dijkstra(int start, int n, vector<vector<ci>>&graph) {
    vector<int> dist(n+1, INF); // dist[i]: i번 컴퓨터가 감염되는데 걸리는 시간
    priority_queue<ci, vector<ci>, greater<>> pq; // {정점, 시작점부터거리}
    
    // 시작 정점 초기화
    dist[start] = 0;
    pq.push({start, 0});
    
    while(!pq.empty()) {
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        
        if(weight > dist[node])
            continue;
        
        // 탐색하려는 노드와 연결된 노드들 탐색
        for(int i=0; i<graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            
            if(next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_node, next_weight});
            }
        }
    }
    
    // 감염된 컴퓨터 수와 시간 구하기
    int hacked=0, time=0;
    for(int i=0; i<n+1; i++) {
        if(dist[i] == INF)
            continue;
        
        hacked++;
        time = max(dist[i], time);
        // 감염될 수 있는 모든 컴퓨터가 감염되는데 걸리는 시간은 INF를 제외한 최댓값
    }
    
    return {hacked, time};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t, n,d,c, a,b,s;
    cin >> t;
    
    while(t--){
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n+1); // graph[b]=[{a,s}]: 컴퓨터b가 감염되면 s초 후 a도 감염
        for(int i=0; i<d; i++) {
            cin >> a >> b >> s;
            graph[b].push_back({a,s});
        }
        
        ci ans = dijkstra(c, n, graph);
        
        cout << ans.first << " " << ans.second << "\n";
    }
    
    return 0;
}

/*
 */

