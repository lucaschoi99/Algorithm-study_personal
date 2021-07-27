#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int n;

struct building{
    int time;
    int inDegree;
    int ans;
    vector<int> adj;
};

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n;
    struct building buildingList[n+1];

    for(int i=1;i<n+1;i++){ // Init
        buildingList[i].time = 0;
        buildingList[i].inDegree = 0;
        buildingList[i].ans = 0;
    }
    
    for(int i=1;i<n+1;i++){
        int cost, cond;
        cin >> cost >> cond;
        buildingList[i].time = cost;

        while(cond != -1){
            // Update inDegree and adjacent nodes
            buildingList[i].inDegree++;
            buildingList[cond].adj.push_back(i);
            cin >> cond;
        }
    }

    // Queue for inDegree == 0
    queue<int> q;
    for(int i=1;i<n+1;i++){
        if(buildingList[i].inDegree == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int item = q.front();
        q.pop();

        buildingList[item].ans += buildingList[item].time;
        for(int vj:buildingList[item].adj){
            buildingList[vj].inDegree--;
            // Building at the same time is allowed -> take max time
            buildingList[vj].ans = max(buildingList[vj].ans , buildingList[item].ans);

            if(buildingList[vj].inDegree == 0){ // Push queue inDegree == 0
                q.push(vj);
            }
        }
    }

    for(int i=1;i<n+1;i++){
        cout << buildingList[i].ans << "\n";
    }

}
