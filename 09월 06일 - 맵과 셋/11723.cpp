// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<bool> v(21, false);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string op;
        int value;
        cin >> op;
        
        if(op == "add") {
            cin >> value;
            v[value] = true;
            
        } else if(op == "remove") {
            cin >> value;
            v[value] = false;
            
        } else if(op == "check") {
            cin >> value;
            if(v[value]) cout << 1 << "\n";
            else cout << 0 << "\n";
            
        } else if(op == "toggle") {
            cin >> value;
            if(v[value]) v[value] = false;
            else v[value] = true;
            
        } else if(op == "all") {
            for(int i=1; i<=20; i++)
                v[i] = true;
            
        } else if(op == "empty") {
            for(int i=1; i<=20; i++)
                v[i] = false;
        }
    }
    
    return 0;
}

/*
 */
