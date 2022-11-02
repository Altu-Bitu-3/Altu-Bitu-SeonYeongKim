// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ci;

const int INF = 1e7;

void floydWarshall(int n, vector<vector<ci>>&graph) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int passK = graph[i][k].first + graph[k][j].first;
                if(passK < graph[i][j].first) {
                    // k 집하장을 지나는 경우가 더 빠른경우
                    graph[i][j].first = passK;
                    graph[i][j].second = graph[i][k].second;
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m, a,b,t;
    cin >> n >> m;
    
    // 초기화
    vector<vector<ci>> graph(n+1, vector<ci>(n+1, {INF,0})); // graph[i][j] = {경로크기, 지나는 집하장}
    for(int i=1; i<=n; i++)
        graph[i][i] = {0, 0}; // i에서 i로 갈때는 0시간이 걸리고 집하장을 지나지 않음(0)
    
    // 입력
    while(m--) {
        cin >> a >> b >> t;
        // a에서 b로 갈때 t시간이 걸리고 집하장 b를 지남
        graph[a][b] = {t, b};
        graph[b][a] = {t, a};
    }
    
    // 연산
    floydWarshall(n, graph);
    
    // 출력
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            if(graph[i][j].second == 0)
                cout << "- ";
            else
                cout << graph[i][j].second << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
 */

