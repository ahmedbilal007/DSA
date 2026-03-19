#include <iostream>
using namespace std;
const int N = 5;
int cQueue[N];
int frontt = -1;
int rear = -1;

void enqueue(int x){
    if (((rear + 1)%N == frontt)){
        cout << "Queue Overflow.\n";
        return;
    }
    if (rear == -1 && frontt == -1){
        rear = frontt = 0;
        cQueue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        cQueue[rear] = x;
    }
}

void dequeue(){
    if (rear == -1 && frontt == -1){
        cout << "Queue is empty.\n";
        return;
    }
    if (rear == frontt){
        rear = frontt = -1;
    } else {
        frontt = (frontt + 1)%N;
    }
}

void display(){
    if (rear == -1 && frontt == -1){
        cout << "Queue is empty.\n";
        return;
    }
    int i = frontt;
    while (i != rear){
        cout << cQueue[i] << " ";
        i = (i + 1) % N;
    }
    cout << cQueue[rear] << endl;
}

int peek(){
    if (rear == -1 && frontt == -1){
        cout << "Queue is empty.\n";

    } else {
        return cQueue[frontt];
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(7);
    display();

    return 0;
}
