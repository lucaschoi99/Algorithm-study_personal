#include<iostream>
#include<queue>
#include<tuple>
using namespace std;


int fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int T;
    cin >> T; //testcases

    tuple<int,int,int> t;
    queue<tuple<int,int,int>> q;

    while(T--){
        int n,a,b,c; //n = 1*a + 2*b + 3*c
        cin >> n;
        
        int temp =n;
        for(c=0;c<4;c++){ //# of three
            for(b=0;b< (temp - 3*c)/2 + 1;b++){ //# of two
                for(a=0;a<(temp - 3*c - 2*b)+1;a++){ //# of one
                    if(n == 1*a + 2*b + 3*c){
                        //if n = 1*a + 2*b + 3*c
                        //make pair tuple and insert into queue
                        q.push(make_tuple(a,b,c));
                    }
                }
            }
        }

        int ans=0;
        while(!q.empty()){
            //for each value a,b,c
            a= get<0>(q.front());
            b= get<1>(q.front());
            c= get<2>(q.front());

            ans += fact(a+b+c) / (fact(a) * fact(b) *fact(c));

            q.pop(); //next element
        }

        cout << ans << "\n";
    }


	return 0;
}