#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
#define MAX 100000000

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n;
    cin >> m;

    long long int dist[101][101];
    // Init
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = MAX;
        }
    }

    for(int i=1;i<=m;i++){
        long long int start, end, cost;
        cin >> start >> end >> cost;

        dist[start][end] = min(dist[start][end], cost);
    }

    // Floyd-Warshall
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] != MAX){
                cout << dist[i][j] << " ";
            }
            else{
                cout << 0 << " ";
            }
            
        }
        cout << "\n";
    }


}
