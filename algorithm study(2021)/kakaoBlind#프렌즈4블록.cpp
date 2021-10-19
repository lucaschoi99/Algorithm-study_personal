#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

char newBoard[30][30];
bool toVisit[30][30];
bool isCounted[30][30];
int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

int traverse(int row, int col){
    int ans = 0;
    for(int i=0;i<row-1;i++){
        for(int j=0;j<col-1;j++){
            if(toVisit[i][j]){
                char current = newBoard[i][j];
                int count = 0;
                int addSum = 0;
                
                // 오른쪽, 아래, 오른쪽아래 확인
                for(int k=0;k<3;k++){
                    char compare = newBoard[i+dx[k]][j+dy[k]];
                    if(current == compare){
                        count++;
                    }
                }
                if(count == 3){ // 2*2 만족 + 추가할 개수 계산
                    if(!isCounted[i][j]){ addSum++; isCounted[i][j] = true;}
                    
                    for(int k=0;k<3;k++){
                        if(!isCounted[i+dx[k]][j+dy[k]]){
                            addSum++;
                            isCounted[i+dx[k]][j+dy[k]] = true;
                        }
                    } 
                }
                ans += addSum;
            }
        }
    }
    return ans;
}

void pullDown(int row, int col){
    // 모양 제거
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(isCounted[i][j]){
                newBoard[i][j] = '0'; 
            }
        }
    }
    
    // 모양 아래로 내리기
    for(int i=0;i<row-1;i++){
        for(int j=0;j<col;j++){
            // 빈칸이 아니고, 아래칸들이 비어있으면 이동
            if(newBoard[i][j] != '0'){
                int idx = i;
                while(true){
                    bool isBlank = (newBoard[idx+1][j] == '0');
                    if(!isBlank){ break;}
                    else{
                        for(int zi=idx;zi>=0;zi--){
                            newBoard[zi+1][j] = newBoard[zi][j];
                            newBoard[zi][j] = '0';
                        }
                    }
                    idx++;
                }
            }
        }
    }
}

void fillBoard(int row, int col, vector<string> board){
    memset(newBoard, '0', sizeof(newBoard));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            newBoard[i][j] = board[i][j];
        }
    }
}

void init(int row, int col){
    memset(toVisit, false, sizeof(toVisit));
    memset(isCounted, false, sizeof(isCounted));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(newBoard[i][j] != '0'){
                toVisit[i][j] = true;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    // Init
    fillBoard(m,n,board);
    init(m,n);
    
    // Traversal
    while(true){
        int returnVal = traverse(m,n);
        if(returnVal == 0){
            break;
        }
        answer += returnVal;
        pullDown(m,n);
        init(m,n);
    }
    
    return answer;
}