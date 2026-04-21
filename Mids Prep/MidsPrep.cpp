#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class SinglyLinkedList{
public:
    Node* head;
    Node* tail;

    SinglyLinkedList(){
        head = tail = NULL;
    }
     
    void pushFront(int val){
        Node* node = new Node(val);
        if (head == NULL){
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void pushBack(int val){
        Node* node = new Node(val);
        if (head == NULL){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void popFront(){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        } 
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void popBack(){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){
        if (pos < 0){
            cout << "Invalid Position.\n";
            return;
        }
        if (pos == 0){
            pushFront(val);
            return;
        }
        Node* temp = head;
        for (int i=0; i<pos-1; i++)
            temp = temp->next;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        }
        if (head->data == val){
            popFront();
            return;
        }
        Node* temp = head;
        Node* temp2 = NULL;
        while (temp != NULL && temp->data != val){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void print(){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseList(){
        if (head == NULL || head->next == NULL){
            return head;
        }
        Node* cur = head;
        Node* prev = NULL;
        while (cur != NULL){
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }

    Node* recursiveRevervse(Node* cur, Node* prev){
        if (cur == NULL){
            head = prev;
            return head;
        }
        Node* next = cur->next;
        cur->next = prev;
        return recursiveRevervse(next, cur);
    }

    Node* swapNodes(){
        if (head == NULL || head->next == NULL){
            return head;
        }
        Node* first = head;
        Node* sec = first->next;
        Node* prev = NULL;
        while (first != NULL && sec != NULL){
            Node* third = sec->next;
            sec->next = first;
            first->next = third;
            if (prev != NULL){
                prev->next = sec;
            } else {
                head = sec;
            }
            prev = first;
            first = third;
            if (third != NULL){
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
    }

    int findMid(){
        if (head==NULL){
            cout << "Linked List is empty.\n";
            return -999;
        }
        if (head->next == NULL){
            return head->data;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;  
    }

    bool search(int key){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return false;
        }
        Node* temp = head;
        while (temp != NULL){
            if (temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool detectCycle(){
        if (head == NULL || head->next == NULL){
            return false;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL || fast->next != NULL){
            if (fast == slow){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

    void deleteAlternative(){
        if (head == NULL) return;
        Node* first = head;
        Node* sec = head->next;
        while (first != NULL && first->next != NULL){
            first->next = sec->next;
            sec->next = NULL;
            delete sec;
            first = first->next;
            if (first!=NULL)
                sec = first->next;
            else
                sec = NULL;
        }
    }
};

Node* mergeSorted(Node* h1, Node* h2, SinglyLinkedList& result){
    if (h1 == NULL){
        result.pushBack(h2->data);
        return h2;
    }
    if (h2 == NULL){
        result.pushBack(h1->data);
        return h1;
    }
    if (h1->data <= h2->data){
        h1->next = mergeSorted(h1->next, h2, result);
        result.pushFront(h1->data);
        return h1;
    } else {
        h2->next = mergeSorted(h1, h2->next, result);
        result.pushFront(h2->data);
        return h2;
    }
}

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print(){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteFromHead(){
        if (head == NULL){
            cout << "Linked List is empty. Can't delete node.\n";
            return;
        } else if (head == tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteFromTail(){
        if (head == NULL){
            cout << "Linked List is empty. Can't delete node.\n";
            return;
        } else if (head == tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
    }

    void insert(int val, int pos){
        if (pos < 0){
            cout << "Invalid Position. Can't Add Element.\n";
            return;
        } 
        if (pos == 0){
            insertAtHead(val);
            return;
        } 
        Node* temp = head;
        for (int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = temp;
    }

    void reverse_print(){
        if (head == NULL){
            cout << "Linked List is empty.\n";
            return;
        }
        Node* temp = tail;
        while (temp != NULL){
            cout << temp->data <<"->";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    void deleteNode(int key){
        if (head == NULL){
            cout << "Linked list is empty.\n";
            return;
        }
        Node* temp = head;
        Node* temp2 = NULL;
        while (temp != NULL && temp->data != key){
            temp2 = temp;
            temp = temp->next;
        }
        if (temp == NULL){
            cout << "Value not found in the list.\n";
            return;
        }
        if (temp2 == NULL){
            head = temp->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }
        temp2->next = temp->next;
        if (temp->next != NULL){
            temp->next->prev = temp2;
        }
        delete temp;
    }

    void reverse(){
        if (head == NULL || head->next == NULL)
            return;
        Node* cur = head;
        Node* prev = NULL;
        while (cur != NULL){
            Node* next = cur->next;
            cur->next = prev;
            cur->prev = next;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void swapNodes(){
        if (head == NULL || head->next == NULL){
            cout << "Linked List is empty or only single node exists in the linked list.\n";
            return;
        }
        Node* first = head;
        Node* sec = first->next;
        Node* prev = NULL;
        while (first != NULL && sec != NULL)
        {
            Node* third = sec->next;
            sec->next = first;
            first->prev = sec;
            first->next = third;
            if (prev != NULL)
                prev->next = sec;
            else
                head = sec;
            
            prev = first;
            first = third;
            if (third != NULL)
                sec = third->next;
            else
                sec = NULL;
        }
    }
};

class StackUsingArray{
private: 
    int top = -1;
    char* q;
    int size;

public:
    StackUsingArray(int s){
        size = s;
        q = new char[size];
    }

    void push(char ch){
        if (top == size-1){
            cout << "Stack is full. Overflow Condition.\n";
            return;
        }
        q[++top] = ch;
    }

    char pop(){
        if (top == -1){
            cout << "Stack is empty. Underflow condition.\n";
            return ' ';
        }
        return q[top--];
    }

    char peek(){
        if (top == -1){
            cout << "Stack is empty.\n";
            return ' ';
        }
        return q[top];
    }

    bool isFull(){
        return top == size-1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        if (top == -1){
            cout << "Stack is empty.\n";
            return;
        }
        while (top != -1){
            cout << q[top] << " ";
            pop();
        }
    }
};

class StackNode{ 
public:
    char data;
    StackNode* next;

    StackNode(char val){
        data = val;
        next = NULL;
    }
};

class Stack{
private:
    StackNode* top;
public:
    Stack(){
        top = NULL;
    }

    void insert(char ch){
        StackNode* newNode = new StackNode(ch);
        if (top == NULL){
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    void deletee(){
        if (top == NULL){
            cout << "Stack is empty.\n";
            return;
        }
        StackNode* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    void display(){
        if (top == NULL){
            cout << "Stack is empty.\n";
            return;
        }
        StackNode* temp = top;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    char peek(){
        if (top == NULL){
            cout << "Stack is empty.\n";
            return ' ';
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};

// Expressions

bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precendence(char ch){
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

string infixToPostFix(string infix){
    Stack s;
    string postFix = "";
    int i = 0;
    int len = static_cast<int>(infix.length());
    while (i < len){
        if (isspace(infix[i])){
            i++;
            continue;
        }
        if (isalnum(infix[i])){
            string num = "";
            while (i < len && isalnum(infix[i])){
                num += infix[i++];
            }
            postFix += num;
            postFix += " ";
            continue;
        }
        if (infix[i] == '('){
            s.insert('(');
        } else if (infix[i] == ')'){
            while (s.peek() != '('){
                postFix += s.peek();
                postFix += " ";
                s.deletee();
            }
            s.deletee();
        } else if (isOperator(infix[i])){
            while (!s.isEmpty() && precendence(s.peek()) >= precendence(infix[i])){
                postFix += s.peek();
                postFix += " ";
                s.deletee();
            }
            s.insert(infix[i]);
        }
        i++;
    }
    while (!s.isEmpty()){
        postFix += s.peek();
        postFix += " ";
        s.deletee();
    }
    return postFix;
}

int postFixEvaluation(string postFix){
    stack<int> s;
    int i = 0;
    int len = static_cast<int>(postFix.length());
    while (i < len){
        if (isspace(postFix[i])){
            i++;
            continue;
        } 
        if (isdigit(postFix[i])){
            int num = 0;
            while (i < len && isdigit(postFix[i])){
                num = num * 10 + (postFix[i++] - '0');
            }
            s.push(num);
        } else if (isOperator(postFix[i])){
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            if (postFix[i] == '+'){
                s.push(op1 + op2);
            } else if (postFix[i] == '-'){
                s.push(op1 - op2);
            } else if (postFix[i] == '*'){
                s.push(op1 * op2);
            } else if (postFix[i] == '/'){
                s.push(op1 / op2);
            } else if (postFix[i] == '^'){
                int res = pow(op1, op2);
                s.push(res);
            }
        }
        i++;
    }
    return s.top();
}

class QueueUsingArray{
private:
    int rear;
    int front;
    int* q;
    int size;
public:
    QueueUsingArray(int s){
        size = s;
        rear = front = -1;
        q = new int[size];
    }
    void enque(int val){
        if (rear == size-1){
            cout << "Queue is full. Overflow Condition.\n";
            return;
        } else if (front == -1 && rear == -1){
            front = rear = 0;
            q[rear] = val;
        } else {
            q[++rear] = val;
        }
    }

    void deque(){
        if (front == -1 && rear == -1){
            cout << "Queue is empty.\n";
            return;
        } else if (front == rear){
            front = rear = -1;
        } else {
            front++;;
        }
    }

    void display(){
        if (front == -1 && rear == -1){
            cout << "Queue is empty.\n";
            return;
        } 
        for (int i=front; i<=rear; i++){
            cout << q[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return rear == size-1;
    }
};

class QueueUsingLL{
private:
    Node* rear;
    Node* front;
public:
    QueueUsingLL(){
        rear = front = NULL;
    }

    void enque(int val){
        Node* newNode = new Node(val);
        if (front == NULL && rear == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deque(){
        if (front == NULL && rear == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    void display(){
        if (front == NULL && rear == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return (front == NULL && rear == NULL);
    }
};
class CircularQUsingArray{
private:
    int rear;
    int front;
    int size;
    int* q;
    int count;

public:
    CircularQUsingArray(int s){
        size = s;
        rear = front = -1;
        q = new int[size];
        count = 0;
    }

    void enque(int val){
        if (front == -1 && rear == -1){
            front = rear = 0;
            q[rear] = val;
        } else if (((rear + 1) % size) == front){
            cout << "Overflow.\n";
            return;
        } else {
            rear = (rear + 1) % size;
            q[rear] = val;
        }
        count++;
    }

    void deque(){
        if (front == -1 && rear == -1){
            cout << "Queue is empty.\n";
            return;
        } else if (front == rear){
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display(){
        int i = front;
        while (i != rear){
            cout << q[i] << " ";
            i = (i+1) % size;
        }
        cout << q[rear] << endl;
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFront(){
        return ((rear + 1) & size) == front; 
    }
};

class CircularQueueUsingLL{
private:
    Node* front;
    Node* rear;
public:
    CircularQueueUsingLL(){
        front = rear = NULL;
    }

    void enque(int val){
        Node* newNode = new Node(val);
        if (front == NULL){
            front = rear = newNode;
            rear->next = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
            newNode->next = front;
        }
    }

    void deque(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        } 
        Node* temp = front;
        front = front->next;
        rear->next = front;
        temp->next = NULL;
        delete temp;
    }

    void display(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front->next;
        cout << front->data << " ";
        while (temp!=front){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return front == NULL;
    }
};

class DoubleEndedQueue{
private:
    Node* front;
    Node* rear;
public:
    DoubleEndedQueue(){
        front = rear = NULL;
    }

    void insertAtFront(int val){
        Node* newNode = new Node(val);
        if (front == NULL){
            front = rear = newNode;
        } else {
            newNode->next = front;
            front = newNode;
        }
    }

    void insertAtRear(int val){
        Node* newNode = new Node(val);
        if (front == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFromFront(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    void deleteFromRear(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        Node* temp2 = NULL;
        while (temp != rear){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        rear = temp2;
        delete temp;
    }

    void display(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return front == NULL;
    }

    int valueAtFront(){
        return front->data;
    }

    int valueAtRear(){
        return rear->data;
    }

};

class PriorityQueueNode{
public: 
    int val;
    int priority;
    PriorityQueueNode* next;


    PriorityQueueNode(int val, int pro){
        this->val = val;
        this->priority = pro;
        next = NULL;
    }
};

class PrioirityQueue{
private:
    PriorityQueueNode* front;

public:
    PrioirityQueue(){
        front = NULL;
    }

    void enque(int val){
        int priority;
        cout << "Enter Node Priority: ";
        cin >> priority;

        PriorityQueueNode* newNode = new PriorityQueueNode(val, priority);
        if (front == NULL || priority > front->priority){
            newNode->next = front;
            front = newNode;
        } else {
            PriorityQueueNode* temp = front;
            while (temp->next != NULL && temp->next->priority > priority)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deque(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        PriorityQueueNode* temp = front;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }

    void display(){
        if (front == NULL){
            cout << "Queue is empty.\n";
            return;
        }
        PriorityQueueNode* temp = front;
        while (temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

int i = -1;

TreeNode* buildTree(int values[]){
    i++;
    if (values[i] == -1){
        return NULL;
    }
    TreeNode* root = new TreeNode(values[i]);
    root->left = buildTree(values);
    root->right = buildTree(values);
    return root;
}

void preOrderTraversal(TreeNode* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root){
    if (root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root){
    if (root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(TreeNode* root){
    // Printing in a Single Line


    // queue<TreeNode*> q;
    // q.push(root);
    // while (q.size() > 0){
    //     TreeNode* cur = q.front();
    //     q.pop();
    //     if (cur != NULL){
    //         cout << cur->data << " ";
    //     }
    //     if (cur->left != NULL)
    //         q.push(cur->left);
    //     if (cur->right != NULL)
    //         q.push(cur->right);
    // }
    // cout << endl;

    // Printing Level Wise
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0){
        TreeNode* cur = q.front();
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

TreeNode* root = NULL;

void iterativeInsert(int val){
    TreeNode* newNode = new TreeNode(val);
    if (root == NULL)
        root = newNode;
    else {
        TreeNode* current = root;
        TreeNode* parent = NULL;
        while (current != NULL){
            parent = current;
            if (current->data > val)
                current = current->left;
            else if (current->data < val)
                current = current->right;
            else {
                cout << "Duplicate value not allowed.n";
                return;
            }
        }
        if (parent->data < val)
            parent->right = newNode;
        else
            parent->left = newNode;
    }
}

TreeNode* createNode(int val){
    TreeNode* newNode = new TreeNode(val);
    return newNode;
}
void rInsert(TreeNode* current, TreeNode* newNode){
    if (current == NULL){
        root = newNode;
        return;
    }
    if (current->data > newNode->data){
        if (current->left == NULL){
            current->left = newNode;
        } else {
            rInsert(current->left, newNode);
        }
    } else if (current->data < newNode->data){
        if (current->right == NULL){
            current->right = newNode;
        } else {
            rInsert(current->right, newNode);
        }
    }
}

TreeNode* recursiveInsert(TreeNode* root, int val){
    if (root == NULL){
        TreeNode* newNode = new TreeNode(val);
        return newNode;
    }
    if (root->data < val){
        root->right = recursiveInsert(root->right, val);
    } else if (root->data > val){
        root->left = recursiveInsert(root->left, val);
    } else {
        cout << "Duplicate values not allowed.\n";
        return NULL;
    }
    return root;
}

TreeNode* buildBST(vector<int> values){
    TreeNode* root = NULL;
    for (int val : values)
        root = recursiveInsert(root, val);
    return root;
}

bool iterativeSearch(int key){
    TreeNode* current = root;
    while (current != NULL && current->data != key){
        if (current->data > key)
            current = current->left;
        else 
            current = current->right;
    }
    if (current == NULL)
        return false;
    else 
        return true;
}

bool recursiveSearch(TreeNode* root, int key){
    if (root == NULL)
        return false;
    if (root->data > key)
        return recursiveSearch(root->left, key);
    else if (root->data < key)
        return recursiveSearch(root->right, key);
    else
        return true;
}

TreeNode* minValue(){
    if (root == NULL){
        return NULL;
    }
    TreeNode* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* maxValue(){
    if (root == NULL)
        return NULL;
    TreeNode* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}


TreeNode* inOrderSuccessor(TreeNode* root){
    while (root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (root->data > key){
        root->left = deleteNode(root->left, key);
    } else if (root->data < key){
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL){
            return NULL;
        } 
        if (root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* successor = inOrderSuccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}
int main(){
    // Singly Linked list using Pointers

    // SinglyLinkedList list;
    // list.pushFront(1);
    // list.pushBack(2);
    // list.pushBack(3);
    // list.pushBack(4);
    // list.pushBack(5);
    // list.pushBack(6);
    // list.print();
    // list.deleteNode(4);
    // list.print();
    // list.deleteAlternative();
    // list.print();
    // list.popBack();
    // list.popFront();
    // list.print();
    // list.reverseList();
    // list.recursiveRevervse(list.head, NULL);
    // list.swapNodes();
    // list.print();
    // SinglyLinkedList l2;
    // mergeSorted(list.head, list.head, l2);
    // l2.print();
    // list.print();
    // cout << list.findMid() << endl;

    // DoublyLinkedList dlist;
    // dlist.insertAtHead(1);
    // dlist.insertAtHead(2);
    // dlist.insertAtHead(3);
    // dlist.insertAtTail(4);
    // dlist.insertAtTail(5);
    // dlist.insertAtTail(6);
    // dlist.print();
    // dlist.deleteFromHead();
    // dlist.deleteFromTail();
    // dlist.insert(7, 3);
    // dlist.deleteNode(4);
    // dlist.deleteNode(4);
    // dlist.swapNodes();
    // dlist.print();
    // dlist.reverse_print();
    // dlist.reverse();
    // dlist.print();

    // Stack Using Arrays
    // StackUsingArray stk(5);
    // stk.push('a');
    // stk.push('b');
    // stk.push('c');
    // stk.push('d');
    // stk.push('e');
    // stk.push('f');          // Overflow condition
    // stk.display();          // e d c b a
    // stk.pop();              // Underflow condition - bcz elements are poped during display method

    // Stack stack;
    // stack.insert('o');
    // stack.insert('l');
    // stack.insert('l');
    // stack.insert('e');
    // stack.insert('h');
    // stack.display();                    // "hello"
    // stack.deletee();                    // "h would be deleted"      
    // stack.display();                    // "ello"
    // cout << stack.peek() << endl;       // e
    // cout << stack.isEmpty() << endl;    // 0 - False  
    
    // Expression
    string infix = "2+8-3*10";
    string postFix = infixToPostFix(infix);
    int result = postFixEvaluation(postFix);
    cout << postFix << endl;
    cout << result << endl;

    // Queue Using Arrays
    // QueueUsingArray qA(5);
    // qA.enque(1);
    // qA.enque(2);
    // qA.enque(3);
    // qA.enque(4);
    // qA.enque(5);
    // qA.display();
    // qA.deque();
    // qA.display();
    // qA.enque(6);

    // Circular Queue Using Arrays
    // CircularQUsingArray cqA(5);
    // cqA.enque(1);
    // cqA.enque(2);
    // cqA.enque(3);
    // cqA.enque(4);
    // cqA.enque(5);
    // cqA.display();
    // cqA.deque();
    // cqA.display();
    // cqA.enque(6);
    // cqA.display();

    // Queue Using Linked List
    // QueueUsingLL qL;
    // qL.enque(1);
    // qL.enque(2);
    // qL.enque(3);
    // qL.enque(4);
    // qL.enque(5);
    // qL.display();
    // qL.deque();
    // qL.display();

    // // Circular Queue using Linked List.
    // CircularQueueUsingLL cqL;
    // cqL.enque(1);
    // cqL.enque(2);
    // cqL.enque(3);
    // cqL.enque(4);
    // cqL.enque(5);
    // cqL.display();
    // cqL.deque();
    // cqL.enque(6);
    // cqL.display();
    // cout << cqL.isEmpty() << endl;

    // // Double Ended Queue
    // DoubleEndedQueue deq;
    // deq.insertAtFront(1);
    // deq.insertAtFront(2);
    // deq.insertAtFront(3);
    // deq.insertAtRear(4);
    // deq.insertAtRear(5);
    // deq.insertAtRear(6);
    // deq.display();
    // deq.deleteFromFront();
    // deq.deleteFromRear();
    // deq.display();
    // cout << deq.isEmpty() << endl;
    // cout << deq.valueAtFront() << endl;
    // cout << deq.valueAtRear() << endl;

    // // Priority Queue
    // PrioirityQueue pq;
    // pq.enque(1);
    // pq.enque(6);
    // pq.enque(3);
    // pq.enque(9);
    // pq.display();
    // pq.deque();
    // pq.display();

    // // Binary Tree
    // int preOrder[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // TreeNode* root = buildTree(preOrder);
    // preOrderTraversal(root);
    // cout << endl;
    // inOrderTraversal(root);
    // cout << endl;
    // postOrderTraversal(root);
    // cout << endl;
    // levelOrderTraversal(root);

    // // Binary Search Trees
    // iterativeInsert(3);
    // iterativeInsert(2);
    // iterativeInsert(1);
    // iterativeInsert(5);
    // iterativeInsert(4);
    // inOrderTraversal(root);
    // cout << endl;
    // cout << recursiveSearch(root, 2) << endl;
    // cout << recursiveSearch(root, 8) << endl;
    // cout << minValue()->data << endl;
    // cout << maxValue()->data << endl;
    // deleteNode(root, 1);
    // inOrderTraversal(root);
    // vector<int> values = {3,2,5,4,1};
    // TreeNode* bst = buildBST(values);
    // inOrderTraversal(bst);
    // cout << endl;
    // preOrderTraversal(bst);
    // cout << endl; 
    return 0;
}