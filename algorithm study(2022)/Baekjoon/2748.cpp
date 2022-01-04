#include<iostream>
#include<vector>
#define MAX 90
using namespace std;

long long fiboArr[MAX];

void fibo(int n){
    fiboArr[0] = 0;
    fiboArr[1] = 1;

    for(int i=2;i<=n;i++){
        fiboArr[i] = fiboArr[i-1] + fiboArr[i-2];
    }
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int size;
    cin >> size;

    fibo(size);
    cout << fiboArr[size];
}
