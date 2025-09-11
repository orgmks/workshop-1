#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(): 
    head(nullptr), size(0) 
{}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::insertAtEnd(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    size++;
}
