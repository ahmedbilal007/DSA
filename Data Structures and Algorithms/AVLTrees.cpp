#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int height(Node* root){
    if (root == NULL){
        return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
        return 1 + left_height;
    else
        return 1 + right_height;
}

int balancing_factor(Node* root){
    if (root == NULL){
        return 0;
    }
    return (height(root->left) - height(root->right));
}

Node* rightRotate(Node* root){
    Node* new_root = root->left;
    Node* temp = new_root->right;
    new_root->right = root;
    root->left = temp;
    return new_root;
}

Node* leftRotate(Node* root){
    Node* new_root = root->right;
    Node* temp = new_root->left;
    new_root->left = root;
    root->right = temp;
    return new_root;
}

Node* insert(Node* root, int val){
    if (root == NULL){
        root = new Node(val);
        return root;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else{
        cout << "Duplicate Values not allowed.\n";
        return NULL;
    }

    int balance_factor = balancing_factor(root);
    if (balance_factor > 1 && val < root->left->data)
        return rightRotate(root);
    else if (balance_factor < -1 && val > root->right->data)
        return leftRotate(root);
    else if (balance_factor > 1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if (balance_factor < -1 && val < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* buildTree(vector<int> values){
    Node* root = nullptr;
    for (int val : values)
        root = insert(root, val);
    return root;
}

void levelOrderTraversal(Node* root){
    if (root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        Node* cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
    cout << endl;
}

Node* inOrderSuccessor(Node* root){
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int val){
    if (root == NULL){
        return NULL;
    }
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else{
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if  (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* successor = inOrderSuccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root, successor->data);
    }

    int balance_factor = balancing_factor(root);
    if (balance_factor == 2 && balancing_factor(root->left) >= 0)
        return rightRotate(root);
    else if (balance_factor == 2 && balancing_factor(root->left) == -1){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if (balance_factor == -2 && balancing_factor(root->right) <= 0)
        return leftRotate(root);
    else if (balance_factor == -2 && balancing_factor(root->right) == 1){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
int main(){

    vector<int> values = {30, 10, 20, 40, 50, 25, 5};
    Node* root = buildTree(values);
    levelOrderTraversal(root);
    root = deleteNode(root, 50);
    levelOrderTraversal(root);
    return 0;
}