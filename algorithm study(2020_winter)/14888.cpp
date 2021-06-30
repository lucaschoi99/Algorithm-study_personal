#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    int v[11];
    vector<int> ans;
    cin >> n;

    // N numbers
    for(int k=0;k<n;k++){
        int a;
        cin >> a;
        v[k] = a;
    }
    
    // 4개의 연산자
    // plus=0, minus=1
    // multiple=2, division=3
    vector<int> cal;
    for(int i=0;i<4;i++){
        int cnt;
        cin >> cnt;
        if(i==0){
            while(cnt--){cal.push_back(0);}
        }
        else if(i==1){
            while(cnt--){cal.push_back(1);}
        }
        else if(i==2){
            while(cnt--){cal.push_back(2);}
        }
        else{
            while(cnt--){cal.push_back(3);}
        }
    }
    // sort
    sort(cal.begin(), cal.end());
    int count=0;
    int temp=0;
    // Try all possibility
    // using next permutation
    do {
        for (auto it = cal.begin(); it != cal.end(); it++){
            if(count==0){ // first iter
                if(*it == 0){temp = v[count] + v[count+1]; count = 2;}
                else if(*it == 1){temp = v[count] - v[count+1]; count = 2;}
                else if(*it == 2){temp = v[count] * v[count+1]; count = 2;}
                else{temp = v[count] / v[count+1]; count= 2;}
            }
            else{ // others
                if(*it == 0){temp += v[count]; count++;}
                else if(*it == 1){temp -= v[count]; count++;}
                else if(*it == 2){temp *= v[count]; count++;}
                else{temp /= v[count]; count++;}
            }
        }
        ans.push_back(temp);
        count = 0; // initialize
        temp = 0;

    } while (next_permutation(cal.begin(), cal.end()));

    // print answer
    int max = *max_element(ans.begin(), ans.end());
    int min = *min_element(ans.begin(), ans.end());
    cout << max << "\n" << min;
}