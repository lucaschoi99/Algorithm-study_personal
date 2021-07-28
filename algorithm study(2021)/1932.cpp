#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    int v[502][502] = {0,}; // for input

    // input
    for(int j=1;j<=n;j++){
        for(int i=1;i<=j;i++){
            cin >> v[j][i];
        }
    }

    // Calculate sum
    int dp[502][502] = {0,};
    dp[1][1] = v[1][1];

    for(int i=1;i<=n-1;i++){
        for(int k=1;k<=i;k++){
            dp[i+1][k] = max(dp[i+1][k], dp[i][k]);
            dp[i+1][k+1] = max(dp[i+1][k+1], dp[i][k]);
        }
        for(int k=1;k<=i+1;k++){
            dp[i+1][k] += v[i+1][k];
        }
    }

    int ans = dp[n][1];
    for(int i=2;i<=n;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    
}
