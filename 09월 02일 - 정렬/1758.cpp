// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int cal_tip(int n, vector<long long int> v) {
    long long int tip = 0;
    for(int i=0; i<n; i++) {
        long long int tmp = v[i] - i;
        if(tmp>=0) tip += tmp;
    }
    return tip;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), greater<>());
    
    cout << cal_tip(n, v);
    
    return 0;
}

/*
 */
