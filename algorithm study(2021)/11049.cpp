#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
#define NUM 501

int n,k;
vector<vector<int>> dp(NUM,vector<int>(NUM,INT_MAX));
vector<int> input[NUM];

int DivideConquer(int start, int end){
    // Escape condition
    if(start == end){
        return 0;
    }

    // Already know DP value
    if(dp[start][end] != INT_MAX){
        return dp[start][end];
    }

    // Start divide&Conquer
    for(int i=start;i<end;i++){
        int left = DivideConquer(start, i);
        int right = DivideConquer(i+1,end);
        
        // Choose min between
        // Own value vs left + right + start.row * ith.column * end.column
        dp[start][end] = min(dp[start][end], left+right+input[start][0] * input[i][1] * input[end][1]);
    }
    return dp[start][end];
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    cin >> n;

    for(int i=0;i<n;i++){
        int r,c;
        cin >> r >> c;
        input[i].push_back(r);
        input[i].push_back(c);
    }

    DivideConquer(0,n-1);

    cout << DivideConquer(0,n-1);

}
