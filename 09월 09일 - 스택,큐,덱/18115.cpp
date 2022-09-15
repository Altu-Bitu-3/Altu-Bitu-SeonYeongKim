// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <deque>

using namespace std;
    
int main() {
    int n;
    cin >> n;
    stack<int> skills;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        skills.push(input);
    }
    deque<int> ans;
    
    for(int i=1; i<=n; i++){  // i번째 수행때는 i번 카드를 움직인다
        int skill = skills.top();
        skills.pop();  // 스킬을 최근것부터 꺼내서 거꾸로 수행
        
        switch (skill) {
            case 1:  // 제일 위의 카드 1장을 바닥에 내려놓는다. -> i 카드를 맨 위로 넣는다
                ans.push_front(i);
                break;
                
            case 2:  // 위에서 두 번째 카드를 바닥에 내려놓는다. -> i 카드를 위에서 두번째 위치로 넣는다
            {
                int top_card = ans.front();
                ans.pop_front();
                ans.push_front(i);
                ans.push_front(top_card);
                break;
            }
                
            case 3:  // 제일 밑에 있는 카드를 바닥에 내려놓는다. -> i 카드를 제일 밑으로 넣는다
                ans.push_back(i);
                break;
        }
    }
    
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop_front();
    }
    
    return 0;
}

/*
 */
