#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;
    map<string, int> ids;
    
    for(int i=0;i<id_list.size();i++){
        map<string, bool> visited;
        string newId = "";
        
        for(int j=0;j<id_list[i].size();j++){
            if(id_list[i][j] != ' '){
                newId += id_list[i][j];
                
                if(j == id_list[i].size()-1){
                    if(ids.find(newId) != ids.end()){ // Found
                        if(!visited[newId]){
                            ids[newId]++;
                            visited[newId] = true;
                        }
                    }
                    else{
                        ids[newId] = 1;
                        visited[newId] = true;
                    }
                    newId = "";
                }
            }
            else{
                if(ids.find(newId) != ids.end()){ // Found
                    if(!visited[newId]){
                        ids[newId]++;
                        visited[newId] = true;
                    }
                }
                else{
                    ids[newId] = 1;
                    visited[newId] = true;
                }
                newId = "";
            }
        }
        for(auto it = visited.begin();it!= visited.end();it++){
            it->second = false;
        }
    }
    
    for(auto elem:ids){
        if(elem.second <= k){
            answer += elem.second;
        }
        else{
            answer += k;
        }
    }
    
    return answer;
}