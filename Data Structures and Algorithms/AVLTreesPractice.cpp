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

int height(Node* node){
    if (node == NULL){
        return -1;
    }

    int left_height = height(node->left);
    int right_height = height(node->right);

    if (left_height > right_height)
        return 1 + left_height;
    else   
        return 1 + right_height;
}

int balancing_factor(Node* node){
    if (node == NULL){
        return -1;
    }
    return (height(node->left) - height(node->right));
}

Node* rotateRight(Node* node){
    Node* new_root = node->left;
    Node* temp = new_root->right;
    new_root->right = node;
    node->left = temp;
    return new_root;
}

Node* rotateLeft(Node* node){
    Node* new_root = node->right;
    Node* temp = new_root->left;
    new_root->left = node;
    node->right = temp;
    return new_root;
}

Node* insert(Node* root, int val){
    if (root == NULL){
        root = new Node(val);
        return root;
    }
    if (root->data > val){
        root->left = insert(root->left, val);
    } else if (root->data < val){
        root->right = insert(root->right, val);
    } else {
        cout << "Duplicate Values not allowed.\n";
        return NULL;
    }

    int b_factor = balancing_factor(root);
    if (b_factor > 1 && val < root->left->data){
        return rotateRight(root);
    } else if (b_factor > 1 && val > root->left->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    } else if (b_factor < -1 && val > root->right->data){
        return rotateLeft(root);
    } else if (b_factor < -1 && val < root->right->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

Node* inOrderSuccessor(Node* root){
    while (root->left != NULL)
        root = root->left;

    return root;
}
Node* deleteNode(Node* root, int val){
    if (root == NULL){
        return nullptr;
    }
    if (root->data > val){
        root->left = deleteNode(root->left, val);
    } else if (root->data < val){
        root->right = deleteNode(root->right, val);
    } else {
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
        root->right = deleteNode(root, successor->data);

        int balance_factor = balancing_factor(root);
        if (balance_factor == 2 && balancing_factor(root->left) >= 0)
            return rotateRight(root);
        else if (balance_factor == 2 && balancing_factor(root->left) == -1){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        } else if (balance_factor == -2 && balancing_factor(root->right) <= 0)
            return rotateLeft(root);
        else if (balance_factor == -2 && balancing_factor(root->right) == 1){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}
Node* buildTree(vector<int> values){
    Node* root = NULL;
    for (int val : values)
        root = insert(root, val);
    return root;
}
void print(Node* root){
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
int main(){
    vector<int> values = {30, 10, 20, 40, 50, 25, 5};
    Node* avl_tree = buildTree(values);
    print(avl_tree);
    avl_tree = deleteNode(avl_tree, 50);
    print(avl_tree);

    return 0;
}