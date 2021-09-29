#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> um;
    
    for(auto vi:participant){
        if(um.count(vi)){ // Already exists
            auto item = um.find(vi);
            item->second++;
        }
        else{
            um.insert(make_pair(vi, 1)); 
        }
    }
    
    // Search hash map
    for(auto item:completion){
        if(um.count(item)){ // Exists
            auto current = um.find(item);
            if(current->second > 1){ // 동명이인 중 한명 제거
                current->second--;
            }
            else{ // 완료한 선수 hasp map에서 제거
                um.erase(item);
            }
        }
    }
    
    // 완주하지 못한 선수 파악
    for(auto elem:um){
        answer = elem.first;
    } 
    
    
    return answer;
}