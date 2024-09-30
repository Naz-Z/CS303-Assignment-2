# CS303-Assignment-2

Here's a README file that describes the functionalities of both the SingleLinkedList and IntStack classes, suitable for developers or users who want to understand and utilize the provided code.

Data Structures Implementation
This repository contains C++ implementations of two basic data structures: a single linked list and a stack. Below is a brief overview of each class and its functionalities.

SingleLinkedList
The SingleLinkedList template class is a container that organizes elements in a linear fashion. Each element points to the next, making insertions and deletions efficient at any point in the sequence.

Features
Dynamic size adjustment: Automatically resizes as elements are added or removed.
Template-based implementation: Can store any data type.
Basic operations: Includes methods for adding, removing, and accessing elements.
Operations
push_front(const Item_Type& item): Adds an item at the beginning of the list.
push_back(const Item_Type& item): Adds an item at the end of the list.
pop_front(): Removes the first item of the list.
pop_back(): Removes the last item of the list.
front(): Returns the first element.
back(): Returns the last element.
empty(): Checks if the list is empty.
insert(size_t index, const Item_Type& item): Inserts an item at the specified position.
remove(size_t index): Removes the item at the specified position.
find(const Item_Type& item): Searches for the item and returns its position.
size(): Returns the number of elements in the list.
IntStack
The IntStack class implements a stack using a vector for storage. It is designed to demonstrate how stacks operate, with last-in, first-out (LIFO) access.

Features
Dynamic storage: Uses C++ STL vector to store elements.
Exception handling: Throws exceptions when attempting to access elements from an empty stack.
Operations
isEmpty(): Checks if the stack is empty.
push(int value): Adds an element to the top of the stack.
pop(): Removes the top element of the stack.
top(): Returns the top element of the stack.
average(): Calculates the average of all elements in the stack.
Usage
To use these classes, include the corresponding header files in your C++ project and ensure your compiler supports C++11 (or later) due to the usage of nullptr and other features.
