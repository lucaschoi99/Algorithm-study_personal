#include<iostream>
using namespace std;

const int MAX = 1000001;
int N;
//index in array indicate number
//array value indicate how many steps to 1
int arr[MAX] = {0,}; 

void solve(){
    arr[1] = 0;
    for(int i=2;i<N+1;i++){
        arr[i] = arr[i-1] +1; //subtract 1 (rule #3)
        if(i % 2 == 0){ //divide to 2 (rule #2)
            arr[i] = min(arr[i], arr[i/2]+1);
        }
        if(i % 3 ==0){ //divide to 3 (rule #1)
            arr[i] = min(arr[i], arr[i/3] + 1);
        }
    }
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> N;

    solve();
    
    cout << arr[N];

	return 0;
}