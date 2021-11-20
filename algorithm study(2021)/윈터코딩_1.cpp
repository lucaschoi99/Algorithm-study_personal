#include <string>
#include <vector>
#include <map>

using namespace std;

struct monsterInfo{
    string name;
    int exp;
    int hp;
    int off;
    int def;
};

string solution(string character, vector<string> monsters) {
    string answer = "";
    map<string, pair<double,int>> answers;

    // Character info
    vector<string> char_infos;

    string newString = "";
    int idx = 0;
    for(char ch:character){
        if(ch != ' '){
            newString += ch;
            if(idx == character.size()-1){
                char_infos.push_back(newString);
                newString = "";
            }
        }
        else{
            char_infos.push_back(newString);
            newString = "";
        }
        idx++;
    }
    int char_hp = stoi(char_infos[0]);
    int char_off = stoi(char_infos[1]);
    int char_def = stoi(char_infos[2]);
    
    
    // Monster info
    vector<struct monsterInfo> infos;
    
    for(string elem:monsters){
        struct monsterInfo monster;
        vector<string> mon_infos;

        string newString = "";
        int idx = 0;
        for(char ch:elem){
            if(ch != ' '){
                newString += ch;
                if(idx == elem.size()-1){
                    mon_infos.push_back(newString);
                    newString = "";
                }
            }
            else{
                mon_infos.push_back(newString);
                newString = "";
            }
            idx++;
        }
        monster.name = mon_infos[0];
        monster.exp = stoi(mon_infos[1]);
        monster.hp = stoi(mon_infos[2]);
        monster.off = stoi(mon_infos[3]);
        monster.def = stoi(mon_infos[4]);
        
        infos.push_back(monster);
    }
    
    // Monster 게임 진행
    for(auto item:infos){
        bool done = false;
        bool gotcha = false;
        int time = 0;
        
        string monster_name = item.name;
        int monster_exp = item.exp;
        int monster_hp = item.hp;
        int monster_off = item.off;
        int monster_def = item.def;
        int player_hp = char_hp;
        
        
        while(!done){
            // Time count
            time++;
            
            // Step1: Player attacks
            if(char_off - monster_def > 0){
                monster_hp -= (char_off - monster_def);
            }
            else{ done = true;}

            // Step2: terminate condition
            if(monster_hp <= 0){
                done = true;
                gotcha = true;
            }

            // Step3: Monster attacks
            if(monster_off - char_def > 0){
                player_hp -= (monster_off - char_def);
            }

            // Step4: terminate condition
            if(player_hp <= 0){
                done = true;
            }

            // Step5: Again
            if(!done){ player_hp = char_hp;}
        }
        
        if(gotcha){
            double exp_per_time = double(monster_exp) / time;
            pair<double,int> temp;
            temp = pair<double,int>(exp_per_time, monster_exp);
            answers[monster_name] = temp;
        }
    }
    
    // Final Answer
    map<string, pair<double,int>>::iterator iter;
    double finalTime = 0;
    int finalExp = 0;
    
    for(auto iter = answers.begin();iter!=answers.end();iter++){
        string name = iter->first;
        pair<double,int> temp = iter->second;
        double expTime = temp.first;
        int exp = temp.second;
        
        if(expTime > finalTime){
            finalTime = expTime;
            finalExp = exp;
            answer = name;
        }
        else if(expTime == finalTime){
            if(exp > finalExp){
                finalTime = expTime;
                finalExp = exp;
                answer = name;
            }
        }
    }
    
    return answer;
}