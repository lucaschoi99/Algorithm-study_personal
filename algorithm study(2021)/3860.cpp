#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
#define MAX 987654321

int W,H,G; // map size: W*H. Grave #: G
bool isGrave[31][31] = {false,};
bool isHole[31][31] = {false,};
int dist[31][31] = {MAX,};
bool minusFlag = false;

// Joy stick
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

struct edgeInfo{
    int startX,startY;
    int endX,endY;
    int cost;
};
vector<edgeInfo> edgeList;

void makePath(){
    // Make a edgeList
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            // Continue if grave or goal or Ghost hole
            if(isGrave[i][j] || (i == H-1 && j == W-1) || isHole[i][j]){
                continue;
            }

            // Possible path
            for(int k=0;k<4;k++){
                int newX = i+dx[k];
                int newY = j+dy[k];

                // Boundary check
                if(newX >= 0 && newX < H && newY >=0 && newY < W && !isGrave[newX][newY]){
                    edgeInfo newEdge = {i,j,newX,newY,1};
                    edgeList.push_back(newEdge);
                }
            }
        }
    }
}

void BellmanFord(){
    // Init
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = MAX;
        }
	}
    dist[0][0]=0;

    // Traverse EdgeList (Node-1) times
    for(int i=0;i<H*W-G;i++){
        int len = edgeList.size();
        for(int j=0;j<len;j++){
            edgeInfo current = edgeList[j];
            if(dist[current.startX][current.startY] == MAX){ // Don't update yet
                continue;
            }
            // Update distance with min value
            dist[current.endX][current.endY] = min(dist[current.endX][current.endY], dist[current.startX][current.startY] + current.cost);
        }
    }

    // Check last iteration - if minus cycle exists
    int len = edgeList.size();
    for(int j=0;j<len;j++){
        edgeInfo current = edgeList[j];
        if(dist[current.startX][current.startY] == MAX){ // Don't update yet
            continue;
        }
        // If update -> minus cycle exists
        if(dist[current.startX][current.startY] + current.cost < dist[current.endX][current.endY]){
            minusFlag = true;
        }
    }

    if(minusFlag){ // Minus cycle exists
        cout << "Never\n";
    }
    else{
        if(dist[H-1][W-1] == MAX){ // Cannot reach Goal position
            cout << "Impossible\n";
        }
        else{ // Print answer
            cout << dist[H-1][W-1] << "\n";
        }
    }

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    while(true){
        cin >> W >> H;

        if(W==0 && H==0){ // Termination
            break;
        }

        int X, Y; // Grave #, pos(X,Y)
        int E, X1, Y1, X2, Y2, T; // Ghost hole #, (X1,Y1) -> (X2,Y2), T= elapsed time

        // Init
        for(int i=0;i<31;i++){
            for(int j=0;j<31;j++){
                isGrave[i][j] = false;
                isHole[i][j] = false;
            }
        }
        edgeList = vector<edgeInfo>();
        minusFlag = false;

        // Grave info
        cin >> G;
        for(int i=0;i<G;i++){
            cin >> X >> Y;
            isGrave[Y][X] = true;
        }
        // Ghost hole info
        cin >> E;
        for(int i=0;i<E;i++){ 
            cin >> X1 >> Y1 >> X2 >> Y2 >> T;

            isHole[Y1][X1] = true;
            edgeInfo newEdge = {Y1,X1,Y2,X2,T};
            edgeList.push_back(newEdge);
        }

        // Position info -> graph
        makePath();

        // Bellman-Ford
        BellmanFord();
        
    }
    
}
