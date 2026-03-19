#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node* next = NULL;
};

struct PQueue{
    Node* front = NULL;
};

void insert(PQueue& p, int val, int priority){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->priority = priority;
    if (p.front == NULL || priority > p.front->priority){
        newNode->next = p.front;
        p.front = newNode;
    } else {
        Node* temp = p.front;
        while (temp != NULL && temp->next->priority > priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void remove(PQueue& p){
    if (p.front == NULL){
        cout << "Priority Queue is empty.\n";
        return;
    }
    Node* temp = p.front;
    p.front = p.front->next;
    delete temp;
}

void print(PQueue p){
    Node* temp = p.front;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    PQueue p;
    insert(p, 1, 1);
    insert(p, 3, 4);
    insert(p, 6, 2);
    insert(p, 2, 3);
    insert(p, 8, 5);
    remove(p);
    insert(p, 11, 6);
    insert(p, 30, 5);
    print(p);


    return 0;
}