#include <math.h>
#include <iostream>

using namespace std;

long long solution(int w,int h) {
    long long row = w;
    long long col = h;
    
    long long answer = row * col;
    
    for(int i=0;i<row;i++){
        long long y1 = (long double)col * i / (long double)row; // floor -> long long convert시 자동 trunc
        long long y2 = ((long double)col * (i+1) + (long double)(row-1)) / row; // ceil -> row-1 더해주고 trunc
        
        answer -= (y2-y1);
        
    }
    
    return answer;
}