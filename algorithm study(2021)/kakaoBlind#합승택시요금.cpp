#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <iostream>
#define NUM 201
#define MAX 487654321

using namespace std;

struct edges{
    int cost;
    int dest;
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    
    // Edges 정보
    vector<edges> newEdge[NUM];
    for(auto info:fares){
        int start = info[0];
        int end = info[1];
        int cost = info[2];
        newEdge[start].push_back({cost, end});
        newEdge[end].push_back({cost, start});
    }
    
    // Floyd-Warshall
    int dist[NUM][NUM];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = MAX;
            }
        }
    }
    
    // dist 배열 init
    for(int i=1;i<=n;i++){
        for(int j=0;j<newEdge[i].size();j++){
            int next = newEdge[i][j].dest;
            int cost = newEdge[i][j].cost;
            
            dist[i][next] = min(dist[i][next], cost);
        }
    }
    
    // 모든 node에 대해 최단거리 계산 -> O(N^3)
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // i ---- k ---- j (k는 경유지)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);   
            }
        }
    }
    
    // 합승 도착지(경유지) -> 완전탐색
    for(int i=1;i<=n;i++){
        long long sum = dist[s][i];
        sum += dist[i][a];
        sum += dist[i][b];
        
        if(answer > sum){
            answer = sum;
        }
    }
    
    return answer;
}