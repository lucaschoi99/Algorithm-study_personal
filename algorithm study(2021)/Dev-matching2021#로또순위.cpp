#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // Matching number 몇개인지 파악
    int minVal = 0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    
    int i=0; int j=0;
    int zeros = 0;
    
    for(i;i<lottos.size();i++){
        if(lottos[i] == 0){
            zeros++;
            continue;
        }
        
        for(j=0;j<win_nums.size();j++){
            if(lottos[i] == win_nums[j]){
                minVal++;
                break;
            }
        }
    }
    
    // 가능한 점수 범위
    int maxNum = minVal + zeros;
    int minNum = minVal;
    
    // 점수 별 순위표
    map<int,int> mp;
    mp[0] = 6; mp[1] = 6; mp[2] = 5; mp[3] = 4; mp[4] = 3; mp[5] = 2; mp[6] = 1;
    
    answer.push_back(mp[maxNum]);
    answer.push_back(mp[minNum]);
    
    return answer;
}