// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int cnt(int n, vector<p> v) {
    int highest = v[0].second, pass = 1;
    for(int i=1; i<n; i++) {
        if(highest > v[i].second) {
            highest = v[i].second;
            pass++;
        }
    }
    return pass;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<p> v(n);
        for(int i=0; i<n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        
        sort(v.begin(), v.end()); // 서류 성적순으로 정렬
        
        int ans = cnt(n, v);
        
        cout << ans << "\n";
    }
    
    return 0;
}

/*
 */
