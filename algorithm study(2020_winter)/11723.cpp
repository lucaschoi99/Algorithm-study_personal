#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//initialize array
const int MAX= 20 +1;
bool visited[MAX];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int M; //testcases
	cin >> M;

    for(int i=0;i<M;i++){
        string func;
        int x;

        //cin including whitespace
        cin >> func;

        if(func == "add"){
            cin >> x;
            visited[x] = true;
        }
                
        else if(func == "remove"){
            cin >> x;
            visited[x] = false;
            
        }
        else if(func == "check"){
            cin >> x;
            if(visited[x]){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(func == "toggle"){
            cin >> x;
            if(!visited[x]){
                //doesn't exist, then insert
                visited[x] =1;
            }
            else{
                //exist, then remove
                visited[x] =0;
            }
        }
        
        else if(func == "all"){
            memset(visited, true, sizeof(visited));
        }
        else { //empty
            memset(visited, false, sizeof(visited));
        }
    }

	return 0;
}