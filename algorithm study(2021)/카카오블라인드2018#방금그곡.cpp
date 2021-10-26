#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int answerTime = 0;
    
    for(int a=musicinfos.size()-1;a>=0;a--){
        vector<string> infos;
        
        int startHour, startMin, endHour, endMin;
        int elapsed;
        
        string title, abcs;
        string newString = "";
        for(int i=0;i<musicinfos[a].size();i++){
            if(musicinfos[a][i] == ':' || musicinfos[a][i] == ','){ infos.push_back(newString); newString = "";}
            else{ newString += musicinfos[a][i];}
        }
        infos.push_back(newString);
        
        startHour = stoi(infos[0]);
        startMin = stoi(infos[1]);
        endHour = stoi(infos[2]);
        endMin = stoi(infos[3]);
        
        elapsed = (endHour - startHour) * 60 + (endMin - startMin);

        title = infos[4];
        abcs = infos[5];
        
        // 재생된 곡 정보
        vector<string> newMusic;
        string newInfo = "";
        for(int k=0;k<abcs.size()-1;k++){
            if(abcs[k+1] == '#'){ newInfo += abcs[k]; }
            else{ newInfo += abcs[k]; newMusic.push_back(newInfo); newInfo = "";}
        }
        if(newInfo == ""){ newInfo += abcs[abcs.size()-1]; newMusic.push_back(newInfo);}
        else{ newInfo += '#'; newMusic.push_back(newInfo);}
        
        
        // 재생된 전체 곡 정보
        int size = newMusic.size();
        vector<string> resultMusic;
        
        if(elapsed <= size){
            for(int k=0;k<elapsed;k++){ resultMusic.push_back(newMusic[k]);}
        }
        else{ // 반복
            int dup = elapsed / size;
            int remain = elapsed - dup*size;
            
            for(int k=0;k<dup;k++){ for(int t=0;t<size;t++){ resultMusic.push_back(newMusic[t]);}}
            for(int k=0;k<remain;k++){ resultMusic.push_back(newMusic[k]);}
        }
        
        // 문자열 m 들어있는지 확인
        vector<string> newM;
        string newInfoM = "";
        
        for(int k=0;k<m.size()-1;k++){
            if(m[k+1] == '#'){ newInfoM += m[k]; }
            else{ newInfoM += m[k]; newM.push_back(newInfoM); newInfoM = "";}
        }
        if(newInfoM == ""){ newInfoM += m[m.size()-1];  newM.push_back(newInfoM);}
        else{ newInfoM += '#'; newM.push_back(newInfoM);}
        
        int jj=0; int kk=0;
        
        for(jj=0;jj<resultMusic.size();jj++){
            if(newM[0] == resultMusic[jj]){
                int cnt = 1;
                for(kk=1;kk<newM.size();kk++){
                    if(newM[kk] == resultMusic[jj+kk]){ cnt++;}
                    else{ break;}
                }
                if(cnt == newM.size()){ // 조건에 맞는 답 후보
                    if(answerTime <= elapsed){ answer = title; answerTime = elapsed; }
                    break;
                }
            }
        }
        
    }
    
    
    return answer;
}