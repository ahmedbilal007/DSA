#include <iostream>
#include <queue>
using namespace std;
int idx = -1;
struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node* buildTree(int sequence[]){
    idx++;
    if (sequence[idx] == -1)
        return NULL;
    Node* root = new Node();
    root->data = sequence[idx];
    root->left = buildTree(sequence);
    root->right= buildTree(sequence);
    return root;
}

void preOrderTraversal(Node* root){
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inOrderTraversal(Node* root){
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size()>0){
        Node* cur = q.front();
        q.pop();
        if (cur == NULL){
            if (!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        cout << cur->data << " ";
        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);

    }
}

int main(){
    int preOrder[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "In Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Level Order Traversal: \n";
    levelOrderTraversal(root);
    cout << endl;


    return 0;
}
