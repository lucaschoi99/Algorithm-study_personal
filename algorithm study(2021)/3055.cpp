#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Joy stick
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool foundAnswer = false;

// Structure providing position
// and type
struct Point{
    int x;
    int y;
    char type;
};

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int R,C;
    queue<Point> q;
    cin >> R >> C;

    char map[R][C];
    int path[R][C];

    // Initialize
    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            path[i][k] = 0;
        }
    }

    struct Point hog;
    // Map
    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            char ch;
            cin >> ch;
            map[i][k] = ch;

            if(ch == '*'){
                // Position of water
                struct Point p{i,k,'*'};
                q.push(p);
            }
            else if(ch == 'S'){
                // Position of hog
                hog = {i,k,'S'};
            }
            
        }
    }
    
    // Insert water first
    // then hog to the queue
    q.push(hog);
    
    // BFS
    while(!q.empty()){
        struct Point p = q.front();
        q.pop();

        if(p.type == 'D'){
            // Done
            foundAnswer = true;
            cout << path[p.x][p.y];
            break;
        }

        for(int k=0;k<4;k++){
            int newX = p.x + dx[k];
            int newY = p.y + dy[k];

            // Boundary check
            if(newX < R && newX >= 0 && newY < C && newY >=0){
                // Water bfs
                if(p.type == '*'){
                    if(map[newX][newY] == '.' || map[newX][newY] == 'S'){
                        map[newX][newY] = '*'; // Update water position
                        struct Point newP{newX,newY,'*'};
                        q.push(newP);
                    }
                }
                else{ // Hog bfs
                    if(map[newX][newY] == '.' || map[newX][newY] == 'D'){
                        if(path[newX][newY] == 0){ // Distance check (shortest path)
                            path[newX][newY] = path[p.x][p.y] +1; 
                            struct Point newP{newX,newY, map[newX][newY]};
                            q.push(newP);
                        }
                        
                    }
                }
            }
        }
    }

    if(!foundAnswer){
        cout << "KAKTUS";
    }

}
