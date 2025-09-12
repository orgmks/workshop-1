#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;
public:
    LinkedList(); 
    ~LinkedList();
    void insertAtEnd(T value);
    T* searchById(int id);
    T* searchByName(string name);
    bool removeById(int id);
    void displayAll();
    bool isEmpty();
    int getSize();
};
