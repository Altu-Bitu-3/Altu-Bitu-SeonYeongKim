// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<string> v;

// s1 과 s2가 같은 사이클 단어인지 판별하는 함수
bool cycleWord(string s1, string s2) {
    for(int k=0; k<s1.size(); k++) {
        if(strcmp(s1.c_str(), s2.c_str()) == 0)
            return true;
        
        s1.push_back(s1.front());
        s1.erase(0,1);
    }
    return false;
}

// 문자열 벡터 내에 i번째 문자열과 같은 사이클단어가 있는지 판별하는 함수
bool isThereSame(int i) {
    for(int j=i+1; j<v.size(); j++) {
        if(cycleWord(v[i], v[j]))
            return true;
    }
    return false;
}

// 서로 단어의 개수 카운트
int solution(int n) {
    int ans=0;
    
    for(int i=0; i<n; i++) {
        if(!isThereSame(i))
            ans++;
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    v.assign(n,"");
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    cout << solution(n);
    
    return 0;
}

/*
 */
