#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.length() < b.length()){
        return true;
    }
    else if(a.length() == b.length()){
        if(a<b){ return true;}
    }
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> reverse_words;
    
    // Words -> 가능한 단어 미리 기록
    // 순방향(query "?": 접미사일 경우)
    sort(words.begin(), words.end(), compare);
    
    // 역방향(query "?": 접두사일 경우)
    for(auto w:words){
        string rString = w;
        reverse(rString.begin(),rString.end());
        reverse_words.push_back(rString);
    }
    sort(reverse_words.begin(), reverse_words.end(), compare);
    
    // Query 검색 키워드 매칭
    for(int i=0;i<queries.size();i++){
        int end = queries[i].size()-1;
        
        // "?" : 접미사 -> Use original words
        if(queries[i][end] == '?'){
            string str = "";
            int cnt = 0;
            for(int j=0;j<=end;j++){
                if(queries[i][j] == '?'){
                    cnt++;
                    continue;
                }
                str += queries[i][j];
            }
            string first = str;
            string last = str;
            while(cnt--){
                first += "a";
                last += "z";
            }
            
            // Binary Search - lower, upper bound로 탐색
            int result = upper_bound(words.begin(), words.end(), last, compare) - lower_bound(words.begin(), words.end(), first, compare);
            answer.push_back(result);
            
        }
        // "?" : 접두사 -> Use reverse words
        else if(queries[i][0] == '?'){
            string str = "";
            int cnt = 0;
            for(int j=end;j>=0;j--){
                if(queries[i][j] == '?'){
                    cnt++;
                    continue;
                }
                str += queries[i][j];
            }
            
            string first = str;
            string last = str;
            while(cnt--){
                first += "a";
                last += "z";
            }
            
            // Binary Search - lower, upper bound로 탐색
            int result = upper_bound(reverse_words.begin(), reverse_words.end(), last, compare) - lower_bound(reverse_words.begin(), reverse_words.end(), first, compare);
            answer.push_back(result);
        }
        
    }
    
    return answer;
}