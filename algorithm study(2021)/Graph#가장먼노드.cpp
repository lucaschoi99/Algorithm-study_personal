#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <iostream>
#define NUM 20001
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0; 
    
    vector<int> edges[NUM];
    for(auto vi:edge){
        // Bi-directional edges
        edges[vi[0]].push_back(vi[1]);
        edges[vi[1]].push_back(vi[0]);
    }
    
    // Dijkstra - without priority queue
    // Cost 1 : queue is enough
    int dist[NUM];
    for(int i=1;i<=n;i++){
        dist[i] = INT_MAX;
    }
    queue<int> q;
    int start = 1;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()){
        int item = q.front();
        q.pop();
        
        // Update adjacent edges
        for(int i=0;i<edges[item].size();i++){
            int next = edges[item][i];
            if(dist[next] > dist[item] + 1){
                dist[next] = dist[item]+1;
                q.push(next);
            }
        }
    }
    
    // Find max distance
    int maxVal = dist[2];
    for(int i=3;i<=n;i++){
        if(maxVal < dist[i]){
            maxVal = dist[i];    
        }
    }
    for(int i=2;i<=n;i++){
        if(maxVal == dist[i]){
            answer++;
        }
    }
    return answer;
}