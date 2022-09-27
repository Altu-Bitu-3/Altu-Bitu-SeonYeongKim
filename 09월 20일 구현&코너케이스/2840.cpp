#include <algorithm> //
#include <iostream> // 기본 입출력을 위함
#include <vector> // 기본 벡터 연산을 위함

using namespace std; // std:: 생략

typedef pair<int, char> ci;  // 자주쓰일 pair의 타입을 이름으로 미리 지정해둠

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

//특정 화살표 index에서 시작한 크기가 n인 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char> &wheel) {
    string ans = ""; // 답 문자열 초기화

    for (int i = n; i > 0; i--) { // 바퀴 크기만큼 반복문 훑기
        ans += wheel[(i + index) % n]; // 답 문자열에 바퀴 글자 추가하기
    }

    return ans; // 답 문자열 리턴
}

string makeWheel(int n, vector<ci> &record) { // 행운의 바퀴를 리턴하는 문자열을 구하는 함수
    vector<char> wheel(n, '?');           // 바퀴를 ?로 초기화
    vector<bool> is_available(26, false); // i번째 알파벳이 사용되었는지 여부를 체크하는 불 벡터

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) { // 입력받은 record 벡터 훑으며 연산
        int rot = record[i].first; // rot = 화살표가 가리키는 글자가 바뀐 횟수
        int ch = record[i].second; // ch = 회전을 멈추었을 때 가리키던 글자

        index = (index + rot) % n; //화살표 이동 (한바퀴를 넘었을때를 대비하여 n으로 나눈 나머지 연산 수행)

        if (wheel[index] == ch) { // 이미 있는 글자일경우 패스
            continue;
        }

        // 주의사항 체크
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            // 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
            return "!"; // 느낌표 (!) 리턴
        }

        wheel[index] = ch; // 나온 글자를 wheel 벡터에 저장
        is_available[ch - 'A'] = true; // 2번 조건(바퀴에 같은글자는 두 번 이상 등장하지 않는다)을 위해 체크하기
    }

    return arrowStartWheel(index, n, wheel); // wheel벡터를 문자열 형태로 변환하여 답 문자열 리턴
}

int main() {
    int n, k; // 바퀴의 수와 바퀴를 돌리는 횟수
    cin >> n >> k; // 입력받기

    vector<ci> record(k, {0, 0}); // 입력 값들을 저장하는 벡터
    for (int i = 0; i < k; i++) { // k번 돌렸으므로 벡터의 크기는 k
        cin >> record[i].first >> record[i].second;
        // {화살표가 가리키는 글자가 바뀐 횟수, 회전을 멈추었을때 가리키던 글자}의 형태로 벡터에 저장
    }

    //출력
    cout << makeWheel(n, record);
}
