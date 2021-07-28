#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    int dp[301];
    int score[301];
    // Init
    for(int i=0;i<=n;i++){
        dp[i] = 0;
        score[i] = 0;
    }

    for(int i=1;i<=n;i++){
        int num;
        cin >> num;    
        score[i] = num;
    }
    
    // First and second init- max
    dp[1] = score[1];
    dp[2] = dp[1] + score[2];

    for(int i=3;i<=n;i++){
        // DP recurrence relation
        // Case1: O X O
        // Case2: O X O O
        dp[i] = max(dp[i-2] + score[i], dp[i-3]+score[i-1]+score[i]);
    }
    cout << dp[n];
}
