#include "../include/linked_list.h"
#include "../include/user.h"  // Add this so 'User' is complete
using namespace std;

template<typename T>
LinkedList<T>::LinkedList()  {}

template<typename T>
LinkedList<T>::~LinkedList() {
    
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::push_back(const T& val) {
    
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::push_front(const T& val) {
    
}

template<typename T>
void LinkedList<T>::insert_after(Node* pos, const T& val) {
    
}

template<typename T>
void LinkedList<T>::remove(Node* node) {
    
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::find(function<bool(const T&)> pred) {
    
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::head() const {
    
}

template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::tail() const {
    
}

template<typename T>
size_t LinkedList<T>::size() const {
    
}

template<typename T>
void LinkedList<T>::clear() {
    
}

// Explicit template instantiation for commonly used types
template class LinkedList<int>;
template class LinkedList<string>;

// Forward declare User struct for template instantiation
struct User;
template class LinkedList<User>;