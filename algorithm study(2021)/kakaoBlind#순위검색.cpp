#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> newInfo;
    int cnt = 0;
    
    // Info 배열의 모든 경우의 수 미리 저장
    for(auto str:info){
        string inf = "";
        string score = "";
        inf += str[0];
        for(int i=0;i<str.size();i++){
            if(str[i] == ' ' && str[i+1] >='a' && str[i+1] <= 'z'){
                inf += str[i+1];
            }
            else if(str[i] == ' ' && str[i+1] >='1' && str[i+1] <= '9'){
                for(int k=i+1;k<str.size();k++){
                    score += str[k];
                }
            }
            else{ continue;}
        }
        // ----
        newInfo["----"].push_back(stoi(score));
        
        // ---
        string newString = "";
        newString += inf[0];
        newString += "---";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "-";
        newString += inf[1];
        newString += "--";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString +=  "--";
        newString +=  inf[2];
        newString +=  "-";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "---";
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        // --
        newString = "";
        newString += inf[0];
        newString += inf[1];
        newString += "--";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += inf[0];
        newString += "-";
        newString += inf[2];
        newString += "-";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += inf[0];
        newString += "--";
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "-";
        newString += inf[1];
        newString += inf[2];
        newString += "-";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "-";
        newString += inf[1];
        newString += "-";
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "--"; 
        newString += inf[2];
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        // -
        newString = "";
        newString += inf[0];
        newString += inf[1];
        newString += inf[2];
        newString += "-";
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += inf[0];
        newString += inf[1];
        newString += "-";
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += inf[0];
        newString += "-";
        newString += inf[2];
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        newString = "";
        newString += "-";
        newString += inf[1];
        newString += inf[2];
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
        
        // 자기자신
        newString = "";
        newString += inf[0];
        newString += inf[1];
        newString += inf[2];
        newString += inf[3];
        newInfo[newString].push_back(stoi(score));
    }
    
    for(auto it=newInfo.begin();it!=newInfo.end();it++){
        sort(it->second.begin(),it->second.end());
    }
    
    // Query 에서 해당 조건찾아 저장
    for(auto qstr:query){
        int ans = 0;
        vector<int> target;
        string inf = "";
        inf += qstr[0];
        string score = "";
        for(int i=0;i<qstr.size();i++){
            if(qstr[i] == ' ' && qstr[i+1] >='b' && qstr[i+1] <= 'z'){
                inf += qstr[i+1];
            }
            else if(qstr[i] == ' ' && qstr[i+1] >='1' && qstr[i+1] <= '9'){
                for(int k=i+1;k<qstr.size();k++){
                    score += qstr[k];
                }
            }
            else if(qstr[i] == ' ' && qstr[i+1] == '-'){
                inf += "-";
            }
            else{ continue;}
        }
        
        // Binary Search - 해당 점수 이상 찾기
        int intScore = stoi(score);
        if(newInfo.find(inf) != newInfo.end()){
            auto idx = lower_bound(newInfo[inf].begin(), newInfo[inf].end(), intScore) - newInfo[inf].begin();
        answer.push_back(newInfo[inf].size() - idx);
        }
        else{
            answer.push_back(0);
        }
    }
    
    return answer;
}