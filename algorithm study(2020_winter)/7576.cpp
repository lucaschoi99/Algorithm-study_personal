#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m,n;
int chunk =0;
int cnt=0;
int ans=0;
const int MAX = 1001;
// Graph
vector<vector<int>> graph(MAX,vector<int>(MAX,-1));
bool check[MAX][MAX] = {false, };
queue<pair<int,int>> q;

void bfs(){

	while(!q.empty()){
        int alpha[] = {-1,1};
        cnt=0;

        // process by chunk
        for(int c=0;c<chunk;c++){
            int tmpX = q.front().first;
            int tmpY = q.front().second;
            check[tmpX][tmpY] = true;

            q.pop();

            // look adjacent spaces(up, down)
            for(int i=0;i<2;i++){
                if(tmpX+alpha[i] > -1 && tmpX+alpha[i] < n && (!check[tmpX+alpha[i]][tmpY]) && (graph[tmpX+alpha[i]][tmpY] != -1)){
                    // push into queue & check visited
                    q.push(pair<int,int>(tmpX+alpha[i],tmpY));

                    //update
                    graph[tmpX+alpha[i]][tmpY] = 1;
                    check[tmpX+alpha[i]][tmpY] = true;
                    cnt++;
                }
                else{}    
            }
            // right, left
            for(int i=0;i<2;i++){
                if(tmpY+alpha[i] > -1 && tmpY+alpha[i] < m && (!check[tmpX][tmpY+alpha[i]]) && (graph[tmpX][tmpY+alpha[i]] != -1)){
                    // push into queue & check visited
                    q.push(pair<int,int>(tmpX,tmpY+alpha[i]));

                    //update
                    graph[tmpX][tmpY+alpha[i]] = 1;
                    check[tmpX][tmpY+alpha[i]] = true;
                    cnt++;
                }
                else{}
            }
        }
        //update chunk num
        chunk = cnt;
        ans++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;

    // insert data & push loc of 1s to queue
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++){
            int num;
            cin >> num;

            graph[k][j] = num;
            if(graph[k][j] == 1){
                q.push(make_pair(k, j));
                chunk++;
            }
        }
        
    }
    
    // run bfs at "1"s
    bfs();

    // check complete
    for(int k=0;k<n;k++){
        for(int j=0;j<m;j++){
            if(graph[k][j] == 0){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    //print answer
    cout << ans-1;
}