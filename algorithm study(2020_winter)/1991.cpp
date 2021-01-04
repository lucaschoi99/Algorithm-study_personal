#include<iostream>
using namespace std;

typedef struct node* nodepointer;
typedef struct node{
    char data;
    nodepointer left, right;
}node;

//preorder traversal
void preorder(nodepointer pointer) {
    if (pointer) { //if not null
        cout << pointer->data;
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

//inorder traversal
void inorder(nodepointer pointer) {
    if (pointer) { //if not null
        inorder(pointer->left);
        cout << pointer->data;
        inorder(pointer->right);
    }
}

//postorder traversal
void postorder(nodepointer pointer) {
    if (pointer) { //if not null
        postorder(pointer->left);
        postorder(pointer->right);
        cout << pointer->data;
    }
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
       
    node nodes[26];

    //initialize
    int ascii = 65; //starts with value 'A'
    for (int k = 0; k < n; k++) {
        nodes[k].data = ascii;
        nodes[k].left = NULL;
        nodes[k].right = NULL;
        ascii++;
    }

    //construct tree
    for (int k = 0; k < n; k++) {
        char alpha;
        char lt;
        char rt;
        cin >> alpha >> lt >> rt;
        if (lt != '.') {
            nodes[int(alpha) - 65].left = &nodes[int(lt) - 65];
        }
        if (rt != '.') {
            nodes[int(alpha) - 65].right = &nodes[int(rt) - 65];
        }
    }

    //print traversal
    //preorder, inorder, postorder
    preorder(&nodes[0]);
    cout << '\n';
    inorder(&nodes[0]);
    cout << '\n';
    postorder(&nodes[0]);
    cout << '\n';

    return 0;
}
