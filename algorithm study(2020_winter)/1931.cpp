#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt=0;
    cin >> n;
    vector<pair<int,int>> v;
    vector<pair<int,int>>::iterator iter;

    for(int i=0;i<n;i++){ 
        int a, b;
        cin >> a >> b;

        v.push_back(pair<int,int>(b,a)); //reverse order of start, end time
    }
    
    sort(v.begin(), v.end());
    cnt++; //first conference

    int end = v.begin()->first;

    //search by end time ascending order 
    for(iter = v.begin()+1;iter != v.end();iter++){
        if(end <= iter->second){
            cnt++; //another conference held
            end = iter->first; //update end time
        }
    }
    cout << cnt << "\n";
}
