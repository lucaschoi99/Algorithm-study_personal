#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define NUM 1000000000

struct extendedGcdResult{
    long long int s;
    long long int t;
    long long int r;
};

extendedGcdResult eGcd(long long a, long long b){
    long long int s0 = 1, t0 = 0, r0 = a;
    long long int s1 = 0, t1 = 1, r1 = b;

    long long int temp;
    while(r1 != 0){
        long long int q = r0 / r1;

        temp = r0 - q*r1;
        r0 = r1;
        r1 = temp;

        temp = s0 - q*s1;
        s0 = s1;
        s1 = temp;

        temp = t0 - q*t1;
        t0 = t1;
        t1 = temp;
    }
    extendedGcdResult result{s0,t0,r0};
    return result;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        long long int K, C;
        cin >> K >> C;

        long long int a,b;
        a= K;
        b= C;
        extendedGcdResult result = eGcd(a,b);
        //cout << "result: " << result.s << " " << result.t << " "<< result.r << "\n";

        if(result.r != 1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            // General solution
            // x = result.s + b*m
            // y = result.t - a*m
            long long int x,y; 

            // Compute k range
            long long int left = ceil((result.t - NUM) / a);
            long long int right = min(ceil((-1)*((double)result.s / (double)b))-1, ceil((double)result.t/(double)a)-1);

            if(left > right){
                cout << "IMPOSSIBLE\n";
            }
            else{
                // Grab any k satisfying condition
                long long int m = left;
                cout << result.t - a*m << "\n";
            }

        }
    }
}