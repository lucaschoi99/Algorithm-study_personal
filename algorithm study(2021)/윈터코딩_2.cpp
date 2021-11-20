#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int time, int gold, vector<vector<int>> upgrade) {
    int answer = 0;
    
    // Upgrade info
    vector<pair<double,double>> upgrade_info;
    for(auto elem:upgrade){
        double upgrade_cost = elem[0];
        double t = elem[1];
        
        upgrade_info.push_back(pair<double,double>(upgrade_cost, t));
        
    }
    
    // Profit - each level
    for(int final_level = 1;final_level <= upgrade.size();final_level++){
        int current_level = 1;
        int totalTime = time;
        bool possible = true;
        double profit = 0;
        
        while(current_level < final_level){
            double cost = upgrade_info[current_level-1].first;
            double timePerRock = upgrade_info[current_level-1].second;
            double nextCost = upgrade_info[current_level].first;
            
            int timeSpent = ceil((double)nextCost / gold) * timePerRock;
            
            if(profit >= nextCost){
                profit -= nextCost;
                current_level++;
                continue;
            }
            profit += (timeSpent / timePerRock * gold);
            
            if(totalTime <= timeSpent && nextCost > profit){ possible = false; break;}
            else{ // Upgrade to next level
                totalTime -= timeSpent;
                profit -= nextCost;
            }
            current_level++;
        }
        
        if(possible){ // Final Step
            double addProfit = floor(totalTime / upgrade_info[final_level-1].second) * gold;
            profit += addProfit;
        }
        
        // Answer
        if(answer < profit){
            answer = profit;
        }
    }
    
    return answer;
}