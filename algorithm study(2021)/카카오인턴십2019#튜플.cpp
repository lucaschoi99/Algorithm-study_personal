#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a.size() < b.size();
}


vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vec;
    
    stack<char> st;
    st.push('{');
    
    // 데이터 전처리
    vector<int> temp;
    string newString = "";
    for(int i=1;i<s.size();i++){
        if(s[i] == '{'){ st.push(s[i]);}
        else if(s[i] == '}'){ if(st.size() == 1 && st.top() == '{'){ vec.push_back(temp);}
                             temp.push_back(stoi(newString)); st.pop();
                            }
        else if(st.size() == 1 && s[i] == ','){ vec.push_back(temp); temp.clear(); newString = "";}
        else if(st.size() > 1 && s[i] == ','){ temp.push_back(stoi(newString)); newString = "";}
        else{ newString += s[i]; }
    }
    
    // 원소개수 오름차순 정렬
    sort(vec.begin(), vec.end(), cmp);
    
    // Answer
    for(int i=0;i<vec.size();i++){
        if(answer.empty()){ answer.push_back(vec[i][0]);}
        else{
            for(int j=0;j<answer.size();j++){
                for(int k=0;k<vec[i].size();k++){
                    if(vec[i][k] == answer[j]){ vec[i].erase(find(vec[i].begin(), vec[i].end(), answer[j])); break;}
                }
            }
            answer.push_back(vec[i][0]);
            }
    }

    return answer;
}