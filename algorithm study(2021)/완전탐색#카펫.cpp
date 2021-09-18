#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> vec;
    
    // Yellow 두 수의 곱으로 표현
    for(int i=1;i<=sqrt(yellow);i++){
        if(yellow % i == 0){
            int m,n;
            if(i >= yellow/i){
                m = i;
                n = yellow/i;
            }
            else{
                m = yellow/i;
                n = i;
            }
            vec.push_back(pair<int,int>(m,n));
        }
    }
    
    // 가능한 경우인지 Brown 개수로 확인
    for(auto vi:vec){
        int width = vi.first + 2;
        int length = vi.second + 2;
        if(width * length - yellow == brown){
            answer.push_back(width);
            answer.push_back(length);
            break;
        }
    }
    
    return answer;
}