#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int n;
    cin >> n;
    vector<int> waters;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        waters.push_back(num);
    }

    // Sort asc
    sort(waters.begin(),waters.end());

    if(n == 2){
        cout << waters[0] << " " << waters[1];
        return 0;
    }

    // 양끝의 2-pointer를 움직이며 절댓값 비교
    int left = 0;
    int right = waters.size()-1;
    int min = INT_MAX;
    int ans[2];

    while(left < right){
        int sum = waters[left] + waters[right];

        if(min > abs(sum)){ // Smaller sum
            min = abs(sum);
            ans[0] = waters[left];
            ans[1] = waters[right];

            if(sum == 0){ break; }
        }

        if(sum < 0){ // Move left pointer
            left++;
        }
        else{ // Move right pointer
            right--;
        }
    }
    
    cout << ans[0] << " " << ans[1];
    
}
