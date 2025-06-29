#include <iostream>
using namespace std;

// Node structure for linked list implementation of stack
class Node {
public:
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
    Node* top; // Pointer to the top node of the stack

public:
    // Constructor: initializes the stack as empty
    Stack() {
        top = nullptr;
    }

    // Push operation: adds an element to the top of the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node with given value
        newNode->next = top;             // Point new node's next to current top
        top = newNode;                   // Update top to the new node
        cout << "Pushed " << value << " to Stack" << endl;
    }

    // Pop operation: removes the top element from the stack
    void pop() {
        if (top == nullptr) {            // If stack is empty
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;                // Temporary pointer to top
        cout << "Popped " << top->data << " from Stack" << endl;
        top = top->next;                 // Move top to the next node
        delete temp;                     // Delete the popped node
    }

    // Peek operation: returns the data at the top of the stack without removing it
    int peek() {
        if (top == nullptr) {            // If stack is empty
            cout << "Stack is empty" << endl;
            return -1;                   // Or some error value
        }
        return top->data;                // Return the data of the top node
    }

    // isEmpty operation: returns true if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display operation: prints all elements in the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";   // Print current node's data
            temp = temp->next;           // Move to next node
        }
        cout << endl;
    }

    // Destructor: cleans up all nodes when stack object goes out of scope
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s; // Create a stack object

    // Demonstration of stack operations
    s.push(10);   // Push 10
    s.push(20);   // Push 20
    s.push(30);   // Push 30

    s.display();  // Display stack elements

    cout << "Top element is: " << s.peek() << endl; // Peek at top

    s.pop();      // Pop top element
    s.display();  // Display after pop

    s.pop();
    s.pop();

    // Try popping from empty stack
    s.pop();

    // Check if stack is empty
    if (s.isEmpty()) {
        cout << "Stack is empty now." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
