#include <string>
#include <vector>
#define MAX 101

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // DP
    long long dp[MAX][MAX];
    dp[1][1] = 1;
    
    // Puddles 위치 확인
    for(auto vi:puddles){
        dp[vi[0]][vi[1]] = -1;
    }
    
    // 시작점에서 (UP), (LEFT) 방향 확인하면서 도착지까지 진행
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // 물 웅덩이인지 확인
            if(dp[j][i] == -1){
                dp[j][i] = 0;
                continue;
            }
            
            // Boundary 확인
            if(i == 1 && j == 1){
                continue; // 시작점 skip
            }
            if(j == 1){ // UP 방향이 없을 경우
                dp[j][i] = dp[j][i-1];
                continue;
            }
            if(i == 1){ // LEFT 방향이 없을 경우
                dp[j][i] = dp[j-1][i];
                continue;
            }
            
            // UP, LEFT 좌표에 물 웅덩이가 존재하는지 확인
            dp[j][i] = dp[j-1][i] % 1000000007 + dp[j][i-1] % 1000000007;
            
        }
    }
    answer = dp[m][n] % 1000000007;
    
    
    return answer;
}