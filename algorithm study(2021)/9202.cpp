#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

char map[4][4];
bool visited[4][4];
string answer;
vector<char> foundWord;
int sum;
int count;

int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};
int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};


struct Node{
    Node* children[26]; // Alphabet
    bool isEnd;
    bool isHit;

    Node(){
        isEnd = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }

    void clearHit(){
        isHit = false;
        for(int i=0;i<26;i++){
            if(children[i] != NULL){
                children[i]->clearHit();
            }
        }
    }

    bool hasChild(char c){
        return children[c - 'A'] != NULL;
    }

    Node* getChild(char c){
        return children[c-'A'];
    }
};

bool cmp(string args0, string args1) {
    if (args1.size() == args0.size()) {
        int n = args0.compare(args1);
        if (n > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return args0.size() < args1.size();
    }
}

void dfs(int row, int col, int length, Node* current){
    visited[row][col] = true;
    foundWord.push_back(map[row][col]);

    if(current->isEnd && (!current->isHit)){
        current->isHit = true;
        count++; // Found word #
        sum += score[length]; // Score
        string ansWord = "";
        for (int i = 0; i < foundWord.size(); i++) {
            ansWord += foundWord[i];
        }
        // Longer word
        if(cmp(answer, ansWord) > 0){
            answer = ansWord;
        }
    }

    for(int i=0;i<8;i++){ // 8-direction check
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        // Boundary check
        if(newRow >= 0 && newRow <4 && newCol >=0 && newCol <4){
            if(visited[newRow][newCol] == false && current->hasChild(map[newRow][newCol])){
                visited[newRow][newCol] = true;
                dfs(newRow, newCol, length+1, current->getChild(map[newRow][newCol]));
            }
        }
    }

    visited[row][col] = false;
    foundWord.erase(foundWord.begin() + length - 1);
}

void insert(string word , Node* root){
    Node* current = root;
    for(int i=0;i<word.length();i++){
        int index = word[i] - 'A';
        if(current->hasChild(word[i]) == false){ // Insert node
            current->children[index] = new Node();
        }
        current = current->getChild(word[i]); // Move pointer
    }
    current->isEnd = true; // Check end of the word
}
/*
bool containsNode(string word){
    Node current = root;
    for(int i=0;i<word.length();i++){
        int index = word[i] - 'A';
        if(current.children[index] == NULL){ // Not here
            return false;
        }
        current = current.children[index]; // Move pointer
    }
    return true;
}
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int w;
    cin >> w;

    Node* root = new Node();

    for(int i=0;i<w;i++){
        string word;
        cin >> word;
        insert(word , root); // Make trie
    }

    root->clearHit();

    int b;
    cin >> b;
    for(int i=0;i<b;i++){
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        answer = "";
        sum = 0;
        count = 0;

        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                char alp;
                cin >> alp;
                map[j][k] = alp; // Make map
            }
        }

        // Traverse map
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(root->hasChild(map[j][k])){
                    dfs(j,k,1,root->getChild(map[j][k]));
                }
            }
        }
        
        root->clearHit();
        cout << sum << " " << answer << " "<< count << "\n";
    }
}