// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> &p){
    int ans=0;
    
    sort(p.begin(), p.end());
    
    for(int i=0; i<n; i++)
        ans += p[i]*(n-i);
    
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++)
        cin >> p[i];
    
    cout << solution(n, p);
    
    return 0;
}

/*
 */
