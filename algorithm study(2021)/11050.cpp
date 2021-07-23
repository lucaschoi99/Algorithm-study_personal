#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int fact(int x){
    if(x == 0 || x==1){
        return 1;
    }
    return x*fact(x-1);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,K;
    cin >> N >> K;

    if(K > (N/2)){
        K = N-K;
    }
    
    cout << fact(N) / fact(K) / fact(N-K);

}