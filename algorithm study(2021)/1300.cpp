#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
typedef long long ll;
#define MAX 200001

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n;
    cin >> k;

    // Binary Search
    int left = 1;
    int right = k;
    int mid = (left+right)/2;
    int result;

    while(left <= right){
        int cnt = 0;
        mid = (left+right)/2;
        // Count num <= mid
        for(int i=1;i<=n;i++){
            cnt += min(mid/i,n);
        }
        if(cnt < k){ // Proceed
            left = mid+1;
        }
        else{ // Save result and proceed
            result = mid;
            right = mid-1;
        }
    }
    cout << result;

}
