#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define NUM 1001

using namespace std;

struct infos{
    string fullName;
    string head;
    int number;
    int idx;
};

bool compare(struct infos &a, struct infos &b){
    // Head 비교
    if(a.head == b.head){
        // 입력 순서 비교
        if(a.number == b.number){ return a.idx < b.idx;}
        else{ return a.number < b.number;} // Number 비교
    }
    else{
        return a.head < b.head;
    }
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<infos> fileInfo;
    int cnt = 0;

    for(string str:files){
        string head; int number; string tail;
        int i=0;
        string temp = "";
        
        // Head
        for(i=0;i<str.size();i++){
            if(str[i] >= '0' && str[i] <= '9'){ head = temp; temp = ""; break;}
            temp += tolower(str[i]);
        }
        
        // Number
        for(i;i<i+5;i++){
            if(str[i] >= '0' && str[i] <= '9'){ temp += str[i];}
            else{ number = stoi(temp); temp = ""; break; }
        }
        
        // Save
        fileInfo.push_back({str, head, number, cnt++});
        
    }
    
    // Sort
    sort(fileInfo.begin(), fileInfo.end(), compare);
    
    for(auto item:fileInfo){
        answer.push_back(item.fullName);
    }
    
    
    return answer;
}