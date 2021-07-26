#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
//int *parent = new int[n+1];
int parent[1000001];

void init(){
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    int pa = find(a);
    int pb = find(b);

    parent[pa] = pb;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> m;
    init();

    for(int i=0;i<m;i++){
        int mode, a ,b;
        cin >> mode >> a >> b;
        if(mode == 0){ // Union
            Union(a,b);
        }
        else if(mode == 1) { // Find
             if(find(a) == find(b)){
                cout << "YES\n";
             }
             else{
                 cout << "NO\n";
             }
        }
    }
}
