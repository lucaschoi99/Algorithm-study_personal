#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

// Row <-Index & Column <- Queen position
int chess[15]; // 1-dimension array
int cnt=0;
int n;

bool checkAvailable(int idx){
    for(int i=0;i<idx;i++){ // Check Cross & Vertical lines 
        if(abs(chess[idx]- chess[i]) == idx - i || chess[idx] == chess[i]){return false;} 
    }

    return true;
}

void solve(int i){
        // If succeed
        if(i == n){
            cnt++;
            return;
        }
        
        for(int x=0;x<n;x++){
            // Queen at
            // Row i , column x
            chess[i] = x;

            // Check position available
            if(checkAvailable(i)){
                solve(i+1);
            }
        }
        

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n;
    
    // Initialize
    for(int i=0;i<n;i++){
        chess[i] = -1;
    }

    solve(0);
    
    
    cout << cnt;

}
