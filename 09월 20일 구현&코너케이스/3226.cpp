// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int cost = 0;
    while(n--) {
        int h, m, d;
        scanf("%d:%d", &h, &m);
        cin >> d;
        
        // 끝나는 분 계산 (총 통화시간이 60을 넘기지 않으므로 시간은 계산할 필요 없다)
        int endMin = (m+d)%60;
        
        if(h==6)
            // 5원으로 시작했다가 10원으로 끝나는 경우
            cost += 5*(60-m) + 10*endMin;
        else if(h==18)
            // 10원으로 시작했다가 5원으로 끝나는 경우
            cost += 10*(60-m) + 5*endMin;
        else if(7<=h && h<=19)
            // 처음부터 끝까지 10원인 경우
            cost += 10*d;
        else
            // 처음부터 끝까지 5원인 경우
            cost += 5*d;
    }
    
    cout << cost;
    
    return 0;
}

/*
 */
