#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    float n, a ,b, c;
    long long int cnt=0;
    vector<int> v;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    cin >> b >> c;

    for(float item:v){
        // Advisor
        cnt++;
        item -= b;
        
        // Vice-Advisor
        if(item > 0.1){
            int q = ceil(item / c);
            cnt += q;
        }
    }
    
    cout << cnt;
    

}
