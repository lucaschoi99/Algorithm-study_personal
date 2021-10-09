#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // 유저 아이디와 닉네임 정보를 담는 map
    map<string,string> mp;
    vector<pair<string,string>> userOrder;
    
    for(auto elem:record){
        vector<string> words;
        stringstream sstream(elem);
        string word;
        
        while(getline(sstream, word, ' ')){
            words.push_back(word);
        }
        
        // 정보 파싱 & Map에 기록
        string cmd = words[0];
        string userId = words[1];
        string name = "";
        if(cmd != "Leave"){ // Enter or Change
            name += words[2];
            mp[userId] = name;
        }
        if(cmd != "Change"){
            userOrder.push_back(pair<string,string>(cmd, userId));
        }
    }
    
    // Answer
    for(int i=0;i<userOrder.size();i++){
        string command = userOrder[i].first;
        string userId = userOrder[i].second;
        
        if(command == "Enter"){
            string newString = mp[userId];
            newString += "님이 들어왔습니다.";
            answer.push_back(newString);
        }
        else if(command == "Leave"){
            string newString = mp[userId];
            newString += "님이 나갔습니다.";
            answer.push_back(newString);
        }
    }
    
    return answer;
}