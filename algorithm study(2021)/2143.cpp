#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int T, n,m;
    cin >> T;
    cin >> n;
    long long int *seqA = new long long int[n+1];
    
    for(int i=0;i<n;i++){
        long long int num;
        cin >> num;
        seqA[i] = num;
    }
    cin >> m;
    long long int *seqB = new long long int[m+1];
    for(int i=0;i<m;i++){
        long long int num;
        cin >> num;
        seqB[i] = num;
    }
    
    // All subsets in A compute sum
    // Two pointer-sliding window
    vector<long long int> subA;
    long long int sum = 0;

    for(int i=0;i<n;i++){
        sum = seqA[i];
        subA.push_back(sum);
        for(int k=i+1;k<n;k++){
            sum += seqA[k];
            subA.push_back(sum);
        }
    }
    
    // subB in the same way
    vector<long long int> subB;
    sum = 0;
    for(int i=0;i<m;i++){
        sum = seqB[i];
        subB.push_back(sum);
        for(int k=i+1;k<m;k++){
            sum += seqB[k];
            subB.push_back(sum);
        }
    }

    // Sort subA asc, subB desc
    sort(subA.begin(),subA.end(), less<long long int>());
    sort(subB.begin(),subB.end(), greater<long long int>());
    
    // Two pointer sliding
    int ptA = 0;
    int ptB = 0;
    long long int result = 0;

    while(ptA < subA.size() && ptB < subB.size()){
        long long int currentA = subA[ptA];
        long long int target = T - currentA;

        if(subB[ptB] > target){ // subA pointer increase
            ptB++;
        }
        else if(subB[ptB]== target){ // FoundAnswer
            long long int cntA = 0;
            long long int cntB = 0;
            // Find same numbers
            while(subA[ptA] == currentA && ptA < subA.size()){
                ptA++;
                cntA++;
            }
            while(subB[ptB] == target && ptB < subB.size()){
                ptB++;
                cntB++;
            }
            result += cntA * cntB;
        }
        else{ // subB pointer increase
            ptA++;
        }
    }
    cout << result;


}
