#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 41;
int zero[MAX];
int one[MAX];

//array zeros and ones
void fibonacci_solve(int n){
    for(int i=0;i<n+1;i++){
        if(i==0){
            zero[i] = 1;
            one[i] = 0;
            continue;
        }
        if(i==1){
            zero[i] = 0;
            one[i] = 1;
            continue;
        }
        //use previous num array
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    cout << zero[n] << " " << one[n] << "\n";
    
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int T; //testcases
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        fibonacci_solve(N);
    }

	return 0;
}