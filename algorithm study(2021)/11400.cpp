#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define NUM 100001

vector<int> edge[NUM];
int visited[NUM]= {0,};
int cnt = 1;
vector<int> isAnswer[NUM];

int dfs(int start, int parent){
    visited[start] = cnt;
    cnt++;
    int ret = visited[start];

    // Children dfs
    for(int i=0;i<edge[start].size();i++){
        int next = edge[start][i];
        if(next == parent){ // Cannot go backward
            continue;
        }
        if(visited[next] == 0){ // Not visited yet
            int low = dfs(next, start);
            
            // Not root, lowest num of children's visited >= start visited num
            // start node is the answer
            if(visited[start] < low){
                isAnswer[start].push_back(next);
            }
            
            ret = min(ret, low);
        }
        else{ // Already visited or Ancestor node
            ret = min(ret, visited[next]);
        }
    }
    
    return ret;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int V,E;
    cin >> V >> E;

    for(int i=1;i<=E;i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    
    // DFS once since graph <- all connected
    dfs(1,0);
    
    // Print answer
    int countAnswer = 0;
    vector<int> ansIdx;

    for(int i=1;i<=V;i++){
        if(isAnswer[i].size() > 0){
            countAnswer += isAnswer[i].size();
            ansIdx.push_back(i);
        }
    }

    vector<pair<int,int>> sorted;
    cout << countAnswer << "\n";
    for(int vi:ansIdx){
        for(int i=0;i<isAnswer[vi].size();i++){
            sorted.push_back(pair<int,int>(min(vi, isAnswer[vi][i]),max(vi, isAnswer[vi][i])));
        }
    }
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<sorted.size();i++){
        cout << sorted[i].first << " " << sorted[i].second << "\n";
    }

}
