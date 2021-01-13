#include<iostream>
#include<cmath>
using namespace std;

//num array
const int MAX = 50001;
int num[MAX] = {0,};
//num to be computed
int n;

//compute sum of powers equal to num
void solve(){
    for(int i=1;i<n+1;i++){
        int min = 5;
        int tmp,cnt;
        
        //squared number -> 1
        if((int)sqrt(i) * sqrt(i) == i){
            num[i] = 1;
            continue;
        }
        for(int k=sqrt(i);k>0;k--){
            cnt = 0;
            tmp = num[i-k*k] +1; //use previous num array
            if(tmp < min){
                min = tmp;
            }
        }
        num[i] = min; //update min
    }
    
    
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n;

    solve();

    cout << num[n];
    

	return 0;
}