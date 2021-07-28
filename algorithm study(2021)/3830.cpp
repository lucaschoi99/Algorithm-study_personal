#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define NUM 100001

int n,m;
int parent[NUM];
long long int dist[NUM];

int find(int a){
    if(parent[a] == a){
        return a;
    }
    int pa = find(parent[a]); // Lazy propagation
    dist[a] += dist[parent[a]]; // Update dist (add parent's dist)
    return parent[a] = pa;
}

void Union(int a, int b, long long int w){
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB){ // Already in the same group
        return;
    }
    // Update rootB distance
    // rootB's parent <- rootA
    dist[rootB] = dist[a] - dist[b] + w;
    parent[rootB] = rootA;
    return;
    
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    while(true){
        cin >> n >> m;
        if(n==0 && m==0){
            break;
        }
        
        // Init
        for(int i=0;i<n+1;i++){
            parent[i] = i;
            dist[i] = 0;
        }
        char mode;
        long long int a,b,w;
        for(int i=0;i<m;i++){    
            cin >> mode;
            if(mode == '!'){
                
                cin >> a >> b >> w;
                Union(a,b,w);
            }
            else{ // mode == '?'
                cin >> a >> b;
                if(find(a) != find(b)){ // UNKNOWN
                    cout << "UNKNOWN\n";
                }
                else{ // answer
                    cout << dist[b] - dist[a] << "\n";
                }
            }
        }
    }
    return 0;
}
