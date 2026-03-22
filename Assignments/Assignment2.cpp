#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

struct dequee{
    Node* frontt = NULL;
    Node* rear = NULL;
};

void insertAtFront(dequee& d){
    Node* newNode = new Node();
    cout << "Enter value to add Node: ";
    cin >> newNode->data;
    if (d.frontt == NULL && d.rear == NULL){
        d.frontt = d.rear = newNode;
    } else {
        newNode->next = d.frontt;
        d.frontt = newNode;
    }
    cout << "Node inserted at front.\n";
}

void insertAtRear(dequee& d){
    Node* newNode = new Node();
    cout << "Enter value to add Node: ";
    cin >> newNode->data;
    if (d.frontt == NULL && d.rear == NULL){
        d.frontt = d.rear = newNode;
    } else {
        d.rear->next = newNode;
        d.rear = newNode;
    }
    cout << "Node inserted at rear.\n";
}

void deleteFromFront(dequee& d){
    if (d.frontt == NULL){
        cout << "Queue is empty. Can't delete Node.\n";
        return;
    }
    if (d.frontt == d.rear){
        Node* temp = d.frontt;
        d.frontt = d.rear = NULL;
        delete temp;
        return;
    }
    Node* temp = d.frontt;
    d.frontt = d.frontt->next;
    temp->next = NULL;
    delete temp;
    cout << "Node deleted from the front.\n";
}

void deleteFromRear(dequee& d){
    if (d.frontt == NULL){
        cout << "Queue is empty. Can't delete Node.\n";
        return;
    }
    if (d.frontt == d.rear){
        Node* temp = d.frontt;
        d.frontt = d.rear = NULL;
        delete temp;
        return;
    }
    Node* temp = d.frontt;
    while (temp->next != d.rear){
        temp = temp->next;
    }
    temp->next = NULL;
    delete d.rear;
    d.rear = temp;
    cout << "Node deleted from the rear.\n";
}
void display(dequee d){
    if (d.frontt == NULL){
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = d.frontt;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void peekAtFront(dequee d){
    if (d.frontt == NULL){
        cout << "Queue is empty.\n";
        return;
    }
    cout << d.frontt->data << endl;
}

void peekAtRear(dequee d){
    if (d.frontt == NULL){
        cout << "Queue is empty.\n";
        return;
    }
    cout << d.rear->data << endl;
}

int main(){
    dequee d;

    cout << "*****************************************************\n";
    cout << "**************** DOUBLE ENDED QUEUE *****************\n\n";

    cout << "Inserting nodes at the front and rear of the queue:\n";
    insertAtFront(d);
    insertAtFront(d);
    insertAtRear(d);
    insertAtRear(d);

    cout << "\nDisplaying the queue:\n";
    display(d);

    cout << "\nValues at the peek of the queue:\n";
    cout << "Front Peek: ";
    peekAtFront(d);

    cout << "Rear Peek: ";
    peekAtRear(d);

    cout << "\n\nDeleting nodes from the front and rear of the queue:\n";
    deleteFromFront(d);
    deleteFromRear(d);

    cout << "\nDisplaying the queue after deletion:\n";
    display(d);

    cout << "\n*****************************************************\n";

    return 0;
}
