#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache;
    
    for(string str:cities){
        // Convert to lower case
        boost::algorithm::to_lower(str);
        
        if(cacheSize == 0){ answer += 5; continue;}
        
        if(count(cache.begin(), cache.end(), str)){ // Cache hit
            answer += 1;
            // Update Recently used ones
            cache.erase(find(cache.begin(), cache.end(), str));
            cache.push_back(str);
        }
        else{ // Cache miss
            answer += 5;
            if(cache.size() < cacheSize){
                cache.push_back(str);
            }
            else{
                cache.erase(cache.begin());
                cache.push_back(str);
            }
        }
    }
    
    
    return answer;
}