#include<iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    int v[501][501] = {0,}; // for input

    // input
    for(int j=1;j<=n;j++){
        for(int i=1;i<=j;i++){
            cin >> v[j][i];
        }
    }

    // Calculate sum
    int sum = 0;
    for(int i=2;i<=n;i++){
        for(int k=1;k<=i;k++){
            if(k==1){ // leftmost node
                v[i][k] = v[i-1][k] + v[i][k];
            }
            else if(k==i){ //rightmost node
                v[i][k] = v[i-1][k-1] + v[i][k];
            }
            else{ // for nodes in the middle
                v[i][k] = max(v[i-1][k-1] , v[i-1][k]) + v[i][k];
            }
        }
    }
    
    // Try max sum in the last layer
    for(int i=0;i<=n;i++){
        if(v[n][i] >= sum){
            sum = v[n][i];
        }
    }
    cout << sum;
}
