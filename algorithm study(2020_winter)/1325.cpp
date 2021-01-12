#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 10001;
int n,m; //n computers, m relationships

//initialize vectors
vector<int> v[MAX];
vector<int> ans;
bool *visited = new bool[MAX];

//dfs
void dfs(int start){
    visited[start] = true;
    
    for(int vv : v[start]){
        if(!visited[vv]){
            ans[vv]++;
            dfs(vv);
        }
    }

}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    //initialize
    ans.resize(n+1,0);

    //input relationships btw computers
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    //make connection
    for(int i=1;i<n+1;i++){
        visited = new bool[n+1];
        dfs(i);
    }
    
    //output
    int max = *max_element(ans.begin(),ans.end());
    vector<int>::iterator iter;
    for(iter=ans.begin(); iter != ans.end();iter++){
        if(*iter == max){
            int index = distance(ans.begin(), iter);
            cout << index << " ";
        }
    }
   
  
    return 0;
}
