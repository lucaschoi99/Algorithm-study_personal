#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

string rev(string str){
    reverse(str.begin(), str.end());
    return str;
}

bool AKA(string newString){
    if(newString != rev(newString)){
        return false;
    }

    if(newString.size() == 1) {return true;}

    int size = newString.size() / 2;

    string first = newString.substr(0, size);
    string second = newString.substr(newString.size()-size);

    if(AKA(first) && AKA(second)) {return true;}
    else{ return false;}
}



int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    string newString;
    cin >> newString;

    if(AKA(newString)){ cout << "AKARAKA";}
    else{ cout << "IPSELENTI";}
    
    
}
