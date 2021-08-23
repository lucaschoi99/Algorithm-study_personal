#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int idx, int sum ,int tar){
    // Termination condition
    if(idx == numbers.size()){
        if(sum == tar){
            answer += 1;
        }
        return;
    }
    // Plus, minus dfs call
    dfs(numbers, idx+1, sum + numbers[idx] ,tar);
    dfs(numbers, idx+1 , sum - numbers[idx], tar);
    return;
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0 , 0, target);
    return answer;
}