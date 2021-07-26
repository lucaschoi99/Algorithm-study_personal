#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define NUM 100000
#define MAX 18

int n;
int K = 1;
int parent[MAX][NUM+1];
int depth[NUM+1] = {0,};
vector<int> tree[NUM+1];

void dfs(int id, int cnt){
    depth[id] = cnt;
    
    for(int i=0;i<tree[id].size();i++){
        if(depth[tree[id][i]] == 0){ // Not visited
            dfs(tree[id][i], cnt+1);
            parent[0][tree[id][i]] = id;
        }
    }
    return;
}

void fillParent(){ // DP
    for(int i=1;i<K;i++){
        for(int j=1;j<n+1;j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}


int lca(int a, int b){
    // Maintain "a vertex" deeper
    if(depth[a] < depth[b]){
        int temp = a;
        a = b;
        b= temp;
    }
    
    // Make two vertex same depth
    // Step = 2^K
    for(int i=K-1;i>=0;i--){
        if(pow(2,i) <= depth[a] - depth[b]){
            a = parent[i][a]; // Jump a
        }
    }
    if(a == b){return a;} // Same node, done

    // Now a,b is in same depth
    // Jump 2^K step to find least common ancestor
    for(int i=K-1;i>=0;i--){
        if(parent[i][a] != parent[i][b]){ // Jump condition
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    // Parent node is the least common ancestor
    return parent[0][a];
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n;
    
    // 2^K > n : K
    while(pow(2,K) <= n){
        K++;
    }

    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;

        // Make tree
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Init
    memset(parent, 0, sizeof(parent));
    fill(depth,depth+n+1, 0);

    // Depth
    dfs(1,1);

    // Parent
    fillParent();

    // LCA
    int m;
    cin >> m;
    vector<int> ans;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        ans.push_back(lca(a,b));
    }

    for(int vi:ans){
        cout << vi << "\n";
    }
    
}
