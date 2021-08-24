#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // Binary Search
    long long start = 1;
    long long end = (long long)n * (*max_element(times.begin(), times.end()));
    long long mid = (start + end) / 2;
    
    while(start <= end){
        mid = (start + end) / 2;
        
        // Count waiting people until (mid) time
        long long cnt=0;
        for(int i=0;i<times.size();i++){
            cnt += mid / times[i];
        }
        if(cnt < n){ // Need more time
            start = mid+1;
        }
        else{ // May be the answer, but proceed
            answer = mid;        
            end = mid-1;
        }
    }
    
    return answer;
}