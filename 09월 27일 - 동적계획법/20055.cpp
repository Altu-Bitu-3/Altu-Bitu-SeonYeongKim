// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(int n, int k, deque<int> &belt) {
    int turn=0;
    deque<bool> robot (n, false); // i번 칸 위에 로봇 존재여부를 알려주는 벡터
    
    while(true) {
        // 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료
        int zeroEndur = 0;
        for(int i=0; i<2*n; i++)
            if(belt[i]==0) zeroEndur++;
        if(zeroEndur >= k)
            break;
        
        // 턴 시작 !
        turn++;
        
        // 1. 벨트 회전시키기
        belt.push_front(belt.back());
        belt.pop_back();
        robot.push_front(robot.back()); // 벨트 회전과 함께 로봇도 회전한다 (로봇은 가만히 있으므로 내구도에 영향 안줌)
        robot.pop_back();
        robot[n-1] = false; // 로봇 내려놓기
        
        // 2. 로봇 이동시키기 (내구도에 영향을 주는 이동)
        for(int i=n-2; i>=0; i--) {
            // n-2번 벨트부터 0번 벨트가지 훑으며 로봇 이동시키기 ("먼저 올라간 로봇부터" 이동하므로 거꾸로 루프를 돌아야한다)
            if(robot[i] && !robot[i+1] && belt[i+1]>0) {
                // 로봇이 해당 위치에 있고, 가려는 위치에 로봇이 없고, 가려는 위치의 내구도가 괜찮다면 로봇 이동
                robot[i] = false;
                robot[i+1] = true;
                belt[i+1]--;
                
                if(i+1 == n-1)  // 도착한곳이 맨 끝이라면 로봇 내림
                    robot[i+1] = false;
            }
        }
        
        // 3. 로봇 올리기 (내구도에 영향 ㅇ)
        if(!robot[0] && belt[0]>0) { // 올리는 위치에 로봇이 없고 내구도가 괜찮다면
            robot[0] = true;
            belt[0]--;
        }
    }
    
    return turn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    deque<int> belt (2*n); // i번 칸에 있는 벨트의 내구도
    for(int i=0; i<2*n; i++)
        cin >> belt[i];
    
    cout << solution(n, k, belt);
    
    return 0;
}

/*
 */
