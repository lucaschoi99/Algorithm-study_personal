#include<iostream>
#include<vector>
using namespace std;

const int MAX = 128;
vector<vector<int>> v(MAX, vector<int>(MAX,-1));
int white=0;
int blue=0;

// check if colored same
void isColored(int size,int r,int c, bool flag){
    int target = v[r][c];
    // compare
    for(int a=0;a<size && !flag;a++){
        for(int b=0;b<size;b++){
            if(target != v[r+a][c+b]){ // check color match
                // recursive call
                isColored(size/2,r,c,false);
                isColored(size/2,r,c+(size/2),false);
                isColored(size/2,r+(size/2),c,false);
                isColored(size/2,r+(size/2),c+(size/2),false);
                flag = true;
                break;
            }
        }
    }
    // for completed ones
    if(target == 0 && !flag){ // white
        white++;
    }
    else if(target == 1 && !flag){ // blue
        blue++;
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    // resize vector v
    v.resize(n,vector<int>(n,0));

    // input into vectors
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            int num;
            cin >> num;
            v[i][k] = num;
        }
    }

    // start check
    isColored(n,0,0,false);

    //answer
    cout << white << "\n" << blue;
    
}