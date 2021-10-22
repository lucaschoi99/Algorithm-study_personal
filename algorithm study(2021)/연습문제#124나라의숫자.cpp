#include <string>
#include <vector>

using namespace std;

// 진법 계산을 인지하지 못하고 푼 풀이
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

string solution(int n) {
    long long nn = n;
    string result = "";
    long long next = 3;
    long long prev = 0;
    long long cnt = 1;

    while(n > next){
        prev += pow(3,cnt);
        next += pow(3, cnt+1);
        cnt++;
    }

    // 자릿수 : cnt
    vector<int> vec;
    vector<int> addNums;
    nn = nn - prev - 1;

    for(int i=0;i<cnt;i++){ vec.push_back(1);}

    for(int i=cnt-1;i>=0;i--){
        addNums.push_back((long long)(nn / pow(3,i)));
        nn -= (long long)(nn / pow(3,i)) * pow(3,i);
    }

    for(int i=0;i<cnt;i++){
        if(addNums[i] == 0){
            vec[i] = 1;
        }
        else if(addNums[i] == 1){
            vec[i] = 2;
        }
        else if(addNums[i] == 2){
            vec[i] = 4;
        }
    }

    for(int i=0;i<cnt;i++){
        result += to_string(vec[i]);
    }

    return result;
}


// 나중에 진법 계산으로 푼 풀이
int convert[3] = {4,1,2};

string solution(int n) {
    string result = "";

    // 0 없는 3진법처럼 계산
    // 0 나오는 경우 4로 계산할 것이기 때문에 몫-1로 이어서 계산
    while(true){
        int r = n % 3;
        result = to_string(convert[r]) + result;
        
        if(r == 0){
            n = n/3 -1;
        }
        else{
            n /= 3;
        }
        
        if(n <= 0){
            break;
        }
        
    }

    return result;
}