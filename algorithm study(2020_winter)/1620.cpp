#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    map<int, string> m1;
    map<string, int> m2;
    int cnt=1;
    
    while(n--){
        string name;
        cin >> name;

        // insert both sides 
        m1.insert(pair<int,string>(cnt,name));
        m2.insert(pair<string, int>(name,cnt));
        cnt++;
    }
    while(m--){
        string target;
        int num;

        cin >> target;

        // check type
        if(isdigit(target[0])){ // int
            num = stoi(target);
            // find name in m1
            cout << m1[num] << "\n";
        }
        else{ // string
            // find num in m2
            cout <<  m2[target] << "\n";
        }
        
    }
    
}
