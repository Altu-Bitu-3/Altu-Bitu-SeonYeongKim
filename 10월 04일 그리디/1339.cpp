// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<string>&word) {
    vector<int> weight(26, 0); // 알파벳들의 가중치를 담는 벡터
    for(int i=0; i<n; i++) {
        int length = word[i].size();
        for(int j=0; j<length; j++)
            weight[word[i][j]-'A'] += pow(10, length-1-j); // 해당 알파벳이 가지는 가중치를 벡터에 넣어준다
    }
    
    sort(weight.begin(), weight.end(), greater<>()); // 가중치 내림차순 정렬
    
    int sum = 0;
    int tmp = 9;  // 배정할 값 -> 가중치가 큰 순서대로 바로 곱해서 더해줌
    for(int i=0; i<10; i++) { // 알파벳 종류는 10개를 넘지 않음
        sum += tmp * weight[i];
        tmp--;
    }
    
    return sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> word(n);
    for(int i=0; i<n; i++)
        cin >> word[i];
 
    cout << solution(n, word);
    
    return 0;
}

/*
 */
