#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;

	Node(int val){
		this->val = val;
		next = NULL;
	}
};

class List{
public:
	Node* head;
	Node* tail;

	List(){
		head = tail = NULL;
	}

	void push_front(int val){
		Node* newNode = new Node(val);
		if (head == NULL){
			head = tail = newNode;
			return;
		} else {
			newNode->next = head;
			head = newNode;
		}
	}

	void push_back(int val){
		Node* newNode = new Node(val);
		if (head == NULL){
			head = tail = newNode;
			return;
		} else {
			tail->next = newNode;
			tail = newNode;
		}


	}

	void pop_front(){
		if (head == NULL){
			cout << "List is empty.\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}

	void pop_back(){
		Node* temp = head;
		if (head == NULL){
			cout << "List is empty.\n";
			return;
		}
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
			push_front(val);
			return;
		}
		Node* newNode = new Node(val);
		Node* temp = head;
		for (int i=0; i<pos-1; i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}

	int search(int key){
		Node* temp = head;
		int idx = 0;
		while (temp != NULL){
			if (temp->val == key)
				return idx;
			temp = temp -> next;
			idx++;
		}
		return -1;
	}

	Node* reverse(){
        Node* curr = head;
        Node* nextNode = NULL;
        Node* prevNode = NULL;
        while (curr != NULL){
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        head = prevNode;
        return prevNode;
    }

    Node* recursive_reverse(Node* prev, Node* cur){
		if (cur == NULL){
			head = prev;
			return prev;
		}
		Node* nextN = cur->next;
		cur->next = prev;
		return recursive_reverse(cur, nextN);
    }

    Node* middleOfList(){
		Node* fast = head;
		Node* slow = head;
		while(fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
    }

    bool detectCycle(){
		Node* slow = head;
		Node* fast = head;
		while (fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
    }

    Node* cycleNode(){
		Node* slow = head;
		Node* fast = head;
		bool isCycle = false;
		while (fast != NULL && fast->next != NULL){
			slow = slow->next;// Detecting cycle in the linked list.
			fast = fast->next->next;
			if (slow == fast){
				isCycle = true;
				break;
			}
		}
		if (!isCycle){
			return NULL;
		} else {
			slow = head;
			Node* prev;
			while (slow != fast){ // Finding the starting point of the cycle in the linked list where cycle starts
				slow = slow->next;
				prev = fast;
				fast = fast->next;
			}
			prev->next = NULL;
			return slow;

			// Prev Node keeps track of the last node in the list because the starting point of the cycle in ahead of the last
		}
	}

	void print_list(){
		Node* temp = head;
		while(temp != NULL){
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

Node* merge_sorted(Node* h1, Node* h2, List & new_list){
	if (h1 == NULL){
		new_list.push_back(h2->val);
		return h2;
	};
	if (h2 == NULL){
		new_list.push_back(h1->val);
		return h1;
	}
	if (h1->val <= h2->val){
		h1->next = merge_sorted(h1->next, h2, new_list);
		new_list.push_front(h1->val);
		return h1;
	} else {
		h2->next = merge_sorted(h1, h2->next, new_list);
		new_list.push_front(h2->val);
		return h2;
	}
}


int main(){
//	List l1;
//	l1.push_front(4);					// 4
//	l1.push_front(7);					// 7 4
//	l1.push_back(6);					// 7 4 6
//	l1.push_back(8);					// 7 4 6 8
//	l1.pop_front();						// 4 6 8
//	l1.pop_back();						// 4 6
//	l1.insert(5, 1);					// 4 5 6
//	cout << l1.search(5) << endl;		// 1
//	cout << l1.reverse()->val << endl;	// 6 -------> new value of head after reversing the linked list
//	l1.print_list();					// 6 5 4 ---> reversed linked list (original => 4 5 6)
//	cout << l1.middleOfList()->val << endl;		// 5
//	cout << l1.detectCycle() << endl;

	List list1;
	List list2;
	List list3;
	list1.push_back(2);
	list1.push_back(6);
	list1.push_back(8);

	cout << list1.reverse()->val << endl;
	list1.print_list();

	cout << list1.recursive_reverse(NULL, list1.head)->val << endl;
	list1.print_list();

	list2.push_back(1);
	list2.push_back(6);
	list2.push_back(7);

	cout << "After merging the two lists: " << merge_sorted(list1.head, list2.head, list3)->val << endl;
	list3.print_list();
    return 0;
}
