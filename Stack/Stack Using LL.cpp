#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack using Linked List
class Stack {
    Node* top;     // Pointer to top node
    int size;      // Stack size

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    // Push operation
    void push(int value) {
        Node* temp = new Node(value);
        if (temp == NULL) {
            cout << "Stack Overflow (Memory Allocation Failed)" << endl;
            return;
        }
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushed " << value << " to Stack" << endl;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped " << temp->data << " from Stack" << endl;
        top = top->next;
        delete temp;
        size--;
    }

    // Peek operation
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        cout << "Peeked " << top->data << " from Stack" << endl;
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Get current size
    int isSize() {
        return size;
    }

    // Destructor to free all nodes
    ~Stack() {
        while (top) {
            pop();  // This will delete each node
        }
    }
};

// Driver Code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek(); // Will also print the top

    cout << "Current Stack Size: " << s.isSize() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();  // Will trigger underflow

    if (s.isEmpty()) {
        cout << "Stack is now empty." << endl;
    }

    return 0;
}
