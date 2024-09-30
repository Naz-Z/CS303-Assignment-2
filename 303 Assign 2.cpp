#include <iostream>

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

    // Data members of the linked list.
    Node* head; // Pointer to the first node in the list.
    Node* tail; // Pointer to the last node in the list.
    size_t num_items; // Number of items in the list.

public:
    // Constructor initializes an empty list.
    SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor to clean up all nodes in the list.
    ~SingleLinkedList() {
        while (!empty()) {
            pop_front(); // Continuously remove the front until the list is empty.
        }
    }

    // Adds an item to the front of the list.
    void push_front(const Item_Type& item) {
        head = new Node(item, head); // Create a new node that points to the current head.
        if (tail == nullptr) {
            tail = head; // If the list was empty, new node is also the tail.
        }
        num_items++; // Increment the number of items.
    }

    // Adds an item to the back of the list.
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item); // Create a new node.
        if (tail != nullptr) {
            tail->next = new_node; // Link the old tail to the new node.
        } else {
            head = new_node; // If the list was empty, new node is the head.
        }
        tail = new_node; // Update the tail to the new node.
        num_items++; // Increment the number of items.
    }

    // Removes the front item from the list.
    void pop_front() {
        if (head != nullptr) {
            Node* old_head = head; // Temporarily store the old head.
            head = head->next; // Move the head to the next node.
            delete old_head; // Delete the old head node.
            if (head == nullptr) {
                tail = nullptr; // If the list is now empty, also reset the tail.
            }
            num_items--; // Decrement the number of items.
        }
    }

    // Removes the back item from the list.
    void pop_back() {
        if (head == nullptr) return; // If the list is empty, do nothing.
        if (head == tail) {
            delete head; // If there's only one node, delete it.
            head = tail = nullptr; // Reset head and tail to nullptr.
        } else {
            Node* current = head;
            // Traverse the list to find the second-to-last node.
            while (current->next != tail) {
                current = current->next;
            }
            delete tail; // Delete the tail node.
            tail = current; // Update the tail to the second-to-last node.
            tail->next = nullptr; // Set the new tail's next to nullptr.
        }
        num_items--; // Decrement the number of items.
    }

    // Returns the data at the front of the list.
    Item_Type front() const {
        if (head != nullptr) {
            return head->data; // Return the data of the head node.
        }
        throw std::out_of_range("List is empty"); // Throw exception if the list is empty.
    }

    // Returns the data at the back of the list.
    Item_Type back() const {
        if (tail != nullptr) {
            return tail->data; // Return the data of the tail node.
        }
        throw std::out_of_range("List is empty"); // Throw exception if the list is empty.
    }

    // Checks if the list is empty.
    bool empty() const {
        return head == nullptr; // Return true if the head is nullptr.
    }

    // Inserts an item at a specified index.
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item); // If index is 0, use push_front.
        } else {
            Node* current = head;
            // Traverse the list to find the node before the insertion point.
            for (size_t i = 1; i < index && current->next != nullptr; i++) {
                current = current->next;
            }
            current->next = new Node(item, current->next); // Insert the new node.
            if (current->next->next == nullptr) {
                tail = current->next; // Update the tail if necessary.
            }
            num_items++; // Increment the number of items.
        }
    }

    // Removes an item at a specified index.
    bool remove(size_t index) {
        if (index >= num_items) return false; // Return false if index is out of bounds.
        if (index == 0) {
            pop_front(); // Use pop_front if index is 0.
            return true;
        }
        Node* current = head;
        // Traverse the list to find the node before the one to remove.
        for (size_t i = 1; i < index && current->next != nullptr; i++) {
            current = current->next;
        }
        Node* to_delete = current->next; // Temporarily store the node to delete.
        current->next = to_delete->next; // Unlink the node from the list.
        if (to_delete == tail) {
            tail = current; // Update the tail if necessary.
        }
        delete to_delete; // Delete the node.
        num_items--; // Decrement the number of items.
        return true;
    }

    // Finds the index of the first occurrence of an item.
    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        // Traverse the list searching for the item.
        while (current != nullptr) {
            if (current->data == item) {
                return index; // Return the index if found.
            }
            current = current->next;
            index++;
        }
        return num_items; // Return the size of the list if not found.
    }

    // Returns the number of items in the list.
    size_t size() const {
        return num_items;
    }
};

int main() {
    SingleLinkedList<int> list;
    list.push_back(10);
    list.push_front(20);
    list.push_back(30);
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    list.pop_front();
    std::cout << "New Front: " << list.front() << std::endl;
    list.insert(1, 25);
    std::cout << "New Back: " << list.back() << std::endl;
    list.remove(1);
    std::cout << "Removed element at index 1, new back: " << list.back() << std::endl;
    std::cout << "Find 30, index: " << list.find(30) << std::endl;
    return 0;
}


// Q2
#include <vector>  // Include the vector library
#include <iostream> // Include the iostream library
// Define a class for the stack
class IntStack {
private:
    std::vector<int> stack;  // Vector to store stack elements

public:
    // Check if the stack is empty
    bool isEmpty() const {
        return stack.empty();  // Return true if stack is empty
    }

    // Push an element onto the stack
    void push(int value) {
        stack.push_back(value);  // Add value to the end of the vector
    }

    // Pop an element from the stack
    void pop() {
        if (!isEmpty()) {  // Check if the stack is not empty
            stack.pop_back();  // Remove the last element from the vector
        }
    }

    // Get the top element of the stack
    int top() const {
        if (!isEmpty()) {  // Check if the stack is not empty
            return stack.back();  // Return the last element of the vector
        }
        throw std::out_of_range("Stack is empty");  // Throw an exception if stack is empty
    }

    // Calculate the average of elements in the stack
    double average() const {
        if (isEmpty()) {  // Check if the stack is empty
            throw std::out_of_range("Stack is empty");  // Throw an exception if stack is empty
        }
        int sum = 0;  // Initialize sum of elements
        for (int num : stack) {  // Loop through each element in the stack
            sum += num;  // Add element to sum
        }
        return static_cast<double>(sum) / stack.size();  // Calculate and return the average
    }
};

int main() {
    IntStack myStack;  // Create a stack object

    // Check if the stack is empty and print the result
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Pop an element from the stack
    myStack.pop();

    // Display the top element of the stack
    std::cout << "Top of the stack: " << myStack.top() << std::endl;

    // Calculate and display the average value of the stack elements
    std::cout << "Average value of stack elements: " << myStack.average() << std::endl;

    return 0;  // End of the program
}
