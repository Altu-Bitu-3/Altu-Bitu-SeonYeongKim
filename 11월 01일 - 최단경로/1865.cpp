// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;

const int INF = 6e7; // 걸리는 시간의 최댓값 : 간선갯수(2500+2500+500)*시간(10000) = 52e6

bool isThereNegativeCycle(int n, int path, vector<tp>&edges) {
        vector<int> dist(n+1, INF);
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<path; j++) {
                int s, d, w;
                tie(s,d,w) = edges[j];
                
                int next_weight = dist[s] + w;
                if(next_weight < dist[d]) {
                    dist[d] = next_weight;
                    
                    if(i==n)
                        return true;
                }
            }
        }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int tc, n,m,w, s,e,t;
    cin >> tc;
    while(tc--) {
        // 입력
        cin >> n >> m >> w;
        vector<tp> edges; // 간선 정보 저장
        for(int i=0; i<m; i++) { // 도로정보 입력받기 (양방향)
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int i=0; i<w; i++) { // 웜홀정보 입력받기 (단방향)
            cin >> s >> e >> t;
            edges.push_back({s, e, t*-1});
        }
        
        // 출력
        if(isThereNegativeCycle(n, 2*m+w, edges))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}

/*
 */