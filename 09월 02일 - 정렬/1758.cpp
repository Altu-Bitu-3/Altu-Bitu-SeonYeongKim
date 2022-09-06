// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    
    vector<long long int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    sort(v.begin(), v.end(), cmp);
    
    long long int tip = 0;
    for(int i=0; i<n; i++) {
        long long int tmp = v[i] - i;
        if(tmp<0) tmp = 0;
        tip += tmp;
    }
    
    cout << tip;
    
    return 0;
}

/*
 */
