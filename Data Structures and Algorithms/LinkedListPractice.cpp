#include <iostream>
using namespace std;

// Singly Linked List
struct Node{
    int val;
    Node* next = NULL;
};
struct LinkedList{
    Node* head = NULL;
    Node* tail = NULL;
};

void push_front(LinkedList& l1, int value){
    Node* newNode = new Node();
    newNode->val = value;
    if (l1.head == NULL){
        l1.head = l1.tail = newNode;
        return;
    } else {
        newNode->next = l1.head;
        l1.head = newNode;
    }
};

void push_back(LinkedList& l1, int value){
    Node* newNode = new Node();
    newNode->val = value;
    if (l1.head == NULL){
        l1.head = l1.tail = newNode;
        return;
    } else {
        l1.tail->next = newNode;
        l1.tail = newNode;
    }
}

void pop_front(LinkedList& l1){
    Node* temp = l1.head;
    if (l1.head == NULL){
        cout << "Linked list is empty.\n";
        return;
    } else {
        l1.head = l1.head->next;
        temp->next = NULL;
        delete temp;
    }
}

void pop_back(LinkedList l1){
    if (l1.head == NULL){
        cout << "Linked list is empty.\n";
        return;
    }
    Node* temp = l1.head;
    while (temp->next != l1.tail){
        temp = temp->next;
    }
    temp->next = NULL;
    delete l1.tail;
    l1.tail = temp;
}

void insert(LinkedList l1, int value, int pos){
    if (pos == 0){
        push_front(l1,value);
        return;
    }
    Node* newNode = new Node();
    newNode->val = value;
    Node* temp = l1.head;
    for (int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeElement(LinkedList l1, int value){
    Node* temp = l1.head;

    while(temp->next->val != value){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}
void print_list(LinkedList l1){
    Node* temp = l1.head;
    while (temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* swap_pairs(LinkedList& l){
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
        if (prev != NULL)
            prev->next = sec;
        else
            l.head = sec;
        prev = first;
        first = third;
        if (third != NULL)
            sec = third->next;
        else
            sec = NULL;
    }

    Node* temp = l.head;
    return l.head;
}

/*
    Class Implementation of Linked List.
*/


//class Node
//{
//public:
//    int val;
//    Node* next;
//
//    Node(int val)
//    {
//        this->val = val;
//        next = NULL;
//    }
//};
//
//class List
//{
//public:
//    Node* head;
//    Node* tail;
//
//    List()
//    {
//        head = tail = NULL;
//    }
//
//    void print()
//    {
//        Node* temp = head;
//        while (temp != NULL)
//        {
//            cout << temp->val << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//
//    void push_front(int val)
//    {
//        Node* newNode = new Node(val);
//        if (head == NULL)
//        {
//            head = tail = newNode;
//            return;
//        }
//        else
//        {
//            newNode->next = head;
//            head = newNode;
//        }
//    }
//
//    void push_back(int val)
//    {
//        Node* newNode = new Node(val);
//        if (head==NULL)
//        {
//            head = tail = newNode;
//            return;
//        }
//        else
//        {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    void pop_front()
//    {
//        if (head==NULL)
//        {
//            cout << "linked list is empty.";
//            return;
//        }
//        Node* temp = head;
//        head = temp->next;
//        temp->next = NULL;
//        delete temp;
//    }
//
//    void pop_back()
//    {
//        if (head == NULL)
//        {
//            cout << "linked list is empty" << endl;
//            return;
//        }
//        Node* temp = head;
//        while (temp->next != tail)
//        {
//            temp = temp->next;
//        }
//        temp->next = NULL;
//        delete tail;
//        tail = temp;
//    }
//
//    void insert(int val, int pos)
//    {
//        if (pos < 0)
//        {
//            cout << "invalid position\n";
//            return;
//        }
//        if (pos==0)
//        {
//            push_front(val);
//            return;
//        }
//        Node* newNode = new Node(val);
//        Node* temp = head;
//        for (int i=0; i<pos-1; i++)
//        {
//            if (temp==NULL)
//            {
//                cout << "invalid position\n";
//                return;
//            }
//            temp = temp->next;
//        }
//        newNode->next = temp->next;
//        temp->next = newNode;
//    }
//
//    int search(int key)
//    {
//        Node* temp = head;
//        int idx = 0;
//        while (temp != NULL)
//        {
//            if (temp->val == key)
//                return idx;
//            temp = temp->next;
//            idx++;
//        }
//        return -1;
//    }
//
//    Node* reverse()
//    {
//        Node* prev = NULL;
//        Node* curr = head;
//        Node* nextN = NULL;
//        while(curr != NULL)
//        {
//            nextN = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextN;
//        }
//        return prev;
//    }
//
//    Node* swap_pairs(){
//        if (head == NULL || head->next == NULL)
//            return head;
//        Node* first = head;
//        Node* sec = first->next;
//        Node* prev = NULL;
//        while (first != NULL && sec != NULL){
//            Node* third = sec->next;
//            sec->next = first;
//            first->next = third;
//            if (prev != NULL)
//                prev->next = sec;
//            else
//                head = sec;
//            prev = first;
//            first = third;
//            if (third != NULL)
//                sec = third->next;
//            else
//                sec = NULL;
//        }
//
//        Node* temp = head;
//        return head;
//    }
//};

int main()
{
//    List list;
//    list.push_back(1);
//    list.push_back(2);
//    list.push_back(3);
//    list.push_back(4);
//    list.push_back(5);
////    list.pop_front();
////    list.pop_back();
//    list.insert(9,2);
//    list.print();
////    cout << list.reverse()->val << endl;
////    cout << list.search(3) << endl;
//
//    cout << list.swap_pairs()->val << endl;
//    list.print();

// Struct

    LinkedList l1;
    push_front(l1, 1);
    push_front(l1, 2);
    push_back(l1, 3);
    push_front(l1, 1);
    push_front(l1, 2);
    push_back(l1, 8);
    insert(l1, 7, 3);
    removeElement(l1, 7);
//    pop_front(l1);
//    pop_back(l1);
    print_list(l1);
    swap_pairs(l1);
    print_list(l1);


    return 0;
}
