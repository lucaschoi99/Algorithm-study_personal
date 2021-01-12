#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//vector space indicate a field
//check visited
vector<int> v;
vector<int> visited;
int cnt=0;

//bfs
void bfs(int start, int colsize, int rowsize){
    queue<int> q;
    q.push(start);
    visited[start]=1; //check visit

    while(!q.empty()){
        int start = q.front();
        q.pop();

        //for adjacent cabbages,
        //if already visited or no cabbages, pass
        if(start < colsize*rowsize-1 && (start%colsize) != (colsize-1)){
            if(visited[start+1] == 1 || v[start+1]==0){
            }
            else{
                q.push(start+1); //east adjacent cabbage
                visited[start+1] = 1; //check visited
            }
            
        }
        if(start > 0 && (start%colsize) != 0){
            if(visited[start-1] == 1 || v[start-1]==0){
            }
            else{
                q.push(start-1); //west adjacent cabbage
                visited[start-1] = 1; //check visited
            }
            
        }
        if(start < colsize*(rowsize-1)){
            if(visited[start+colsize] == 1 || v[start+colsize]==0){
            }
            else{
                q.push(start+colsize); //south adjacent cabbage
                visited[start+colsize] = 1; //check visited
            }
            
        }
        if(start > colsize-1){
            if(visited[start-colsize] == 1 || v[start-colsize]==0){
            }
            else{
                q.push(start-colsize); //north adjacent cabbage
                visited[start-colsize] = 1; //check visited
            }
            
        }
    }
    cnt++; //bfs done
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T; //test cases

    while(T--){
        int m,n,k; //m columns, n rows, k cabbages
        cin >>  m >> n >> k;

        //initialize vector spaces to 0
        v.resize(m*n, 0);
        visited.resize(m*n,0);

        //initialze
        cnt = 0;

        //location of cabbages
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            int loc = (y*m) + x;

            v[loc] = 1; //locate (y,x)
        }   
        
        //find minimum number of worms
        for(int i=0;i<v.size();i++){
            if(v[i] == 1 && visited[i]==0){ 
                //find appearance of unvisited cabbage
                //bfs
                bfs(i,m,n);
            }
        }
        cout << cnt << "\n";
        
        //initialize
        v.clear();
        visited.clear();

        
    }


    return 0;
}
