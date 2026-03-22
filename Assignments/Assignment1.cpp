#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

struct PQueue {
    Node* front = NULL;
};

void insert(PQueue& p) {
    int data, priority;
    cout << "Enter node value: ";
    cin >> data;
    cout << "Enter node priority: ";
    cin >> priority;

    Node* newNode = new Node(data, priority);

    if (p.front == NULL || priority > p.front->priority) {
        newNode->next = p.front;
        p.front = newNode;
    }
    else {
        Node* temp = p.front;

        while (temp->next != NULL && temp->next->priority > priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << "Node inserted.\n";
}

void deleteNode(PQueue& p) {
    if (p.front == NULL) {
        cout << "Priority Queue is empty.\n";
        return;
    }

    Node* temp = p.front;
    cout << "Deleted node: " << temp->data << endl;

    p.front = p.front->next;
    delete temp;
}

void print(const PQueue& p) {
    if (p.front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = p.front;
    cout << "Queue (data:priority): ";

    while (temp != NULL) {
        cout << temp->data << ":" << temp->priority << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    PQueue p;

    cout << "================ PRIORITY QUEUE ================\n\n";
    cout << "Highest Number means Highest Priority.\n\n";

    cout << "Inserting nodes:\n";
    insert(p);
    insert(p);
    insert(p);

    cout << "\nCurrent queue:\n";
    print(p);

    cout << "\nDeleting highest priority node:\n";
    deleteNode(p);

    cout << "\nQueue after deletion:\n";
    print(p);

    cout << "\n===============================================\n";

    return 0;
}
