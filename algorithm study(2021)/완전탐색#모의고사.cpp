#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> players;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    
    int vec1[5] = {1,2,3,4,5};
    int vec2[8] = {2,1,2,3,2,4,2,5};
    int vec3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    // 완전탐색
    for(int i=0;i<answers.size();i++){
        // #1
        if(answers[i] == vec1[i%5]){
            p1++;
        }
        
        // #2
        if(answers[i] == vec2[i%8]){
            p2++;
        }
        
        // #3
        if(answers[i] == vec3[i%10]){
            p3++;
        }
    }
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    
    // 최고 점수 구하기
    int maxNum = *max_element(players.begin(),players.end());
    
    if(p1 == maxNum){
        answer.push_back(1);
    }
    if(p2 == maxNum){
        answer.push_back(2);
    }
    if(p3 == maxNum){
        answer.push_back(3);
    }
    
    return answer;
}