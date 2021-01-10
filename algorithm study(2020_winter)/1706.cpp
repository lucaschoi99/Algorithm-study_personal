#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 1000;
vector<char> v[MAX];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, r;
    cin >> r >> c;

    vector<string> words_list;

    //vector space
    for (int i = 0; i < r; i++) {
        string text;
        cin >> text;
        for (int k = 0; k < c; k++) {
            v[i].push_back(text[k]);
        }

    }

    string word = "";

    //search by rows
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            if (v[i][k] != '#') {
                //collect word until banned space appears
                word += v[i][k];
            }
            else if (v[i][k] == '#') {
                //banned space appears, save word to words_list
                //initialize word
                if (word.length() <= 1) {
                    word = "";
                    continue;
                }
                words_list.push_back(word);

                word = "";
            }

        }
        if (word.length() > 1) {
            //save word and initialize
            words_list.push_back(word);
        }
        word = "";
    }

    //search by columns
    for (int i = 0; i < c; i++) {
        for (int k = 0; k < r; k++) {
            if (v[k][i] != '#') {
                //collect word until banned space appears
                word += v[k][i];
            }
            else if (v[k][i] == '#') {
                //banned space appears, save word to words_list
                //initialize word
                if (word.length() <= 1) {
                    word = "";
                    continue;
                }
                words_list.push_back(word);
                word = "";
            }
        }
        if (word.length() > 1) {
            //save word and initialize
            words_list.push_back(word);
        }
        word = "";
    }
    
    sort(words_list.begin(), words_list.end());
    cout << *words_list.begin() << "\n";
    return 0;
}
