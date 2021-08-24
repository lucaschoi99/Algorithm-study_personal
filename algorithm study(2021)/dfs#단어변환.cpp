#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define NUM 51

using namespace std;

vector<int> ansArr;
int visited[NUM] = {false,};
queue<pair<int,int>> q;

// 한글자만 다른 단어 찾기
bool stringMatch(string current, string target){
    int num = 0;
    for(int i=0;i<current.size();i++){
        if(current[i] != target[i]){
            num++;
        }
    }
    if(num == 1){
        return true;
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool isPossible = false;
    
    // No target in words
    for(int i=0;i<words.size();i++){
        if(words[i] == target){isPossible = true;}
        else{continue;}
    }
    if(!isPossible){ 
        return 0;
    }
    
    // Begin
    for(int i=0;i<words.size();i++){
        if(stringMatch(begin, words[i]) && !visited[i]){
            // Push into the queue
            visited[i] = true;
            q.push(pair<int,int>(1,i));
            if(words[i] == target){ // Found answer at the first time
                return 1;
            }
        }
    }
    
    // BFS
    while(!q.empty()){
        int item = q.front().second;
        int currLength = q.front().first;
        q.pop();
        
        for(int i=0;i<words.size();i++){
            if(stringMatch(words[item], words[i]) && !visited[i]){
                // Push into the queue
                visited[i] = true;
                q.push(pair<int,int>(currLength+1,i));
                if(words[i] == target){ // Found answer
                    return currLength+1;
                }
            }
        }
    }
}