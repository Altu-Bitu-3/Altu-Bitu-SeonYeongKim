// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> swit;

void toggle(int index) {
    swit[index] = !swit[index];
    return;
}

void boy(int num) {
    for(int i=1; i<=n; i++)
        if(i%num == 0)
            toggle(i);
    return;
}

void girl(int num) {
    toggle(num);  // 중앙은 무조건 바꾼다
    
    for(int i=1; true; i++) {
        int left = num-i;
        int right = num+i;
        
        if(left < 1 || right > n || swit[left] != swit[right])
            return;  // 인덱스를 넘어서거나 대칭이 아니라면 종료
        
        toggle(left);
        toggle(right);
    }
}


void solution(int gender, int number) {
    if(gender==1)
        boy(number);
    else
        girl(number);
    
    return;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> n;
    swit.assign(n+1, 0);
    for(int i=1; i<=n; i++)
        cin >> swit[i];
    
    // 풀이
    int m;
    cin >> m;
    while(m--) {
        int gender, number;
        cin >> gender >> number;
        solution(gender, number);
    }
    
    // 출력
    for(int i=1; i<=n; i++) {
        cout << swit[i] << " ";
        
        if(i%20 == 0)
            cout << "\n";
    }
    
    return 0;
}

/*
 */
