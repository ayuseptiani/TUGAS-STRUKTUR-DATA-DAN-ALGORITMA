#include <iostream>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int key;
    
    Node() {
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;
    
    BST() {
        root = NULL;
    }
    
    Node *insertRecursive(int inputKey, Node *currentRoot) {
        if (currentRoot == NULL) {
            Node *newNode = new Node();
            newNode->key = inputKey;
            return newNode;
        }
        
        if (inputKey < currentRoot->key) {
            currentRoot->left = insertRecursive(inputKey, currentRoot->left);
        } else if (inputKey > currentRoot->key) {
            currentRoot->right = insertRecursive(inputKey, currentRoot->right);
        }
        
        return currentRoot;
    }
    
    void insert(int inputKey) {
        root = insertRecursive(inputKey, root);
    }
    
    void preOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            cout << currentNode->key << " ";
            preOrderTraversal(currentNode->left);
            preOrderTraversal(currentNode->right);
        }
    }
    
    void preOrder() {
        cout << "Pre Order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }
    
    
    void postOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            postOrderTraversal(currentNode->left);
            postOrderTraversal(currentNode->right);
            cout << currentNode->key << " ";
        }
    }
    
    void postOrder() {
        cout << "Post Order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }
    
    void inOrderTraversal(Node *currentNode) {
        if (currentNode != NULL) {
            inOrderTraversal(currentNode->left);
            cout << currentNode->key << " ";
            inOrderTraversal(currentNode->right);
        }
    }
    
    void inOrder() {
        cout << "In Order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
    
    int findMaxRecursive(Node *currentNode) {
        if (currentNode == NULL)
            return -1; 
        else if (currentNode->right == NULL)
            return currentNode->key; 
        else
            return findMaxRecursive(currentNode->right); 
    }
    
    int findMax() {
        return findMaxRecursive(root);
    }
    
    int findMinRecursive(Node *currentNode) {
        if (currentNode == NULL)
            return -1; 
        else if (currentNode->left == NULL)
            return currentNode->key; 
        else
            return findMinRecursive(currentNode->left); 
    }

    int findMin() {
        return findMinRecursive(root);
    }
    
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }
    
    Node* searchRecursive(Node* currentNode, int key) {
        if (currentNode == NULL || currentNode->key == key)
            return currentNode;
        if (currentNode->key > key)
            return searchRecursive(currentNode->left, key);
        	return searchRecursive(currentNode->right, key);
    }

    bool search(int key) {
        Node* result = searchRecursive(root, key);
        return result != NULL;
    }
};


int main() {
    BST *bin1 = new BST();
    
    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(8);
    bin1->insert(5);
    bin1->insert(3);
    
    bin1->preOrder();
    bin1->inOrder();
    bin1->postOrder();
    
    cout << "Maximum value : " << bin1->findMax() << endl;
    cout << "Minimum value : " << bin1->findMin() << endl;
    
    int searchKey = 5;
    if (bin1->search(searchKey))
        cout << "Key " << searchKey << " found in the BST." << endl;
    else
        cout << "Key " << searchKey << " not found in the BST." << endl;
        
    bin1->deleteKey(5);
    
    return 0;
}
