#include<iostream>
//#include<map>-- not a good idea using map since unique key constraint
#include<vector> //use vector to indicate tree nodes
using namespace std;
const int MAX = 1000001;

vector<int> tree[MAX];
bool visited[MAX];
int ans[MAX];

void findParent(int num) {
    visited[num] = true;
    //dfs
    for (int k = 0; k < tree[num].size(); k++) {
        int node = tree[num][k]; //next node to find
        if (!visited[node]) { //if not visited
            ans[node] = num; //set num as node's parent
            findParent(node); //dfs
        }
    }
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n; //node #
    for(int q=0;q<n-1;q++) {
        int a, b;
        cin >> a >> b;
        //insert associated nodes info
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    findParent(1); //start from root

    for (int i = 2; i < n + 1; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
