#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100000;
bool visited[MAX];

bool isValid(int num){
    if(num <0 || num>100000 ||visited[num]){
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    int ans=0;
    cin >> n >> k;

    if(n>=k){
        cout << n-k;
    }
    else{ // n<k(main case)
        queue<int> v;
        int chunk =1;
        v.push(n);
        visited[n] = true;

        while(!v.empty()){
            // for each elements
            int cnt=0;

            // process by chunk
            for(int c=0;c<chunk;c++){
                int tmp = v.front();
                v.pop();

                // search if equals to k
                if(tmp == k){
                    cout << ans;
                    return 0;
                }
                //insert -1, +1, *2
                if(isValid(tmp-1)){
                    v.push(tmp-1);
                    visited[tmp-1] = true;
                    cnt++;
                }
                if(isValid(tmp+1)){
                    v.push(tmp+1);
                    visited[tmp+1] = true;
                    cnt++;
                }
                if(isValid(2*tmp)){
                    v.push(2*(tmp));
                    visited[2*(tmp)] = true;
                    cnt++;
                }
                
            }
            chunk = cnt;
            ans++;
            
        }
    }
}
