// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int r, int b) {
    vector<int> ans;
    
    int tot = r+b;
    
    for(int i=1; i<tot; i++) {
        if(tot%i != 0) continue;
        
        int l = i, w = tot/i;
        int brown = (l-2)*(w-2);
        
        if(brown == b) {
            ans.push_back(max(l, w));
            ans.push_back(min(w, l));
        }
    }
    
    return ans;
}

int main() {
    int r, b;
    cin >> r >> b;
    
    vector<int> ans = solution(r, b);
    cout << ans[0] << " " << ans[1];

    return 0;
}

/*
 */
