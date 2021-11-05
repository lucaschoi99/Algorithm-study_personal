#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> dict;
vector<int> temp;
int cnt = 27;

void dfs(string str, int idx){
    string newStr = "";
    newStr += str[idx];
    string tempStr = newStr;
    int count = idx;
    
    // Phase 2
    while(idx < str.size()-1){
        tempStr += str[count+1];
        if(dict.find(tempStr) != dict.end()){ // Found
            newStr += str[count+1];
            count++;
        }
        else{ break;} // Not found
    }
    
    // Phase 3
    temp.push_back(dict[newStr]);
    
    // Phase 4
    if(count+1 < str.size()){
        string nextStr = "";
        nextStr += newStr + str[count+1];
        dict[nextStr] = cnt++;
        dfs(str, count+1);
    }
    
}



vector<int> solution(string msg) {
    vector<int> answer;
    
    // Phase 1: Init
    char newChar = 'A';
    for(int i=1;i<=26;i++){
        string newString = "";
        newString += newChar++;
        dict[newString] = i;
    }
    
    // Phase 2 ~ Phase 5 : DFS
    dfs(msg, 0);
    
    answer = temp;
    
    return answer;
}