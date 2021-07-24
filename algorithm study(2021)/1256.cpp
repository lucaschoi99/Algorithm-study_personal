#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

long long int MAX_NUM = 1000000000;
long long int **dp;

long long int combination(long long int x, long long int y){
    if(y == 0 || x==1 || x==y){
        dp[x][y] = 1;
        return 1;
    }
    else if(dp[x][y] != 0){ // Already computed
        return dp[x][y];
    }
    else{ // Assign value
        // if pascal value > MAX_NUM
        // value <- MAX_NUM (Does not affect the logic)
        return dp[x][y] = min(MAX_NUM,(combination(x-1,y) + combination(x-1,y-1)));
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    long long int N,M,K;
    string dict = "";
    cin >> N >> M >> K;

    dp = new long long int*[N+M+1];
    for (int i = 0; i < N+M+1; i++){
        dp[i] = new long long int[N+M+1];
        memset(dp[i],0,sizeof(long long)*(N+M+1));
    }

    long long int total = combination(N+M, M);
    if(total < K){
        cout << -1;
        return 0;
    }
    else{
        long long int a = N+M-1;
        long long int b = M;
        int zCount = 0;
        int aCount = 0;
        while(a > 0){
            if(K > dp[a][b]){ // Choose "z"
                dict += "z";
                zCount++;
                K -= dp[a][b];
                a--;
                b--;
            }
            else{ // Choose "a"
                dict += "a";
                aCount++;
                a--;
            }
        }

        // Add last word
        if(N-aCount != 0){
            dict += "a";
        }
        else{
            dict += "z";
        }
    }
    cout << dict;

    // Memory deallocate
    for (int i = 0; i < N+1; i++){
        delete[] dp[i];
    }
    delete[] dp;




}