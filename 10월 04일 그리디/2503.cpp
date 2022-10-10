// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct input {
    string number;
    int strike;
    int ball;
};

int n;
vector<input> v;

// 정답문자열이 i번째 케이스에 해당하는지 여부를 반환하는 함수
bool isCaseRight(int i, string ansString) {
        string num = v[i].number;
        int b=0, s=0;
        
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(num[j]==ansString[k]) {
                    if(j==k)
                        s++;
                    else
                        b++;
                }
            }
        }
        
        if(b==v[i].ball && s==v[i].strike)
            return true;
        return false;
}

// i개의 케이스중 단 하나라도 안맞으면 false
bool isNumRight(string ansString) {
    for(int i=0; i<n; i++)
        if(!isCaseRight(i, ansString))
            return false;
    return true;
}

int solution() {
    int ans=0;
    
    for(int i=123; i<999; i++) {
        // 답이될 수 있는 문자열들을 전부 다 돌아본다. (부르트포스)
        string ansString = to_string(i);
        
        // 답 숫자열에는 숫자 0을 제외한 서로 다른 숫자로 이루어져있어야한다.
        if(ansString[0]=='0' || ansString[1]=='0' || ansString[2]=='0')
            continue;
        if(ansString[0]==ansString[1] || ansString[1]==ansString[2] || ansString[2]==ansString[0])
            continue;
        
        if(isNumRight(ansString))
            ans++;
    }
    
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        string n;
        int s,b;
        cin >> n >> s >> b;
        v.push_back({n,s,b});
    }
    
    cout << solution();
    
    return 0;
}

/*
 */
