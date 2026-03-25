#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct LinkedList{
    Node* head = NULL;
    Node* tail = NULL;
};

void push_front(LinkedList& l, int val){
    Node* newNode = new Node();
    newNode->data = val;
    if (l.head == NULL){
        l.head = l.tail = newNode;
    } else {
        newNode->next = l.head;
        l.head = newNode;
    }
}

void push_back(LinkedList& l, int val){
    Node* newNode = new Node();
    newNode->data = val;
    if (l.head == NULL)
        l.head = l.tail = newNode;
    else{
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void pop_front(LinkedList& l){
    if (l.head == NULL){
        cout << "Linked list is empty.\n";
        return;
    }
    Node* temp = l.head;
    l.head = l.head->next;
    delete temp;
}

void pop_back(LinkedList& l){
     if (l.head == NULL){
        cout << "Linked list is empty.\n";
        return;
    }
    Node* temp = l.head;
    while (temp->next != l.tail){
        temp = temp->next;
    }
    temp->next = NULL;
    delete l.tail;
    l.tail = temp;
}

void print(LinkedList l){
    if (l.head == NULL){
        cout << "Linked List is empty.\n";
        return;
    }
    Node* temp = l.head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insert(LinkedList& l, int pos, int val){
    if (pos < 0){
        cout << "Invalid Position.\n";
        return;
    }
    if (pos == 0){
        push_front(l, val);
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    Node* temp = l.head;
    for (int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletee(LinkedList& l, int val){
    if (l.head == NULL){
        cout << "Linked List is empty.\n";
        return;
    }
    if (l.head->data == val){
        pop_front(l);
        return;
    }
    if (l.tail->data == val){
        pop_back(l);
        return;
    }
    Node* temp = l.head;
    Node* temp2 = NULL;
    while (temp != NULL && temp->data != val){
        temp2 = temp;
        temp = temp->next;
    }
    if (temp != NULL){
        temp2->next = temp->next;
        temp->next = NULL;
        delete temp;
    } else {
        cout << "Node not found in the list.\n";
    }
}

Node* reverseList(LinkedList& l){
    if (l.head == NULL || l.head->next == NULL)
    {
        return l.head;
    }
    Node* cur = l.head;
    Node* prev = NULL;
    while (cur != NULL){
        Node* nextt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextt;
    }
    l.head = prev;
    return prev;
}

Node* recursiveReverse(LinkedList& l, Node* cur, Node* prev){
    if (cur == NULL){
        l.head = prev;
        return prev;
    }
    Node* next = cur->next;
    cur->next = prev;
    return recursiveReverse(l, next, cur);
}

int findMid(LinkedList l){
    if (l.head == NULL || l.head->next == NULL){
        return l.head->data;
    }
    Node* slow = l.head;
    Node* fast = l.head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

bool detectCycle(LinkedList l){
    if (l.head == NULL || l.head->next == NULL){
        return false;
    }
    Node* slow = l.head;
    Node* fast = l.head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int valueFromEnd(LinkedList& l, int n){
    if (l.head == NULL || n < 0){
        cout << "Either list is empty or invalid value is given.\n";
        return -11111111;
    }
    Node* fast = l.head;
    Node* slow = l.head;
    for (int i=0; i<n; i++)
        fast = fast->next;
    while (fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

void deleteFromEnd(LinkedList& l, int n){
    if (l.head == NULL || n < 0){
        cout << "Either list is empty or invalid value is given.\n";
        return;
    }
    Node* fast = l.head;
    Node* slow = l.head;
    Node* prev = NULL;
    for (int i=0; i<n; i++){
        if (fast == NULL){
            cout << "n is greater than length of the list.\n";
            return;
        }
        fast = fast->next;
    }
    if (fast == NULL){
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
        return;
    }
    while (fast != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = slow->next;
    slow->next = NULL;
    delete slow;
}

bool isPalindrome(LinkedList l){
    if (l.head == NULL || l.head->next == NULL){
        return false;
    }
    Node* fast = l.head;
    Node* slow = l.head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL){
        slow = slow->next;
    }
    Node* cur = slow;
    Node* prev = NULL;
    while (cur != NULL){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    Node* first = l.head;
    Node* second = prev;
    while (second != NULL){
        if (first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }
    return true;
}

Node* swapNodes(LinkedList& l){
    if (l.head == NULL || l.head->next == NULL){
        return l.head;
    }
    Node* first = l.head;
    Node* sec = first->next;
    Node* prev = NULL;
    while (first != NULL && sec != NULL){
        Node* third = sec->next;
        sec->next = first;
        first->next = third;
        if (prev != NULL){
            prev->next = sec;
        } else {
            l.head = sec;
        }
        prev = first;
        first = third;
        if (third != NULL){
            sec = third->next;
        } else {
            sec = NULL;
        }
    }
    return l.head;
}
int main(){
    LinkedList l;
    push_back(l, 1);
    push_back(l, 2);
    push_back(l, 3);
    push_back(l, 3);
    push_back(l, 7);
    push_back(l, 1);
//    pop_back(l);
//    pop_front(l);
//    insert(l, 3, 8);
//    deletee(l, 6);
//    recursiveReverse(l, l.head, NULL);
//    cout << findMid(l) << endl;
    print(l);
//    cout << valueFromEnd(l, 4) << endl;
//    deleteFromEnd(l, 4);
//    print(l);
//    cout << isPalindrome(l) << endl;
    swapNodes(l);
    print(l);
    return 0;
}
