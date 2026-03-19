#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Queue{
    Node* frontt = NULL;
    Node* rear = NULL;
};

void enqueue(Queue& q, int x){
    Node* newNode = new Node();
    newNode->data = x;
    if (q.frontt == NULL && q.rear == NULL){
        q.frontt = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

void dequeue(Queue& q){
    if (q.frontt == NULL && q.rear == NULL){
        cout << "Queue is empty.\n";
        return;
    }
    if (q.frontt == q.rear){
        Node* temp = q.frontt;
        q.frontt = q.rear = NULL;
        delete temp;
    } else {
        Node* temp = q.frontt;
        q.frontt = q.frontt->next;
        delete temp;
    }
}

void display(Queue q){
    if (q.frontt == NULL && q.rear == NULL){
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = q.frontt;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int peek(Queue q){
    return q.frontt->data;
}
int main(){
    Queue q;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    dequeue(q);
    display(q);
    enqueue(q, 7);
    display(q);
    cout << peek(q) << endl;

    return 0;
}
