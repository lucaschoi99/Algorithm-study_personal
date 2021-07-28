#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;

struct edgeList{
    int start;
    int end;
    int cost;
};

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    struct edgeList List[m+1];

    for(int i=1;i<m+1;i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        List[i] = {start, end, cost};
    }

    // Dist[] init
    int start=1;
    vector<long long int> dist(n+1,LLONG_MAX);
    dist[start] = 0;

    bool isNegCycle = false;
    // Bellman-Ford
    for(int j=1;j<n;j++){ // Loop # (n-1)
        for(int i=1;i<m+1;i++){
            if(dist[List[i].start] == LLONG_MAX){ // Cannot update now
                continue;
            }
            // Update
            dist[List[i].end] = min(dist[List[i].start] + List[i].cost, dist[List[i].end]);
        }
    }
    // Last iteration
    for(int i=1;i<m+1;i++){
        // Check if update occurs
        if(dist[List[i].start] == LLONG_MAX){ // Don't update
            continue;
        }
        if(dist[List[i].end] > dist[List[i].start] + List[i].cost){
            isNegCycle = true;
            break;
        }
    }
    
    if(isNegCycle){ // Negative cycle exists
        cout << -1;
    }
    else{
        for(int i=2;i<n+1;i++){
            if(dist[i] != LLONG_MAX){
                cout << dist[i] << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }

}
