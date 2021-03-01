#include<iostream>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    int dp[n];
    dp[0]= 1;
    dp[1] = 2;

    // dynamic programming
    for(int k=2;k<=n;k++){
        dp[k] = (dp[k-1] + dp[k-2]) % 10007;
    }

    
    cout << dp[n-1];
}