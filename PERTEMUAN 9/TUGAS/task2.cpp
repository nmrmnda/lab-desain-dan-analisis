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
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void preOrder() {
        preOrderRec(root);
        cout << endl;
    }

    void inOrder() {
        inOrderRec(root);
        cout << endl;
    }

    void postOrder() {
        postOrderRec(root);
        cout << endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void preOrderRec(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        preOrderRec(node->left);
        preOrderRec(node->right);
    }

    void inOrderRec(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrderRec(node->left);
        cout << node->data << " ";
        inOrderRec(node->right);
    }

    void postOrderRec(Node* node) {
        if (node == NULL) {
            return;
        }

        postOrderRec(node->left);
        postOrderRec(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "Masukkan jumlah elemen yang akan diinput : ";
    cin >> n;

    cout << "Masukkan elemen-elemen : ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Pre-order traversal : ";
    tree.preOrder();

    cout << "In-order traversal : ";
    tree.inOrder();

    cout << "Post-order traversal : ";
    tree.postOrder();

    return 0;
}
