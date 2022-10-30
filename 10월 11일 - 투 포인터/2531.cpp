// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 인자로 받은 eat 큐 내의 초밥의 종류의 갯수를 카운트해서 리턴
int countKind(deque<int> q, int k, int d, int c) {
    vector<bool> isEat(d+1, false);
    isEat[c] = true;
    
    for(int i=0; i<k; i++) {
        isEat[q.front()]=true;
        q.pop_front();
    }
    
    int kind = 0;
    for(int i=1; i<=d; i++) {
        if(isEat[i])
            kind++;
    }
    
    return kind;
}

// 먹을 수 있는 초밥의 최대 가짓수
int maxKind(int n, int d, int k, int c, vector<int>&sushi) {
    deque<int> eat;
    for(int i=0; i<k; i++)
        eat.push_back(sushi[i]);
    
    int max_kind = countKind(eat, k, d, c);
        
    for(int i=k; i<n+k; i++) {
        int end = i>=n ? i-n : i;  // 슬라이딩 윈도우에 추가할 인덱스 (sushi 벡터를 회전해야하므로 예외처리)

        eat.pop_front();
        eat.push_back(sushi[end]);

        max_kind = max(max_kind, countKind(eat, k, d, c));
    }
    
    return max_kind;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for(int i=0; i<n; i++)
        cin >> sushi[i];

    cout << maxKind(n, d, k, c, sushi);
    
    return 0;
}

/*
 */

