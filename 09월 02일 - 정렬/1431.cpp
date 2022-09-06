// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumNum(string s) {
    int ans = 0;
    for(int i=0; i<s.size(); i++)
        if(s[i] >= '0' && s[i] <= '9') ans += s[i]-'0';
    return ans;
}

bool cmp(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    if(sumNum(a) != sumNum(b)) return sumNum(a) < sumNum(b);
    else return a < b;
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
