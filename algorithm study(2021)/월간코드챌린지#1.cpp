#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int target = n-1;
    vector<int> quotients;
    for(int i=1;i<=target/2;i++){
        if(target % i == 0){
            quotients.push_back(i);
        }
    }
    int maxVal = quotients.back();
    answer = target / maxVal;
    
    return answer;
}