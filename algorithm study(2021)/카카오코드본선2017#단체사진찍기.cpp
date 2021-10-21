#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    vector<char> ppl = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    // 모든 경우의 수 8! -> 조건 필터링
    do{
        int condCnt = 0; // 조건 만족 개수
        
        for(int i=0;i<n;i++){
            char me = data[i][0];
            char you = data[i][2];
            char cond = data[i][3];
            int dist = data[i][4] - '0';
            
            auto meIdx = find(ppl.begin(), ppl.end(), me) - ppl.begin();
            auto youIdx = find(ppl.begin(), ppl.end(), you) - ppl.begin();
            int condDist = abs(meIdx - youIdx);
            
            if(cond == '='){
                if(condDist == dist+1){
                    condCnt++;
                }
            }
            else if(cond == '<'){
                if(condDist <= dist){
                    condCnt++;
                }
            }
            else if(cond == '>'){
                if(condDist > dist+1){
                    condCnt++;
                }
            }
        }
        
        // 통과 여부 판단
        if(condCnt == n){
            answer++;
        }
        
    }while(next_permutation(ppl.begin(), ppl.end()));
    
    return answer;
}