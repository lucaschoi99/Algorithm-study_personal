#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    // 시작시간, 완료시간 저장
    vector<int> start;
    vector<int> end;
    
    for(auto time:lines){
        // 맨뒤 s 단위 제외
        time.pop_back();
        
        string hour = time.substr(11,2);
        string min = time.substr(14,2);
        string sec = time.substr(17,6);
        string elpased = time.substr(24);
        
        // 단위 ms로 통일
        int hourInt = stoi(hour) * 3600 * 1000;
        int minInt = stoi(min) * 60 * 1000;
        int secInt = int(stod(sec) * 1000);
        int elpInt = int(stod(elpased) * 1000);
        
        start.push_back(hourInt + minInt + secInt - elpInt + 1);
        end.push_back(hourInt + minInt + secInt);
        
    }
    
    // 2중 for문으로 구간 처리량 순회
    for(int i=0;i<lines.size();i++){
        int count = 0;
        int endTime = end[i] + 1000; // end <= T < end+1 구간
        
        for(int j=i;j<lines.size();j++){
            if(start[j] < endTime){
                count++;
            }
        }
        
        if(answer < count){ // 최대 처리량 갱신
            answer = count;
        }
    }
    
    return answer;
}