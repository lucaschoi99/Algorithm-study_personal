#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n == 0 || n == 1){
        return false;
    }
    
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> nums;
    set<int> st;
    
    for(int i=0;i<numbers.size();i++){
        nums.push_back(numbers[i]);
    }
    sort(nums.begin(),nums.end());
    
    // 모든 순열의 조합을 찾아 기록
    do{
        string temp = "";
        for(int i=0;i<nums.size();i++){
            temp += nums[i];
            int number = stoi(temp);
            st.insert(number);
        }
        
    }while(next_permutation(nums.begin(),nums.end()));
    
    // 모든 경우 완전탐색
    for(auto vi:st){
        if(isPrime(vi)){
            answer++;
        }
    }
    
    return answer;
}