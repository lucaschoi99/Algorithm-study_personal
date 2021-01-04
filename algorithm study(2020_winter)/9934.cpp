#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    int num = int(pow(2, k)) - 1;
    
    //reserve vector space
    vector<int> v;
    v.reserve(num);
    for (int i = 0; i < num; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    //find regularity for each depth values
    while(k--) {
        int temp = int(pow(2, k)) - 1;
        if (num >= 3 * temp + 2) {
            int cnt = 0;
            while (num >= temp + cnt * (2 * (temp + 1))) {
                cout << v[temp + cnt * (2 * (temp + 1))] << ' ';
                cnt++;
            }
            cout << '\n';
            continue;
        }
        cout << v[temp] << '\n';
     }

    return 0;
}
