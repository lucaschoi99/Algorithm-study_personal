#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

long long int *dp;

long long int permutation(long long int x){
    if(x==1){
        dp[x] = 1;
        return 1;
    }
    else if(dp[x] != 0){ // Already computed
        return dp[x];
    }
    else{ // Assign value
        return dp[x] = x * permutation(x-1);
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    long long int N,M,K;
    vector<int> numbers;
    vector<long long> ans;
    cin >> N;

    dp = new long long int[N+1];
    memset(dp,0,sizeof(long long)*(N+1));

    for(int i=1;i<N+1;i++){
        numbers.push_back(i);
    }

    long long int total = permutation(N);
    long long int a = N-1;

    cin >> M;
    if(M == 1){ // k!th answer -> order?
        long long int num;
        cin >> num;
        K = num;
        //K = dp[num];

        while(a > 0){
            int cnt = 1;
            if(K <= dp[a]){ // Starts with first case
                a--;
                ans.push_back(cnt); // Order of numbers
                cnt++;
            }
            else{ // Go through other cases
                K -= dp[a];
                cnt++;
                while(K > dp[a]){
                    K -= dp[a];
                    cnt++;
                }
                ans.push_back(cnt); // Order of numbers
                a--;
            }
        }

        // Find order of permutation using cnt
        for(long long int vi:ans){
            cout << numbers[vi-1] << " ";
            numbers.erase(numbers.begin()+vi-1);
        }
        // Last number
        cout << numbers[0];
    }
    else if(M == 2){ // permutation order -> kth answer?
        for(int j=0;j<N;j++){
            int num;
            cin >> num;

            int index = find(numbers.begin(), numbers.end(), num) - numbers.begin();
            ans.push_back(index+1);
            numbers.erase(numbers.begin()+index);
        }
        
        long long int result = 0;
        // Kth order
        while(a > 0){
            result += dp[a]*(ans[0]-1);
            ans.erase(ans.begin());
            a--;
        }
        cout << result+1;
    }

    // Memory deallocate
    delete[] dp;

}