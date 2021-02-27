#include <iostream>
#include <math.h>
using namespace std;

int n,r,c;
int loc=0;

void traversal(int num, int row, int col){
    if(num == 1){ // graph size 2*2
        return;
    }
    else{ //graph size larger than 2*2
        if((row / int(pow(2,num-1)))  % 2 == 0){
            if((col / int(pow(2,num-1)))  % 2 == 0){loc = loc + pow(2,2*num-2) * 0;}
            else{loc = loc + pow(2,2*num-2) * 1;}
        }
        else{
            if((col / int(pow(2,num-1))) % 2 == 0){loc = loc + pow(2,2*num-2) * 2;}
            else{loc = loc + pow(2,2*num-2) * 3;}
        }

        // update row & col
        if(row < int(pow(2,num-1))){}
        else{row = (row % int(pow(2,num-1)));}

        if(col < int(pow(2,num-1))){}
        else{col = (col % int(pow(2,num-1)));}

        traversal(num-1,row,col);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c;

    if(r % 2 == 0){
        if(c % 2 == 0){loc += 0;}
        else{loc += 1;}
    }
    else{
        if(c %2 == 0){loc += 2;}
        else{loc +=3;}
    }

    traversal(n,r,c);

    cout << loc;
    
}
