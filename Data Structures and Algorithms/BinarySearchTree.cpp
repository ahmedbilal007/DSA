#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node* insertNode(Node* root, int val){
    if (root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = val;
        return newNode;
    }
    if (root->data > val){
        root->left = insertNode(root->left, val);
    } else if(root->data < val){
        root->right = insertNode(root->right, val);
    }
    return root;
}

Node* buildTree(vector<int> values){
    Node* root = NULL;
    for (int val : values)
        root = insertNode(root, val);

    return root;
}

void inOrderTraversal(Node* root){
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool searchNode(Node* root, int key){
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (root->data > key)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

Node* inOrderSuccessor(Node* root){
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* successor = inOrderSuccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}
int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildTree(arr);
    inOrderTraversal(root);
    cout << searchNode(root, 5) << endl;
    cout << searchNode(root, 0) << endl;
    deleteNode(root, 5);
    inOrderTraversal(root);
    return 0;
}
