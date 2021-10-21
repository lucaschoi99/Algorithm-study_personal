#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

bool isVisited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init(int row, int col){
    memset(isVisited, false, sizeof(isVisited));
}

int dfs(int row, int col, vector<vector<int>> picture, int maxRow, int maxCol){
    int areaSize = 1;
    isVisited[row][col] = true;

    // 상하좌우 확인 Joystick
    for(int a=0;a<4;a++){
        // 범위 확인
        if(row+dx[a] < 0 || row+dx[a] >= maxRow || col+dy[a] < 0 || col+dy[a] >= maxCol){
            continue;
        }
        
        if(!isVisited[row+dx[a]][col+dy[a]] && picture[row+dx[a]][col+dy[a]] == picture[row][col]){
            areaSize += dfs(row+dx[a], col+dy[a], picture, maxRow, maxCol);
        }
    }
    
    return areaSize;
}




// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    init(m,n);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!isVisited[i][j] && picture[i][j] != 0){
                number_of_area++;
                int size = 0;
                size += dfs(i,j,picture, m, n);
                if(size > max_size_of_one_area){
                    max_size_of_one_area = size;
                }
            }
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}