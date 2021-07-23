#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

string P;

bool checkIsBad(int x){ // Check if divisble
    int result = 0;
    for(int i=0;i<P.length();i++){
        result = (result * 10 + (P[i] - '0')) % x;
    }
    if(result == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int K;
    cin >> P >> K;

    int *vec = new int[K];
    vector<int> primes;

    // Initialize
    for(int i=0;i<K;i++){
        vec[i] = i;
    }

    // Get prime numbers
    bool visited[K] = {false,};
    for(int i=2;i<K;i++){
        if(!visited[i]){
            primes.push_back(i);
            for(int j=2*i;j<K;j+=i){
                visited[j] = true;
            }
        }
    }
    
    bool foundAnswer = false;
    for(int vi:primes){
        if(checkIsBad(vi)){
            cout << "BAD" << " " << vi;
            foundAnswer = true;
            break;
        }
    }
    
    if(!foundAnswer){
        cout << "GOOD";
    }
}