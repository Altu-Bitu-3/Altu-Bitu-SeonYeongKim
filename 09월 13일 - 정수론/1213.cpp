// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string ans;
    
    // 문자열에 들어간 알파벳 갯수 세기
    vector<int> alphabet(26, 0);
    for(int i=0; i<s.size(); i++)
        alphabet[s[i]-'A']++;
    
    // 개수가 홀수인 알파벳 카운트하기
    int odd = -1;
    for(int i=0; i<26; i++) {
        if(alphabet[i] % 2 == 1) { // 홀수 개수인 알파벳이 있다면
            if(odd != -1) return "I'm Sorry Hansoo";  // 이미 홀수 개수인 알파벳이 있을 경우
            odd = i;  //  홀수 개수인 알파벳 보관
        }
    }
    
    // 답 문자열 반쪽 구하기
    string halfAns;
    for(int i=0; i<26; i++) {
        for(int j=0; j<alphabet[i]/2; j++) {
            halfAns.push_back(i+'A');
        }
    }
    
    // 구한 반쪽문자열 추가하고, 센터에 알파벳(있다면) 넣고, 반쪽문자열 뒤집어서 추가
    ans += halfAns;
    
    if(odd != -1) ans.push_back(odd+'A');
    
    reverse(halfAns.begin(), halfAns.end());
    ans += halfAns;
    
    return ans;
}

int main() {
    string input;
    cin >> input;

    string ans = solution(input);
    
    cout << ans;
    
    return 0;
}

/*
 */
