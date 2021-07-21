#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> heap;

void insertHeap(int inserted){
    
    heap.push_back(inserted);
    int index = heap.size() - 1;

    // Compare with parent node
    // Bottom-up
    while(true){
        if(heap[index / 2] > inserted && index > 1){ // Smaller than parent, swap
            int temp = inserted;
            heap[index] = heap[index / 2];
            heap[index/2] = temp;
            index /= 2;
        }
        else{ // Condition satisfied
            break;
        }
    }
}

int deleteHeap(){
    if(heap.size() == 1){ // Empty
        return 0;
    }
    // Delete root (min)
    // Last element index
    int index = heap.size() - 1;
    int min = heap[1];

    // Swap root and last node
    heap[1] = heap[index];
    heap.pop_back();

    // Check min heap condition
    // Top-down
    int idx = 1;
    while(true){
        int leftchild = 2*idx;
        int rightchild = 2*idx+1;

        if(leftchild > heap.size()-1){
            break;
        }
        int minValue = heap[leftchild];
        int minPos = leftchild;
        
        if(rightchild <= heap.size()-1 && minValue > heap[rightchild]){ // Case: Swap with right child
            minValue = heap[rightchild];
            minPos = rightchild;
        }

        // Condition for swap
        if(heap[idx] > minValue){
            int temp = heap[idx];
            heap[idx] = heap[minPos];
            heap[minPos] = temp;
            idx = minPos;
        }
        else{
            break;
        }
    }

    return min;
    
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int N;
    cin >> N;

    // Fill index 0
    heap.push_back(0);

    for(int i=0;i<N;i++){
        int cmd;
        cin >> cmd;

        if(cmd == 0){
            int result;
            result = deleteHeap();
            cout << result << "\n";
        }
        else{
            insertHeap(cmd);
        }
    }


}
