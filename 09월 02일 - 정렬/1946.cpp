// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
        
        sort(v.begin(), v.end(), cmp); // 서류 성적순으로 정렬
        
        int tmp = n+1, pass = 0;
        for(int i=0; i<n; i++) {
            if(tmp > v[i].second) {
                tmp = v[i].second;
                pass++;
            }
        }
        
        cout << pass << "\n";
    }
    
    return 0;
}

/*
 */
