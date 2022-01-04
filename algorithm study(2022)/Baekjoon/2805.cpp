#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num, targetLen, answer=0;
    vector<int> trees;
    cin >> num >> targetLen;

    for(int i=0;i<num;i++){
        int el;
        cin >> el;
        trees.push_back(el);
    }

    // Binary Search
    int start=0, end= *max_element(trees.begin(), trees.end()), mid;
    
    while(start <= end){
        mid = (start+end) / 2;
        long long sum = 0;
        for(int item=0;item<trees.size();item++){
            int cal = max(0,trees[item]-mid);
            sum += cal;
        }

        if(sum > targetLen){
             start = mid+1;
             answer = mid;
        }
        else if(sum == targetLen){
            answer = mid;
            break;
        }
        else{
            end = mid-1;
        }
    }
    
    cout << answer << "\n";

}
