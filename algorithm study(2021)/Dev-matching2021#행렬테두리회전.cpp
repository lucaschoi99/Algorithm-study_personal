#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define NUM 101

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 2차원 행렬
    int mat[NUM][NUM] = {-1,};
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            mat[i-1][j-1] = (i-1) * columns + j;
        }
    }
    
    // Queries
    for(auto qr:queries){
        int x1 = qr[0]; int y1 = qr[1]; int x2 = qr[2]; int y2 = qr[3];
        queue<int> temp;
        
        // x1행 y1열부터 오른쪽 방향
        temp.push(mat[x1-1][y1-1]);
        int minVal = temp.front();
        for(int i=y1-1;i<y2-1;i++){
            temp.push(mat[x1-1][i+1]);
            minVal = min(minVal, temp.back());
            mat[x1-1][i+1] = temp.front();
            temp.pop();
        }
        
        // x1행 y2열부터 아래 방향
        for(int i=x1-1;i<x2-1;i++){
            temp.push(mat[i+1][y2-1]);
            minVal = min(minVal, temp.back());
            mat[i+1][y2-1] = temp.front();
            temp.pop();
        }
        
        // x2행 y2열부터 왼쪽 방향
        for(int i=y2-1;i>y1-1;i--){
            temp.push(mat[x2-1][i-1]);
            minVal = min(minVal, temp.back());
            mat[x2-1][i-1] = temp.front();
            temp.pop();
        }
        
        // x2행 y1열부터 위 방향
        for(int i=x2-1;i>x1-1;i--){
            temp.push(mat[i-1][y1-1]);
            minVal = min(minVal, temp.back());
            mat[i-1][y1-1] = temp.front();
            temp.pop();
        }
        
        answer.push_back(minVal);
        
    }
    
    return answer;
}