// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n,k;
    queue<int> q;
    vector<int> ans;
    
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    
    for(int i=1; !q.empty(); i++){
        if(i%k == 0) {
            ans.push_back(q.front());
        } else {
            q.push(q.front());
        }
        q.pop();
    }
    
    cout << "<";
    for(int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size()-1] << ">";
    
    return 0;
}

/*
 */
