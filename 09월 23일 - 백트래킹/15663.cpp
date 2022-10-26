// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int input[10];  // 입력받은 수열
bool used[10];  // i번째 수를 사용했는지 여부 (중복 방지)
int arr[10];  // 출력할 수열

void recur(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int tmp = 0;
    for(int i=0; i<n; i++) {
        if(!used[i] && tmp != input[i]) {
            arr[k] = input[i];
            used[i] = true;
            tmp = input[i];
            recur(k+1);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0; i<10; i++) input[i] = 10000;
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> input[i];
    sort(begin(input), end(input));
    
    recur(0);
    
    return 0;
}

/*
 */