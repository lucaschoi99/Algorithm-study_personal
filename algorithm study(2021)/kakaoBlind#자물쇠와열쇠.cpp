#include <string>
#include <vector>
#include <iostream>
#define NUM 60

using namespace std;

vector<vector<pair<int,int>>> keyInfo;

void rotate(vector<vector<pair<int,int>>> info, int size){
    
    // 시계방향 90도 회전 Key정보
    vector<pair<int,int>> temp_90;
    for(int j=0;j<info[0].size();j++){
        temp_90.push_back(pair<int,int>(info[0][j].second, (size-1) - info[0][j].first));
    }
    keyInfo.push_back(temp_90);
    
    // 180도 회전
    vector<pair<int,int>> temp_180;
    for(int j=0;j<info[0].size();j++){
        temp_180.push_back(pair<int,int>(temp_90[j].second, (size-1) - temp_90[j].first));
    }
    keyInfo.push_back(temp_180);
    
    // 270도 회전
    vector<pair<int,int>> temp_270;
    for(int j=0;j<info[0].size();j++){
        temp_270.push_back(pair<int,int>(temp_180[j].second, (size-1) - temp_180[j].first));
    }
    keyInfo.push_back(temp_270);
    
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<pair<int,int>> target;
    
    // Key 돌기 정보
    vector<pair<int,int>> vec;
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key[i].size();j++){
            if(key[i][j] == 1){
                vec.push_back(pair<int,int>(i,j));
            }
        }
    }
    keyInfo.push_back(vec);
    
    // 3번 rotation 시행
    rotate(keyInfo, key.size());
    
    // Lock 홈 정보
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock[i].size();j++){
            if(lock[i][j] == 0){
                target.push_back(pair<int,int>(i,j));
            }
        }
    }
    
    // Lock보다 가로,세로가 3배인 자물쇠 배열 생성
    int extendedLock[NUM][NUM] = {0,};
    for(int i=0;i<3*lock.size();i++){
        for(int j=0;j<3*lock.size();j++){
            if(i >= lock.size() && i < 2*lock.size() && j >= lock.size() && j < 2*lock.size()){
                extendedLock[i][j] = lock[i-lock.size()][j-lock.size()];
            }
            else{
                extendedLock[i][j] = 0;
            }
        }
    }
    
    // 자물쇠 홈 정보 update
    vector<pair<int,int>> extendedTarget;
    for(int i=0;i<target.size();i++){
        extendedTarget.push_back(pair<int,int>(target[i].first + lock.size(), target[i].second + lock.size()));
    }
    
    // 자물쇠를 Lock보다 가로,세로가 3배인 자물쇠 배열에 대입 - 완전탐색
    int ansCnt = 0;
    bool isAnswer = false;
    for(int i=0;i<3*lock.size();i++){
        for(int j=0;j<3*lock.size();j++){
            for(int k=0;k<keyInfo.size();k++){
                bool flag = true;
                for(int m=0;m<keyInfo[k].size();m++){
                    for(int x=0;x<extendedTarget.size();x++){
                        // 자물쇠 돌기와 Key돌기가 만나는 경우 배제
                        if(extendedLock[i+keyInfo[k][m].first][j+keyInfo[k][m].second] == 1){
                            flag = false;
                        }
                        // 자물쇠 홈과 Key돌기가 만나는 경우 count
                        if(i+keyInfo[k][m].first == extendedTarget[x].first && j+keyInfo[k][m].second == extendedTarget[x].second){
                            ansCnt++;
                            break;
                        }
                    }
                }
                if(ansCnt == target.size() && flag){ // 모든 홈이 맞춰짐
                    return true;
                }
                else{
                    ansCnt = 0; // 계속 진행
                }
            }
        }
    }
    if(!isAnswer){ // 모든 홈을 맞출수 있는 방법이 없음
        return false;
    }
}