// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMultiple(string &s){
    int sum=0;
    for(int i=0; i<s.size(); i++)
        sum += s[i]-'0';
    
    // 만약 각 자리의 합이 3의 배수이고, 가장 작은 숫자가 0이면(=0이 포함되어있다면)
    if(sum%3==0 && s[0]=='0')
        return true;
    
    return false;
}

string solution(string s){
    sort(s.begin(), s.end());
    
    if(isMultiple(s)) {
        reverse(s.begin(), s.end());
        return s;
    }
    
    return "-1";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    
    cout << solution(s);
    
    return 0;
}

/*
 */
