#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> mp1;
    map<string, int> mp2;
    
    int ans1 = 0;
    int ans2 = 0;
    
    // 두글자씩 묶기
    for(int i=0;i<str1.size()-1;i++){
        string newString = "";
        newString += tolower(str1[i]);
        newString += tolower(str1[i+1]);
        
        bool isNotAlpha = false;
        if('a' > newString[0] || newString[0] > 'z'){
            isNotAlpha = true;
        }
        if('a' > newString[1] || newString[1] > 'z'){
            isNotAlpha = true;
        }
        
        if(!isNotAlpha){ // 다중집합 원소로 삽입
            if(mp1.find(newString) == mp1.end()){ // Not exists
                mp1[newString] = 1;
            }
            else{
                mp1[newString]++;
            }
        }
        
    }
    
    for(int i=0;i<str2.size()-1;i++){
        string newString = "";
        newString += tolower(str2[i]);
        newString += tolower(str2[i+1]);
        
        bool isNotAlpha = false;
        if('a' > newString[0] || newString[0] > 'z'){
            isNotAlpha = true;
        }
        if('a' > newString[1] || newString[1] > 'z'){
            isNotAlpha = true;
        }
        
        if(!isNotAlpha){ // 다중집합 원소로 삽입
            if(mp2.find(newString) == mp2.end()){ // Not exists
                mp2[newString] = 1;
            }
            else{
                mp2[newString]++;
            }
        }
    }
    
    // 다중집합 비교
    int cnt = 0;
    int sum = 0;
    for(auto elem:mp1){
        if(mp2.find(elem.first) != mp2.end()){ // Found
            int minVal = min(mp1[elem.first], mp2[elem.first]);
            int maxVal = max(mp1[elem.first], mp2[elem.first]);
            
            cnt += mp2[elem.first];
            sum += maxVal;
            
            ans1 += minVal;
        }
        else{ // Not found
            sum += mp1[elem.first];
        }
    }
    
    for(auto elem:mp2){
        cnt -= mp2[elem.first];
    }
    ans2 = (-1)*cnt + sum;
    
    if(ans1 == 0 && ans2 == 0){
        return 65536;
    }
    answer = trunc(((double)ans1 / ans2) * 65536);
    return answer;
}