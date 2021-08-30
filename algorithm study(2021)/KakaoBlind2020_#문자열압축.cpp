#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    
    for(int i=1;i<=s.size()/2+1;i++){
        vector<string> vec;
        int result = 0;
        // i개 단위로 자른 단어 뭉치
        for(int j=0;j<s.size();j+=i){
            if(j+i-1 < s.size()){
                vec.push_back(s.substr(j,i));    
            }
            else{
                vec.push_back(s.substr(j));
                break;
            }
        }
        // 반복되는 단어 뭉치 찾기
        int cnt=1;
        for(int k=0;k<vec.size()-1;k++){
            if(vec[k] == vec[k+1]){ // 반복됨
                cnt++;
            }
            else{
                if(cnt > 1){ // 반복된 단어 뭉치들 처리
                    string cntLength = to_string(cnt);
                    result += (cntLength.size() + i);
                }
                else{
                    result += vec[k].size();
                }
                cnt=1;
            }
        }
        // 마지막 단어 처리
        if(cnt > 1){
            string cntLength = to_string(cnt);
            result += (cntLength.size() + i);
        }
        else{
            result += vec[vec.size()-1].size();
        }
        //cout << "result: " <<result << "\n";
        answer = min(answer, result);
    }
    
    return answer;
}