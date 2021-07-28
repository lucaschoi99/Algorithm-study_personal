#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NUM 1025

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    int **map = new int*[NUM];
    for(int i=0;i<NUM;i++){
        map[i] = new int[NUM];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num;
            cin >> num;
            // ith row prefix sum
            map[i][j] = map[i][j-1] + num;
        }
    }
    
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result=0;
        for(int j=x1;j<=x2;j++){
            // DP recurrence relation
            result += map[j][y2] - map[j][y1-1];
        }
        cout << result << "\n";
    }

}
