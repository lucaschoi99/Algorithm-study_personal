#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// gcd(a,b) = gcd(b, a mod b)
int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n;
    vector<int> vec;
    vector<int> LR;
    vector<int> RL;

    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    LR.resize(n,0);
    RL.resize(n,0);

    // LtoR gcd array (Prefix sum)
    int gcdSum = vec[0];
    LR[0] = gcdSum;
    for(int i=1;i<n;i++){
        LR[i] = gcd(LR[i-1], vec[i]);
    }
    // RtoL gcd array (Prefix sum)
    gcdSum = vec[n-1];
    RL[n-1] = gcdSum;
    for(int i=n-2;i>=0;i--){
        RL[i] = gcd(RL[i+1], vec[i]);;
    }

    // Delete each element
    // O(n^2) -> O(n)
    // by using prefix sum arrays
    int result;
    int max=0;
    int maxIndex =0;
    for(int i=0;i<n;i++){
        result = 0;
        if(i == 0){ // Use RL
            result = RL[1];
        }
        else if(i == n-1){ // Use LR
            result = LR[n-2];
        }
        else{ // between 1, n
            result = gcd(LR[i-1] , RL[i+1]);
        }

        if(vec[i] % result != 0 && result > max){
            max = result;
            maxIndex = i;
        }
        
        
    }
    if(max == 0){
        cout << -1;
        return 0;
    }
    cout << max << " " << vec[maxIndex];


}