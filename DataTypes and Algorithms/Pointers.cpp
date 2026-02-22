#include <iostream>
using namespace std;

void change(int &a){	// pass by reference using alias (references)
	a = 20;
}

void changeA(int* a){	// pass by reference using pointers
	*a = 30;
}


int main(){
	// Pointers
	int a = 10;
	int b = 20;
//	cout << &a << endl;		// printing address of a variable
	int* ptr = &a;			// pointer variable --> refer to the address of a varible
	int* ptr1 = &b;
	int** ptr2 = &ptr;		// pointer to pointer --> a pointer variable that points to another pointer

	int *nullPointer = NULL;	// Null pointer --> does not point to any variable
	int ** ptr3;				// stores a garbage value in it
//	cout << ptr << endl;
//	cout << &a << endl;
//	cout << &ptr << endl;
//	cout << ptr2 << endl;
//	cout << &ptr2 << endl;

//	cout << *(&a) << endl;
//	cout << *ptr << endl;
//	cout << *ptr2 << endl;
//	cout << ptr << endl;
//	cout << **ptr2 << endl;
//	cout << nullPointer << endl;		// 0x0

//	change(a);
//	changeA(&a);
//	cout << a << endl;

	int arr[] = {1,2,3,4,5};
//	cout << arr << endl; 		// prints the address of arr[0];
//	cout << &arr[0] << endl; 	// prints the address of arr[0];
//	cout << *arr   << endl;		// prints the value at arr[0]

//	cout << ptr1 - ptr << endl;		// no of integers present between the two

	cout << (ptr1 < ptr) << endl;

	return 0;
}
