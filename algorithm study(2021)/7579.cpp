#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define NUM 101
#define MAX 10001

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;

    vector<int> mem(NUM,0);
    vector<int> cost(NUM,0);
    int costSum = 0;

    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        mem[i] = num;
    }
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        cost[i] = num;
        costSum += num;
    }
    
    // Key-idea
    // DP[i][j] : ~ith App, possible max memory with costSum j
    // Cannot use DP[n][10000000] <- memory over 3000MB
    vector<vector<int>> dp(n+1, vector<int>(costSum+1,0));
    
    // DP logic
    for(int i=1;i<=n;i++){
        for(int j=0;j<=costSum;j++){
            if(j>=cost[i]){ // Update possible
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + mem[i]);
            }
            
            dp[i][j] = max(dp[i][j] , dp[i-1][j]);
            
        }
    }

    // Answer
    int ans=0;
    for(int j=0;j<=costSum;j++){
        if(dp[n][j] >= m){
            ans = j;
            break;
        }
    }
    
    cout << ans;
    
}
