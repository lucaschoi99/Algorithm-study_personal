#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

long long cal(long long a, long long b, string op){
    if(op == "*"){ return a * b;}
    else if(op == "+"){ return a + b;}
    else if(op == "-"){ return a-b;}
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> numbers;
    vector<string> operatorList = {"*", "+", "-"};
    vector<string> ops;
    
    // Parse Expression
    string number = "";
    string op = "";
    for(int i=0;i<expression.size();i++){
        if(expression[i] >= '0' && expression[i] <= '9'){
            number += expression[i];
            if(i == expression.size()-1){
                numbers.push_back(stol(number));
            }
        }
        else{
            numbers.push_back(stol(number));
            number = "";
            op += expression[i];
            ops.push_back(op);
            op = "";
        }
    }
    
    // 3! 경우의 수 모두 시행 -> abs 가장 큰값 선택
    do{
        vector<long long> temp_nums = numbers;
        vector<string> temp_ops = ops;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<temp_ops.size();j++){
                if(temp_ops[j] == operatorList[i]){
                    temp_nums[j] = cal(temp_nums[j], temp_nums[j+1], operatorList[i]);
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_ops.erase(temp_ops.begin() + j);
                    j--;
                }
            }
        }
        if(abs(temp_nums.front()) > answer){
            answer = abs(temp_nums.front());
        }
    }while(next_permutation(operatorList.begin(), operatorList.end()));
    
    
    return answer;
}