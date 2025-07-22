#include <iostream>
using namespace std;

class Stack {
    int* arr;      // Pointer to array for stack
    int top;       // Index of top element
    int size;      // Max size of stack

public:
    bool flag;     // True = empty, False = non-empty

    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
        flag = true;  // Stack is initially empty
    }

    // Push operation
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << "Pushed " << value << " to Stack" << endl;
        flag = false; // Stack now has elements
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped " << arr[top] << " from Stack" << endl;
        top--;
        if (top == -1)
            flag = true;  // Stack became empty after pop
    }

    // Peek operation - returns top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Error value
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Return current size of the stack
    int isSize() {
        return top + 1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(5);   // Stack with size 5

    s.push(-1);   // Push one value
    int value = s.peek();  // Peek top value

    // Check if stack has elements using flag
    if (!s.flag) {
        cout << "Top element is: " << value << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    // Uncomment to test other operations
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.pop();
    // cout << "Current size: " << s.isSize() << endl;
    // cout << "Is empty: " << s.isEmpty() << endl;

    return 0;
}
