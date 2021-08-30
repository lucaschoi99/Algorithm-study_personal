#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    // Step1
    for(int i=0;i<new_id.size();i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z'){
            new_id[i] += 32;
        }
    }
    
    // Step2
    string ret= "";
    for(int i=0;i<new_id.size();i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '.' || new_id[i] == '_'){
            ret += new_id[i];
        }
    }
    new_id = ret;
    
    // Step3
    int cnt=0;
    ret = "";
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]== 46){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt <= 1){
            ret += new_id[i];
        }
    }
    new_id = ret;
    
    // Step4
    if(new_id[0] == 46){
        new_id.erase(new_id.begin());
    }
    
    int idx = new_id.size()-1;
    if(new_id[idx] == 46){
        new_id.erase(idx);
    }
    
    // Step5
    if(new_id.size() == 0){
        new_id += "a";
    }
    // Step6
    if(new_id.size() >= 16){
        new_id.erase(15);
    }
    
    if(new_id[new_id.size()-1] == 46){
        new_id.erase(new_id.size()-1);
    }
    
    // Step7
    if(new_id.size() == 1){
        new_id += new_id[0];
        new_id += new_id[0];
    }
    if(new_id.size() == 2){
        new_id += new_id[1];
    }
    return new_id;
}