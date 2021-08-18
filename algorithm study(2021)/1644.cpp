#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
typedef long long ll;
#define MAX 4000001

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int N;
	cin >> N;
	if(N==1){ cout << 0; return 0;}

    // 에라토스테네스의 체로 소수 구하기
	vector<int> nums(MAX, 0);
	vector<bool> visited(MAX, false);
	visited[0] = true;
	visited[1] = true;

	for(int i=0;i<=N;i++){
		nums[i] = i;
	}
	for(int i=2;i<=N;i++){
		if(!visited[i]){
			for(int j=2;i*j<=N;j++){
				visited[i*j] = true;
			}
		}
	}
	vector<int> primes;
	for(int i=2;i<=N;i++){
		if(!visited[i]){
			primes.push_back(nums[i]);
		}
	}
	
	// 2-pointer 이용해 가능한 경우의 수 구하기
	int left = 0;
	int right = 0;
	ll value = primes[left];
	int ans = 0;

	while(left < primes.size() || right < primes.size()){
		if(value < N){ // right pointer 이동
			right++;
			if(right < primes.size()){
				value += primes[right];
			}
			else{
				break;
			}
		}
		else if(value > N){
			// left pointer 이동
			value -= primes[left];
			left++;
		}
		else{ // N과 일치
			ans++;
			// left pointer 이동
			value -= primes[left];
			left++;
		}
	}
	cout << ans;
	
}
