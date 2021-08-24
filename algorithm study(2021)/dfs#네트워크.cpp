#include <string>
#include <vector>
#define MAX 201

using namespace std;

vector<int> edges[MAX];
bool visited[MAX] = {false,};

void dfs(int num){
    // Check visited
    visited[num] = true;
    for(int i=0;i<edges[num].size();i++){
        // Recursive call
        if(!visited[edges[num][i]]){
            dfs(edges[num][i]);    
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int k=0;k<computers[i].size();k++){
            if(i != k && computers[i][k]){ // Push edges
                edges[i].push_back(k);
            }
        }
    }
    
    // DFS on every edges
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            dfs(i);    
        }
        
    }
    
    return answer;
}