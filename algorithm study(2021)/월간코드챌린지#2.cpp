#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int row = left / n;
    int col = left % n;
    
    int endRow = right / n;
    int endCol = right % n;
    
    vector<int> array;
    for(int i=row;i<=endRow;i++){
        for(int j=0;j<=i;j++){
            array.push_back(i+1);
        }
        for(int j=i+1;j<n;j++){
            array.push_back(j+1);
        }
    }
    
    answer = {array.begin()+col, array.end()-(n-endCol-1)};
    
    return answer;
}