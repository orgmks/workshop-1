#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() 
    : head(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::insertAtEnd(T value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        ++size;
        return;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
    ++size;
}

template <typename T>
T* LinkedList<T>::searchById(int id) {
    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->data.getId() == id) {
            return &cur->data;
        }
    }
    return nullptr;
}

template <typename T>
T* LinkedList<T>::searchByName(const std::string& name) {
    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->data.getName() == name) {
            return &cur->data;
        }
    }
    return nullptr;
}

template <typename T>
bool LinkedList<T>::removeById(int id) {
    if (!head) return false;

    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
        return true;
    }
    Node* cur = head;
    while (cur->next && cur->next->data.getId() != id) {
        cur = cur->next;
    }

    if (!cur->next) return false; 

    Node* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
    --size;
    return true;
}

template <typename T>
void LinkedList<T>::displayAll() const {
    if (!head) {
        std::cout << "The list is empty.\n";
        return;
    }

    for (Node* cur = head; cur; cur = cur->next) {
        cur->data.display();
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}


#include "Student.h"
template class LinkedList<Student>;
