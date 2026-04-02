#include <iostream>
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
        while (temp != NULL){
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
            this->insertAtHead(val);
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
int main(){
    // SinglyLinkedList list;
    // list.pushFront(1);
    // list.pushBack(2);
    // list.pushBack(3);
    // list.pushBack(4);
    // list.pushBack(5);
    // list.pushBack(6);
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

    DoublyLinkedList dlist;
    dlist.insertAtHead(1);
    dlist.insertAtHead(2);
    dlist.insertAtHead(3);
    dlist.insertAtTail(4);
    dlist.insertAtTail(5);
    dlist.insertAtTail(6);
    dlist.print();
    // dlist.deleteFromHead();
    // dlist.deleteFromTail();
    // dlist.insert(7, 3);
    // dlist.deleteNode(4);
    // dlist.deleteNode(4);
    dlist.swapNodes();
    dlist.print();
    // dlist.reverse_print();
    // dlist.reverse();
    // dlist.print();
}