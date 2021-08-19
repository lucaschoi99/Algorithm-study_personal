#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
typedef long long ll;
#define MAX 1000001

int n;
// Vector to save index, order
vector<int> input;
int idxArr[MAX];
vector<int> vec;

int binarySearch(int value){ // Lower bound binarySearch implementation
    int left = 0;
    int right = vec.size()-1;
    int mid = (left+right) / 2;

    while(left < right){
        mid = (left+right)/2;
        if(vec[mid] < value){ // Move left
            left = mid+1;
        }
        else if(vec[mid] >= value){ // Move right
            right = mid;
        }
    }
    if(value > vec[vec.size()-1]){ // Add at the end
        return vec.size();
    }
    return left;

}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    
    // First value
    vec.push_back(input[0]);
    idxArr[0]= 0;
    
    // Traverse through input array
    // Use lower_bound to replace the value
    // Update idxArr
    for(int i=1;i<n;i++){
        int idx = binarySearch(input[i]);
        if(idx >= vec.size()){ // Add at the end
            vec.push_back(input[i]);
            idxArr[i] = idx;
            continue;
        }
        vec[idx] = input[i];
        idxArr[i] = idx;
    }

    // Check backwards
    int ans=0;
    int target = vec.size()-1;
    for(int i=n-1;i>=0;i--){
        if(idxArr[i] == target){
            ans++;
            target--;
        }
    }
    cout << ans;
}
