#include<iostream>
using namespace std;

//node
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root; //root node

Node* insert(Node* root, int data) { //bst insert

    if (root == nullptr)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;

}

void postorder(Node* node) {
    if (node) { //if node pointer not null
        postorder(node->left);
        postorder(node->right);
        cout << node->data << '\n';
    }
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    root = nullptr;

    int n;
    while(cin >> n){ //get value until done
        if (n <= 0) { break; }
        root = insert(root, n);

    } 
    
    postorder(root);


    return 0;
}
