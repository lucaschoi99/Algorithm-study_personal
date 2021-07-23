#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
#define NUM 10007

long long int **dp;

long long int combination(long long int x, long long int y){
    if(y == 0 || x==1 || x==y){
        return 1;
    }
    else if(dp[x][y] != 0){ // Already computed
        return dp[x][y];
    }
    else{ // Assign value
        return dp[x][y] = (combination(x-1,y) % NUM) + (combination(x-1,y-1) % NUM);
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    long long int N,K;
    cin >> N >> K;

    dp = new long long int*[N+1];
    for (int i = 0; i < N+1; i++){
        dp[i] = new long long int[K+1];
        memset(dp[i],0,sizeof(long long)*(K+1));
    }

    long long int result = combination(N,K);
    cout << result % NUM;

    for (int i = 0; i < N+1; i++){
        delete[] dp[i];
    }
    delete[] dp;




}