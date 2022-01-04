#include <bits/stdc++.h>
#define MAX 15
using namespace std;

int queen[MAX];
int cnt=0, maxSize;

void init(int sz){
    for(int i=0;i<sz;i++){
        queen[i] = -1;
    }
}

bool isPossible(int row){
    for(int i=row-1;i>=0;i--){
        int diffVal = abs(queen[row] - queen[i]);
        int diffRow = abs(row - i);

        // 일직선상, 대각선
        if(diffVal == 0 || diffVal == diffRow){
            return false;
        }
    }
    return true;
}

void simulate(int row){
    int ret = 0;

    if(row >= maxSize){
        cnt++;
        return;
    }

    for(int i=0;i<maxSize;i++){
        queen[row] = i;

        if(isPossible(row)){
            simulate(row+1);
        }
    }

    return;
}



int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int sz;
    cin >> sz;
    maxSize = sz;

    init(sz);
    simulate(0);
    
    cout << cnt << "\n";

}
