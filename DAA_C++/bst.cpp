#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    bool search(int key) {
        return searchRec(root, key);
    }

    void inOrder() {
        inOrderRec(root);
    }

private:
    Node* insertRec(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else if (key > node->key) {
            node->right = insertRec(node->right, key);
        }

        return node;
    }

    bool searchRec(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == key) {
            return true;
        }

        if (key > node->key) {
            return searchRec(node->right, key);
        }

        return searchRec(node->left, key);
    }

    void inOrderRec(Node* node) {
        if (node != nullptr) {
            inOrderRec(node->left);
            std::cout << node->key << " ";
            inOrderRec(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order traversal: ";
    bst.inOrder(); 
    std::cout << std::endl;

    int key = 40;
    if (bst.search(key)) {
        std::cout << "Key " << key << " found in the BST." << std::endl;
    } else {
        std::cout << "Key " << key << " not found in the BST." << std::endl;
    }

    return 0;
}