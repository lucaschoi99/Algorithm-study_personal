#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> str;
bool checkAlpha[26] = {false, };
int answer = 0;

int countRead(){
    int cnt= 0;
    
    for(int i=0;i<str.size();i++){
        int count = 0;
        string newString = str[i];
        for(int k=0;k<newString.size();k++){
            char idx = newString[k] - 'a';
            if(checkAlpha[idx]){count++;}
        }
        if(count == newString.size()){cnt++;}
    }
    return cnt;
}

void simulation(int idx, int start, int end){
    if(start == end){
        answer = max(answer, countRead());
        return;
    }

    for(int i=idx;i<26;i++){
        if(checkAlpha[i]){ continue;}
        checkAlpha[i] = true;
        simulation(i,start+1,end);
        checkAlpha[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    // a,n,t,i,c
    if(k < 5){ cout << 0; return 0;}
    checkAlpha['a' - 'a'] = true;
    checkAlpha['n' - 'a'] = true;
    checkAlpha['t' - 'a'] = true;
    checkAlpha['i' - 'a'] = true;
    checkAlpha['c' - 'a'] = true;

    for(int i=0;i<n;i++){
        string word;
        cin >> word;
        int len = word.size() - 8;
        word = word.substr(4,len);

        // 추가 단어 종류
        string newString = "";
        for(int m=0;m<word.size();m++){
            if(!checkAlpha[word[m]-'a']){
                newString += word[m];
            }
        }
        str.push_back(newString);
    }

    // 백트랙킹 완전탐색
    int num = k-5;
    simulation(0,0,num);

    cout << answer << "\n";

}
