// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int getGcd(int n, int m) {
    if(m == 0) return n;
    return getGcd(m, n%m);
}

int main() {
    int n, m;
    scanf("%d:%d", &n, &m);
    
    int gcd = getGcd(n, m);
    
    cout << n/gcd << ":" << m/gcd;
    
    return 0;
}

/*
 */
