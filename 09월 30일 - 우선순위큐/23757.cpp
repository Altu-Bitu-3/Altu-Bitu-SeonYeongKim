// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bool possible = true;

    int n, m;
    cin >> n >> m;

    priority_queue<int> q;
    for (int i=0; i<n; i++){
        int c;
        cin >> c;
        q.push(c);
    }
    
    for (int i=0; i<m; i++) {
        int w;
        cin >> w;
        if(q.top() >= w) {
            q.push(q.top()-w);
            q.pop();
        } else
            possible = false;
    }
    
    if(possible)
        cout << 1;
    else
        cout << 0;

    return 0;
}

/*
 */
