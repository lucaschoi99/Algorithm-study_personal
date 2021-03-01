#include<iostream>
#include<set>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    cin >> n;

    while(n--){
        int m;
        // create set
        multiset<int> st;

        cin >> m;

        while(m--){
            char op;
            int num;
            cin >> op >> num;
            if(op == 'I'){ // if insert
                st.insert(num);
            }
            else{ // else delete
                if(st.empty()){continue;}
                if(num == 1){ // delete maximum
                    auto iter = st.end();
                    iter--;
                    st.erase(iter);
                }
                else{ // delete minimum
                    auto iter = st.begin();
                    st.erase(iter);
                }
            }
        }
        if(st.empty()){cout << "EMPTY" << "\n";}
        else{
            auto end = st.end();
            end--;
            cout << *end << " " << *st.begin() << "\n";
        }
    }
}