#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define INT_MAX 2000000000
#define NUM 20001

struct Edge{
    int id;
    int cost;
};

struct compare{
    bool operator()(const Edge& a, const Edge& b){
        return a.cost > b.cost;
    }
};

int V,E,K; // V: nodes# E: edges# K: start node
int dist[NUM];
vector<Edge> adj[NUM];

void dijkstra(){
    priority_queue<Edge, vector<Edge>, compare> pq;

    // Start node INIT
    dist[K] = 0;
    pq.push({K,0});

    while(!pq.empty()){
        Edge item = pq.top();
        pq.pop();

        // If already smaller distance
        if(item.cost > dist[item.id]){
            continue;
        }
        for(int i=0;i<adj[item.id].size();i++){
            Edge next = adj[item.id][i];
            if(dist[next.id] > item.cost + next.cost){ // Update to smaller value
                dist[next.id] = item.cost + next.cost;

                pq.push({next.id, dist[next.id]});
            }
        }
    }
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> V >> E;
    cin >> K;

    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
    }

    for(int i=1;i<V+1;i++){
        dist[i] = INT_MAX;
    }
    // Dijkstra
    dijkstra();

    for(int i=1;i<V+1;i++){
        if(dist[i] == INT_MAX){
            cout << "INF\n";
        }
        else{
             cout << dist[i] << "\n";
        }
    }

}
