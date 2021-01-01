#include<iostream>
#include<map>
using namespace std;

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> mp;

    int m, n;
    cin >> n >> m;
    while (n--) {
        string val;
        cin >> val;
        mp[val] = 1;
    }
    int ans = 0;
    while (m--) {
        string val;
        cin >> val;
        if (mp[val] == 1) {
            ans++;
        }
    }
    cout << ans;


    return 0;
}
