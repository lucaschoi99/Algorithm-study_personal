#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<int> indegree(n+1,0);
    vector<vector<int>> edge(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;

        indegree[b]++;
        edge[a].push_back(b);
    }
    
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<n+1;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int item = q.front();
        q.pop();
        ans.push_back(item);
        //cout << "item: " << item << "\n";

        for(int j=0;j<edge[item].size();j++){
            indegree[edge[item][j]]--;
            if(indegree[edge[item][j]] == 0){
                q.push(edge[item][j]);
            }
        }
    }

    for(int vi:ans){
        cout << vi << " ";
    }
    
}
