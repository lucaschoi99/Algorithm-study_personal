#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

const int MAX = 200001;
const int PLACE = 1048577;
vector<int> ducks[MAX];
bool visited[PLACE] = { false, };

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long int n, q;
    cin >> n >> q;

    //input data
    for (int k = 0; k < q; k++) {
        long int num;
        cin >> num;
        ducks[k].push_back(num);
    }

    //start with ascending order
    for (int k = 0; k < q; k++) {
        long int temp = ducks[k][0];
        while (temp != 1) {
            if (visited[temp]) { //if passed already visited node
                cout << temp << '\n';
                break;
            }
            temp /= 2;
        }
        
        if (!visited[temp]) { //if passed successfully
            visited[ducks[k][0]] = true; //check visit
            cout << 0 << '\n'; 
        }
        
    }

    return 0;
}
