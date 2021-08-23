#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> unsortedArr;
        for(int k=commands[i][0]-1;k<=commands[i][1]-1;k++){
            unsortedArr.push_back(array[k]);
        }
        sort(unsortedArr.begin(),unsortedArr.end());
        answer.push_back(unsortedArr[commands[i][2]-1]);
    }
    
    
    return answer;
}