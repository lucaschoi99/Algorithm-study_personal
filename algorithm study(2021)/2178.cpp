#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_NUM 100
int n,m;

// Board
vector<vector<char>> vec(MAX_NUM*sizeof(char), vector<char>(MAX_NUM*sizeof(char),'0'));
bool visited[MAX_NUM][MAX_NUM] = {false,};
int dist[MAX_NUM][MAX_NUM]; // distance from the start point
int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0 ,-1};

void bfs(int posX, int posY){
    // check visited
    visited[posX][posY] = true;
    
    // Make a queue
    queue<pair<int,int>> q;
    q.push(make_pair(posX,posY));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            // Boundary check
            if(next_x >= 0 && next_x < n && next_y >=0 && next_y < m){
                // The way exists
                // and not visited yet
                if(vec[next_x][next_y] == '1' && visited[next_x][next_y] == false){
                    dist[next_x][next_y] = dist[x][y] + 1; // Add 1
                    visited[next_x][next_y] = true;
                    q.push(make_pair(next_x,next_y)); // next position
                }
            }
        }
    }

}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> m;

    // Resize board
    vec.resize(n,vector<char>(m,'0'));

    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            char num;
            cin >> num;
            
            // Fill the board
            if(num == '1'){
                vec[i][k] = '1';
            }
        }
    }

    // Search for the shortest path
    bfs(0,0);
    
    cout << dist[n-1][m-1] +1;
    
}
