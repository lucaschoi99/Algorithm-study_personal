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

    int n,m;
    cin >> n >> m;

    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        arr2.push_back(num);
    }

    // Merge-Sort algorithm
    // Divide & Conquer 중 Conquer부분
    // Use 2-pointer
    int left=0;
    int right=0;
    vector<int> ans;
    while(left < arr1.size() && right < arr2.size()){
        if(arr1[left] == arr2[right]){ // 둘 다 이동
            ans.push_back(arr1[left]);
            ans.push_back(arr2[right]);
            left++;
            right++;
        }
        else if(arr1[left] < arr2[right]){ // left pointer 이동
            ans.push_back(arr1[left]);
            left++;
        }
        else{ // right pointer 이동
            ans.push_back(arr2[right]);
            right++;
        }
    }
    while(left < arr1.size()){ // arr1 미완료
        ans.push_back(arr1[left]);
        left++;
    }
    while(right < arr2.size()){ // arr2 미완료
        ans.push_back(arr2[right]);
        right++;
    }
    for(int vi:ans){
        cout << vi << " ";
    }

	
}
