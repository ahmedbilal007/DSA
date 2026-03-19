#include <iostream>
using namespace std;

const int SIZE = 10;
int queueA[SIZE];
int frontt, rear = -1;

void enqueue(int x){
    if (rear >= SIZE){
        cout << "Overflow.\n";
    } else if (frontt == -1 && rear == -1){
        frontt++;
        rear++;
        queueA[rear] = x;
    } else {
        queueA[++rear] = x;
    }
}

void dequeue(){
    if (frontt == -1 && rear == -1){
        cout << "Queue is empty.\n";
    } else if (frontt == rear){
        frontt = rear = -1;
    } else {
        frontt++;
    }
}

void display(){
    if (frontt == -1 && rear == -1){
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Displaying the queue: ";
    for (int i=frontt; i<=rear; i++){
        cout << queueA[i] << " ";
    }
    cout << endl;
}

int peek(){
    if (frontt == -1 && rear == -1){
        cout << "Queue is empty.\n";
    } else {
        return queueA[frontt];
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    enqueue(6);
    display();
    dequeue();
    display();
    cout << peek() << endl;

    return 0;
}
