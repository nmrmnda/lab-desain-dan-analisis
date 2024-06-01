#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void preOrderTraversal(Node* node) {
        if (node == NULL) return;
        cout<< node->data<<" ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void inOrderTraversal(Node* node) {
        if (node == NULL) return;
        inOrderTraversal(node->left);
        cout<< node->data<<" ";
        inOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (node == NULL) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<< node->data<<" ";
    }
};

int main() {
    BinaryTree tree;
    
    int array[] = {18, 30, 33, 29, 32};
    tree.root = new Node(array[0]);
    tree.root->left = new Node(array[1]);
    tree.root->right = new Node(array[2]);
    tree.root->left->left = new Node(array[3]);
    tree.root->left->right = new Node(array[4]);
    
    cout<<"Pre-order traversal : ";
    tree.preOrderTraversal(tree.root);
    cout<<endl;

    cout<<"In-order traversal : ";
    tree.inOrderTraversal(tree.root);
    cout<<endl;

    cout<<"Post-order traversal : ";
    tree.postOrderTraversal(tree.root);
    cout<<endl;

    return 0;
}
