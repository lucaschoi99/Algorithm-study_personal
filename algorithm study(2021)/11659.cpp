#include<iostream>
#include<algorithm>
using namespace std;
#define NUM 100001

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    // 1~i sum -> dp[i]
    int dp[NUM];
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;

        if(i==1){
            dp[i] = num;
        }
        else{ // DP recurrence relation
            dp[i] = dp[i-1] + num;
        }
    }
    
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(a ==1){ // 1~b : dp[b]
            cout << dp[b] << "\n";
        }
        else{ // a~b : dp[b] - dp[a-1]
            cout << dp[b] - dp[a-1] << "\n";
        }
    }
    
}
