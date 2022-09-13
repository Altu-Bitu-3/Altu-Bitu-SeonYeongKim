// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;
    
int main() {
    string input;
    
    int case_num = 1;
    
    while(getline(cin, input)) {
        if(input[0]=='-') {
            break;
        }
        
        stack<char> s;
        for(int i=0; i<input.size(); i++) {
            if(input[i] == '}' && !s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(input[i]);
        }

        int ans = 0;
        while(!s.empty()) {
            char first = s.top();
            s.pop();
            char second = s.top();
            s.pop();
            
            if(first == second) ans++;
            else ans += 2;
        }
        
        cout <<  case_num << ". " << ans << "\n";
        case_num++;
    }
    
    return 0;
}

/*
 */
