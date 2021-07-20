#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,S;
    cin >> N >> S;
    int* seq = new int[N+1];

    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        seq[i] = num;
    }

    // Two pointer-sliding window
    int left = 0;
    int right = 0;
    int sum = seq[0];
    vector<int> ans;

    while(true){
        if(sum < S){ // Move right pointer
            right += 1;
            sum += seq[right];
        }
        else { // Target
            ans.push_back(right - left + 1);
            sum -= seq[left];
            left += 1;
        }

        if(right == N){ // Termination
            break;
        }
    }
    if(ans.size() != 0){
        sort(ans.begin(), ans.end());
        cout << ans[0];
    }
    else{
        cout << 0;
    }
    

}
