#include <iostream>
#include <vector>
using namespace std;

int n,m;
const int MAX = 1001;
// Graph
vector<int> graph[MAX];
bool check[MAX];

void dfs(int start){
    check[start] = true;

    for(int i=0;i<graph[start].size();i++){
        int nxt = graph[start][i];
        if(!check[nxt]){
            dfs(nxt);
        }
    }

}


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int cnt=0;

    while(m--){
        int u, v;
        cin >> u >> v;

        //insert both sides
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<n+1;i++){
        //not visited
        if(!check[i]){dfs(i); cnt++;}
    }
    cout << cnt;
}