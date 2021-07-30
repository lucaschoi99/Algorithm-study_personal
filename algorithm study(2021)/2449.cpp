#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
#define NUM 201

int n,k;
vector<vector<int>> dp(NUM,vector<int>(NUM,0));
vector<int> input(NUM,0);

int DivideConquer(int start, int end){
    // Escape condition
    if(start == end){
        return 0;
    }

    // Already know DP value
    if(dp[start][end] != 0){
        return dp[start][end];
    }

    // Start divide&Conquer
    int ret = INT_MAX;
    for(int i=start;i<end;i++){
        int left = DivideConquer(start, i);
        int right = DivideConquer(i+1,end);

        // Two group starts with same light
        if(input[start] == input[i+1]){
            ret = min(ret, left + right);
        }
        else{ // Starts with different light
            ret = min(ret, left + right + 1);
        }
    }
    return dp[start][end] = ret;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        input[i] = num;
    }

    DivideConquer(1,n);

    cout << DivideConquer(1,n);

}
