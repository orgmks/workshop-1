#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertAtEnd(T value);
    T* searchById(int id);
    void searchByName(const std::string& name) const;
    bool removeById(int id);
    void displayAll() const;
    bool isEmpty() const;
    int getSize() const;
    bool insert(const T& student);
    bool remove(int id);
    bool exists(int id) const;
    void display() const;
};

#endif

