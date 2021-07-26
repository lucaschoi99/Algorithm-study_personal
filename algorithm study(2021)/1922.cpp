#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int parent[1001];

void init(){
    for(int i=1;i<=n;i++){
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

struct Edge{ // Edge info
    int start;
    int end;
    int cost;
};

struct compare{ // Ascending
    bool operator()(Edge &a, Edge &b){
		return a.cost>=b.cost;
	}
};


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n;
    cin >> m;

    // Ascending priority queue
    priority_queue<Edge, vector<Edge>, compare> pq;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >>c;
        Edge newEdge = {a,b,c};
        pq.push(newEdge);
    }

    init();
    int cnt=0;
    int total=0;
    while(!pq.empty()){ // Kruskal algorithm
        Edge item = pq.top();
        pq.pop();

        if(cnt == n-1){break;} // MST edge # max

        if(item.start == item.end){ // Same computer
            continue;
        }
        if(find(item.start) == find(item.end)){ // Same group
            continue;
        }
        else{
            Union(item.start, item.end);
            cnt++;
            total += item.cost;
        }
    }

    cout << total;


}
