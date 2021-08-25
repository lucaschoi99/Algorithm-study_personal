#include <string>
#include <vector>
#include <algorithm>
#define NUM 10001
using namespace std;

vector<int> isAns;
int visited[NUM] = {false,};
vector<vector<string>> ansCand; // Answer 후보

void dfs(string city, vector<vector<string>> tickets, vector<int> currAns, vector<string> result, int cnt){
    
    for(int i=0;i<tickets.size();i++){
        if(!visited[i] && tickets[i][0] == city){ // 경로 후보지
            vector<int> current = currAns;
            current.push_back(i);
            vector<string> resultAns = result;
            resultAns.push_back(tickets[i][1]);
            
            visited[i] = true;
            dfs(tickets[i][1], tickets, current, resultAns, cnt+1);
            visited[i] = false;
        }
    }
    
    sort(currAns.begin(),currAns.end()); // Sort asc
    if(isAns == currAns){ // Answer 후보
        ansCand.push_back(result);
        return;
    }
    
    if(cnt > tickets.size()){ // Termination
        return;
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> currAns;
    vector<string> result;
    
    for(int i=0;i<tickets.size();i++){
        isAns.push_back(i);
    }
    result.push_back("ICN");
    // DFS
    dfs("ICN", tickets, currAns, result, 1);
    
    // Alphabetical order
    sort(ansCand.begin(),ansCand.end());
    answer = ansCand[0];
    return answer;
}