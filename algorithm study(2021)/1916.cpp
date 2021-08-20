#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
typedef long long ll;
#define NUM 1001

struct info{
    int id;
    ll cost;
};

struct compare{
    bool operator()(info& a, info& b){
        return a.cost < b.cost;
    }
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n;
    cin >> m;

    vector<info> edge[NUM];

    for(int i=1;i<=m;i++){
        int s,e,c;
        cin >> s >> e >> c;
        
        edge[s].push_back({e,c});
    }

    // Start, end
    int startNum;
    int endNum;
    cin >> startNum >> endNum;

    // Priority queue (cost asc)
    priority_queue<info,vector<info>,compare> pq;
    pq.push({startNum,0});

    // Distance array
    ll dist[NUM];
    for(int i=1;i<=n;i++){
        dist[i] = LLONG_MAX;
    }
    dist[startNum] = 0;

    // Dijkstra
    while(!pq.empty()){
        struct info item = pq.top();
        pq.pop();

        // If already smaller distance
        if(item.cost > dist[item.id]){
            continue;
        }

        for(auto vi:edge[item.id]){
            // Update dist
            if(dist[vi.id] > item.cost + vi.cost){
                dist[vi.id] = item.cost + vi.cost;
                pq.push({vi.id, dist[vi.id]});
            }
        }
    }
    cout << dist[endNum];
}
