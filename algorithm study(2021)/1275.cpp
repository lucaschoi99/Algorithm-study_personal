#include<iostream>
#include<vector>
using namespace std;

// Number # : n
// Turn # : q
long long int n,q;
long long int S; // First Leaf node index : S

vector<long long int> numArray;
vector<long long int> idxtree;

void init(){

    // Fill leaf nodes with numArray
    for(int i=0;i<numArray.size();i++){ 
        idxtree[S+i] = numArray[i];
    }

    // Fill internal nodes
    for(int i=S-1;i>0;i--){
        // Sum left, right child
        idxtree[i] = idxtree[2*i+1] + idxtree[2*i];
    }
}

long long int query(int left, int right, int node, int queryLeft, int queryRight){
    if(left > queryRight || right < queryLeft){ // Range outside
        return 0;
    }
    else if(queryLeft <= left && queryRight >= right){ // contains
        return idxtree[node];
    }
    else{ // Recursive call
        int mid = (left + right) / 2;
        long long int leftResult = query(left, mid, 2*node, queryLeft, queryRight);
        long long int rightResult = query(mid+1, right, 2*node+1, queryLeft, queryRight);

        return leftResult + rightResult;
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

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> q;

    // Input
    for(int i=0;i<n;i++){
        long long int nodeNum;
        cin >> nodeNum;
        numArray.push_back(nodeNum);
    }

    S = 1;
    while(S < n){
        S *= 2; 
    }
    // Initialize tree with zeros
    idxtree.resize(2*S, 0);
    
    // Init
    init(); // Fill idxtree

    long long int x,y,a,b;
    for(int i=0;i<q;i++){
        cin >> x >> y >> a >> b;
        
        // Query sum bth ~ cth element
        if(x > y){ // swap
            long long int temp = x;
            x = y;
            y = temp;
        }
        cout << query(1,S,1,x,y) << "\n";

        // Change ath element to b
        long long int diff = b - idxtree[S+a-1];;
        update(1,S,1,a,diff);
        
    }
}
