#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto elem:places){
        char room[5][5];
        vector<pair<int,int>> ppl;
        bool flag = false;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                room[i][j] = elem[i][j];
                if(room[i][j] == 'P'){ // 사람 좌석 기억
                    ppl.push_back(pair<int,int>(i,j));
                }
            }
        }
        
        // 사람 좌석마다 거리두기 확인
        for(int i=0;i<ppl.size();i++){
            int row = ppl[i].first;
            int col = ppl[i].second;
            
            // 상하좌우, 대각선, 두 칸 떨어진 상하좌우 검사
            if(row > 0){
                if(room[row-1][col] == 'P'){ flag = true; break;}
                // 왼쪽 위 대각선
                if(col > 0){
                    if(room[row-1][col-1] == 'P' && (room[row-1][col] != 'X' || room[row][col-1] != 'X')){ flag = true; break;}
                }
                // 오른쪽 위 대각선
                if(col < 4){
                    if(room[row-1][col+1] == 'P' && (room[row-1][col] != 'X' || room[row][col+1] != 'X')){ flag = true; break;}
                }
                // 두 칸 위의 칸
                if(row > 1){
                    if(room[row-2][col] == 'P' && room[row-1][col] != 'X'){ flag = true; break;}
                }
            }
            if(row < 4){
                if(room[row+1][col] == 'P'){ flag = true; break;}
                // 왼쪽 아래 대각선
                if(col > 0){
                    if(room[row+1][col-1] == 'P' && (room[row][col-1] != 'X' || room[row+1][col] != 'X')){ flag = true; break;}
                }
                // 오른쪽 아래 대각선
                if(col < 4){
                    if(room[row+1][col+1] == 'P' && (room[row][col+1] != 'X' || room[row+1][col] != 'X')){ flag = true; break;}
                }
                // 두 칸 아래 칸
                if(row < 3){
                    if(room[row+2][col] == 'P' && room[row+1][col] != 'X'){ flag = true; break;}
                }
            }
            if(col > 0){
                if(room[row][col-1] == 'P'){ flag = true; break;}
                // 두 칸 좌측칸
                if(col > 1){
                    if(room[row][col-2] == 'P' && room[row][col-1] != 'X'){ flag = true; break;}
                }
            }
            if(col < 4){
                if(room[row][col+1] == 'P'){ flag = true; break;}
                // 두 칸 우측칸
                if(col < 3){
                    if(room[row][col+2] == 'P' && room[row][col+1] != 'X'){ flag = true; break;}
                }
            }
        }
        
        if(flag){ answer.push_back(0);}
        else{ answer.push_back(1);}
    }
    
    
    return answer;
}