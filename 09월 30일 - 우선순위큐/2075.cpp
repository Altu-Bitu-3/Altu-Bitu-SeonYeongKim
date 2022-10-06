// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n*n);
    for(int i=0; i<n*n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end(), greater<>());
    
    cout << v[n-1];
    

    return 0;
}

/*
 강의에서 배운 우선순위큐를 쓰고 싶었는데 쓰는 방법을 몰라서 일단 벡터로 풀었습니다 ㅠ_ㅠ
 */
