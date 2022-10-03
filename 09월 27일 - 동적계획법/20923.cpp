// Authored by : seondal
// Co-authored by : -

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> doCard, suCard;
deque<int> doGround, suGround;

// 종친사람의 카드덱에 상대의 그라운드 덱과 자신의 그라운드 덱을 합치는 합수
void mergeCard(deque<int> &winnerCard, deque<int> &loserGround, deque<int> &winnerGround) {
    for(int i=0; !loserGround.empty(); i++) {
        winnerCard.push_front(loserGround.front());
        loserGround.pop_front();
    }
    for(int i=0; !winnerGround.empty(); i++) {
        winnerCard.push_front(winnerGround.front());
        winnerGround.pop_front();
    }
}

// 그라운드에 카드를 내놓을때마다 종 칠 여부를 결정하여 종을 친다.
void hitBell() {
    // groundTop=0 : 그라운드가 비어있음
    int doGroundTop=0, suGroundTop=0;
    if(!doGround.empty())
        doGroundTop = doGround.back();
    if(!suGround.empty())
        suGroundTop = suGround.back();
    
    // 수연이가 종침 (그라운드가 비어있지 않아야하고, 합이 5여야함)
    if(doGroundTop!=0 && suGroundTop!=0 && doGroundTop+suGroundTop==5)
        mergeCard(suCard, doGround, suGround);
    
    // 도도가 종침 (둘중 하나가 5여야함)
    if(doGroundTop==5 || suGroundTop==5)
        mergeCard(doCard, suGround, doGround);
    
    // 종 안침
    return;
}

string solution(int n, int m) {
    // 할리갈리 수행
    bool doTurn = true;
    while(m--){
        if(doTurn) {
            // 인덱스가 작을수록 아래쪽에 위치한 카드 => back이 카드의 꼭대기쪽 방향이다
            doGround.push_back(doCard.back());
            doCard.pop_back();
            if(suCard.empty() || doCard.empty()) break; // 둘 중 한명이라도 갯수가 0이되면 게임 종료
            hitBell();
        } else {
            suGround.push_back(suCard.back());
            suCard.pop_back();
            if(suCard.empty() || doCard.empty()) break;
            hitBell();
        }
        
        doTurn = !doTurn;
    }

    // 승자 결정
    if(suCard.size() > doCard.size())
        return "su";
    else if (suCard.size() < doCard.size())
        return "do";
    else
        return "dosu";
}

int main() {
    int n,m;
    cin >> n >> m;
    doCard.assign (n,0);
    suCard.assign (n,0);
    for(int i=0; i<n; i++)
        cin >> doCard[i] >> suCard[i];

    cout << solution(n, m);
    
    return 0;
}

/*
 */
