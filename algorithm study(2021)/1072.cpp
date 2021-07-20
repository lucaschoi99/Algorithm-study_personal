#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    long long int x,y;
    long long int z;
    cin >> x >> y;
    z = 100*y/x;
    if(z == 100 || z==99){ // Z cannot change
        cout << -1;
        return 0;
    }

    long long int start= 0;
    long long int top= x;
    long long int mid;
    
    // Parametric Search
    while(true){
        mid = (top + start) /2;
        long long int value= 100*(y+mid) / (x+mid);

        if(value == z){
            start = mid+1; // mid value no use anymore
        }
        else{
            top = mid; // keep mid value
        }
        
        if(start >= top){ // Termination condition
            break;
        }

    }
    
    cout << top;

}
