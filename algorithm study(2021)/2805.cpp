#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int N,M;
    cin >> N >> M;

    int *trees = new int[N];
    long long int top=0;
    for(int i=0;i<N;i++){
        long long int length;
        cin >> length;
        trees[i] = length;
        top = max(top, length);
    }

    long long int start=0;
    long long int mid;
    long long int result=0;
    
    while(true){
        long long int sum=0;
        mid = (top + start) /2;

        for(int i=0;i<N;i++){
            if(trees[i] > mid){
                sum += trees[i] - mid;
            }
        }

        if(sum > M){
            start = mid +1;
            result = mid;
        }
        else if(sum == M){
            result = mid;
            break;
        }
        else{
            top = mid - 1;
        }

        if(start > top){ // Termination condition
            break;
        }

    }
    
    cout << result;

}
