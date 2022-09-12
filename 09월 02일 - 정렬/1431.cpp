// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(string s) {
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) {
            ans += s[i]-'0';
        }
    }
    return ans;
}

bool cmp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    if(count(a) != count(b)) return count(a) < count(b);
    return a < b;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<n; i++) cout << v[i] << "\n";
    
    return 0;
}

/*
 */
