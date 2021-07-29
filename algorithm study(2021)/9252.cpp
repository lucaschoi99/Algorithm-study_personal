#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

#define NUM 1001

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    string first;
    string second;

    cin >> first;
    cin >> second;

    vector<vector<int>> dp(NUM,vector<int>(NUM,0));

    int ans=0;
    for(int i=1;i<=first.length();i++){
        for(int j=1;j<=second.length();j++){
            if(first[i-1] == second[j-1]){ // Matching char
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else{ // Not-matching : Check max((←), (↑))
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }
    // Find answer string
    int fLength = first.length();
    int sLength = second.length();
    vector<char> answer;
    while(fLength>0 && sLength >0){
            if(first[fLength-1] == second[sLength-1]){
                answer.insert(answer.begin(),first[fLength-1]);
                fLength--;
                sLength--;
            }
            else if(dp[fLength][sLength] == dp[fLength-1][sLength]){
                // Compare (←)
                fLength--;
            }
            else if(dp[fLength][sLength] == dp[fLength][sLength-1]){
                // Compare (↑)
                sLength--;
            }
    }

    cout << ans << "\n";
    if(ans != 0){
        for(char vi: answer){
            cout << vi;
        }
    }
    
    
}
