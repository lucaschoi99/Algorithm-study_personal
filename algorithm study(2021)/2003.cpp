#include<iostream>
#include<vector>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,M;
    cin >> N >> M;
    int* seq = new int[N+1];

    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        seq[i] = num;
    }

    // Two pointer-sliding window
    int left = 0;
    int right = 0;
    int sum = 0;
    int ans=0;

    while(left < N && right < N){
        if(left == right){
            sum = seq[left];
        }
        else{
            sum=0;
            for(int i=left;i<=right;i++){
                sum += seq[i];
            }
        }
        
        if(sum < M){ // Move right pointer
            right += 1;
        }
        else if(sum == M){ // target
            ans++;
            left += 1;
        }
        else{ // Move left pointer
            left += 1;
        }
    }
    cout << ans;

}
