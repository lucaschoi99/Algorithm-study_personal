#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,K;
    vector<pair<int,int>> jewl;
    vector<int> bags;

    cin >> N >> K;

    for(int i=0;i<N;i++){
        int weight;
        int price;
        cin >> weight >> price;
        jewl.push_back(pair<int,int>(weight,price));
    }
    for(int i=0;i<K;i++){
        int weight;
        cin >> weight;
        bags.push_back(weight);
    }

    // Sort jewl, bags by weight asc
    sort(jewl.begin(), jewl.end());
    sort(bags.begin(), bags.end());

    // Priority queue to maintain price desc
    priority_queue<int> pq;
    int idx = 0;
    long long int ans=0;

    // For each bags, choose smaller jewl using 2-pointer
    // and fetch the most expensive jewl
    for(int i=0;i<K;i++){
        for(idx;idx<jewl.size();idx++){
            if(bags[i] >= jewl[idx].first){
                pq.push(jewl[idx].second);
            }
            else{
                //idx--;
                break;
            }
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}
