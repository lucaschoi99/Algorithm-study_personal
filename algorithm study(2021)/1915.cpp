#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
#define NUM 1001

int n,m;
int map[NUM][NUM] = {0,};
int dp[NUM][NUM] = {0,};

// Check (↖), (←), (↑)  
int check(int a, int b){
    int check1 = dp[a-1][b-1];
    int check2 = dp[a][b-1];
    int check3 = dp[a-1][b];

    if(check1 == 0 || check2 == 0 || check3 == 0){
        return 1;
    }
    return min(min(check1,check2),check3) + 1;
}



int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char num;
            cin >> num;
            map[i][j] = num - '0';
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j] == 1){ // Check '1' value
                dp[i][j] = check(i,j);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans*ans;

}
