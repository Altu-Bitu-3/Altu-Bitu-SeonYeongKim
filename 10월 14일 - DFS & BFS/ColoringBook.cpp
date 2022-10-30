#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j] == 0) continue;
            
                    queue<pair<int,int>> q;

            number_of_area++;
            int area = 0;
            int color = picture[i][j];
                       
            q.push({i,j});
            picture[i][j] = 0;
            
            while(!q.empty()){
                area++;

                auto c = q.front();
                q.pop();
                
                for(int dir=0; dir<4; dir++){
                    int x = c.first + dx[dir];
                    int y = c.second + dy[dir];
                    
                    if(x<0 || x>=m || y<0 || y>=n) continue;
                    if(picture[x][y] != color) continue;
                    
                    q.push({x,y});
                    picture[x][y] = 0;
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }
                
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
