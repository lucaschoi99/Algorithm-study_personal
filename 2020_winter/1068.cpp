#include<iostream>
#include<vector>
using namespace std;

vector<int> v[50];

void deleteNode(int node) {
    //deleted node's children not a leaf node anymore
    for (int k = 0; k < v[node].size(); k++) {
        deleteNode(v[node][k]);
    }
    v[node].push_back(-1); //not a leaf node
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {
        int num;
        cin >> num;
        if (num != -1) {
            v[num].push_back(k);
        }
    }

    //count leaf node
    int cnt = 0;

    int node2delete;
    cin >> node2delete;

    //check if node to be deleted is a single child of parent node
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < v[k].size(); l++) {
            if (v[k][l] == node2delete && v[k].size() == 1) {
                cnt++; //add leaf node
            }
        }
    }

    //deleted node's child not a leaf node
    deleteNode(node2delete);

    //deleted node also is not a leaf node anymore
    v[node2delete].push_back(-1);

    
    for (int k = 0; k < n; k++) {
        if (v[k].size() == 0) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
