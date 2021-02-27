#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;

    while(n--){
        int num;
        cin >> num;

        // insert into vector
        v.push_back(num);
    }

    // Create a map to store the frequency of each element in vector
    map<int, int> countMap;
    // Iterate over the vector and store the frequency of each element in map
    for (auto & elem : v)
    {
        auto result = countMap.insert(pair<int, int>(elem, 1));
        if (result.second == false)
            result.first->second++;
    }

    // Map to store answer
    map<int,int> ans;
    int cnt=0;
    map<int,int>::iterator iter;
    for(iter=countMap.begin();iter!=countMap.end();iter++){
        ans[iter->first] = cnt;
        cnt += 1;
    }

    for (auto & elem : v)
    {
        cout << ans[elem] << " ";
    }
}