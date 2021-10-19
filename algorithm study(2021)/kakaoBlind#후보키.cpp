#include <string>
#include <vector>
#include <set>

using namespace std;

// 최소성 확인
// -> 후보키 추가 후보인 item이 이전에 후보키로 선정된 것을 포함한다면 배제
bool minimality(int item, vector<int> ans){
    for(int i=0;i<ans.size();i++){
        if((ans[i] & item) == ans[i]){ // item이 이전 후보키를 포함함
            return false;
        }
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    int rowSize = relation.size();
    int colSize = relation[0].size();
    vector<int> ans;
    
    // 모든 가능한 조합의 수
    for(int i=1;i<(1<<colSize);i++){
        set<string> current;
        
        // Set 배열에 현재 탐색하는 col 정보 저장
        for(int j=0;j<rowSize;j++){
            string item = "";
            for(int k=0;k<colSize;k++){
                if(i & (1<<k)){ // 현재 탐색하는 행 추가
                    item += relation[j][k] + " ";
                }
            }
            current.insert(item);
        }
        
        // 유일성 확인
        if(rowSize == current.size()){ // 유일성 True
            if(minimality(i, ans)){ // 최소성 True
                ans.push_back(i);
            }
        }
    }
    
    return ans.size();
}