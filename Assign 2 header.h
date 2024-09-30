#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<typename Item_Type>
class SingleLinkedList {
private:
    // Define the Node structure that will hold list elements.
    struct Node {
        Item_Type data; // The data stored in the node.
        Node* next; // Pointer to the next node in the list.

        // Constructor for creating a new node.
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
    };

    Node* head; // Pointer to the first node in the list.
    Node* tail; // Pointer to the last node in the list.
    size_t num_items; // Number of items in the list.

public:
    // Constructor initializes an empty list.
    SingleLinkedList();
    // Destructor to clean up all nodes in the list.
    ~SingleLinkedList();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    size_t size() const;
};

#include "SingleLinkedList.tpp"

#endif // SINGLELINKEDLIST_H


#ifndef INT_STACK_H
#define INT_STACK_H

#include <vector>
#include <stdexcept> // For std::out_of_range exception

// Define the IntStack class
class IntStack {
private:
    std::vector<int> stack; // Vector to store stack elements

public:
    bool isEmpty() const;  // Check if the stack is empty
    void push(int value);  // Push an element onto the stack
    void pop();            // Pop an element from the stack
    int top() const;       // Get the top element of the stack
    double average() const; // Calculate the average of elements in the stack
};

#endif // INT_STACK_H