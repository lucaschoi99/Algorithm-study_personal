#include<iostream>
#include<vector>
using namespace std;

const int MAX= 500001;
vector<int> v[MAX];
bool visited[MAX];
int sum=0;

void leafheight(int num, int height){
    bool isleaf = true;
    visited[num] = true;

    for(int k=0;k<v[num].size();k++){
        int node = v[num][k]; //next node to find
        if(!visited[node]){ //meaning "have children"
            isleaf = false;
            leafheight(node, height+1);
        }
    }
    if(isleaf){sum += height;}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n;
    cin >> n;

    for(int k=0;k<n-1;k++){
        int a,b;
        cin >> a >> b;

        //both direction
        v[a].push_back(b);
        v[b].push_back(a);
    }

    leafheight(1, 0); //sum up numbers of leaf nodes' height

    if(sum % 2 ==0){
        //sum == even number
        cout << "No";
    }
    else{
        //sum == odd number
        cout << "Yes";
    }
	return 0;
}
