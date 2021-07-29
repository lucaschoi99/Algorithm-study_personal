#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

#define NUM 4001

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    string first;
    string second;

    cin >> first;
    cin >> second;

    vector<vector<int>> dp(NUM,vector<int>(NUM,0));

    int ans=0;
    for(int i=1;i<=first.length();i++){
        for(int j=1;j<=second.length();j++){
            if(first[i-1] == second[j-1]){ // Matching char
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    
    
}
