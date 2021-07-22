#include<iostream>
#include<vector>
using namespace std;

#define NUM_MAX 1000000
long long int S; // First Leaf node index : S

//vector<long long int> numArray;
vector<long long int> idxtree;

void init(){
    // Fill zeros
    idxtree.resize(2*NUM_MAX+1,0);
}

long long int query(int left, int right, int node, int target){
    int mid = (left + right) / 2;

    if(left == right){ // Leaf node
        return left;
    }

    if(idxtree[2*node] < target){ // No target candy on left-side
        target -= idxtree[2*node]; // exclude left side
        return query(mid+1, right, 2*node+1, target);
    }
    else{ // Target candy on left-side
        return query(left, mid, 2*node, target);
    }
    
}

void update(int left, int right, int node, int target, long long int diff){
    if(left > target || right < target){
        // Do nothing
        return;
    }
    else{ // contains target
        idxtree[node] += diff; // update
        if(left == right){
            return;
        }
        // Do update on internal nodes
        int mid = (left + right) / 2;
        update(left, mid, 2*node, target, diff);
        update(mid+1, right, 2*node+1, target, diff);
        
    }
}

void updateBU(int target, int value){
    int index = S + target -1;
    idxtree[index] = value;

    // Update parents
    index /= 2;
    while(index > 0){
        idxtree[index] = idxtree[2*index] + idxtree[2*index+1];
        index /= 2;
    }

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
/*
    // Initialize
    numArray.resize(NUM_MAX, 0);
*/
    S = 1;
    while(S < NUM_MAX){
        S *= 2; 
    }
    //init();
    // Fill zeros
    idxtree.resize(2*S,0);

    for(int i=0;i<n;i++){
        int a,b;
        int c=0;
        cin >> a;
        if(a == 1){ // Take out bth candy
            cin >> b;
            long long int result = query(1,S,1,b);
            update(1,S,1,result,-1);
            cout << result << "\n";
        }
        else if(a==2){ // Push bth candy #c
            cin >> b >> c;
            update(1,S,1,b,c);
        }
    }
}
