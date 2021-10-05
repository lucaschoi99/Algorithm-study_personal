#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    // 총합
    for(int i=0;i<=9;i++){
        answer += i;
    }
    
    // 존재하는 숫자 빼기
    for(auto nums:numbers){
        answer -= nums;
    }
    
    return answer;
}