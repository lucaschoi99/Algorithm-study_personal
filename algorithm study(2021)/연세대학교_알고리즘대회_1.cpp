#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    string newString;
    getline(cin,newString);

    if(newString.find("d2") != string::npos){
        cout << "D2\n";
        return 0;
    }
    if(newString.find("D2") != string::npos){
        cout << "D2\n";
        return 0;
    }
    
    cout << "unrated\n";
    
	
}
