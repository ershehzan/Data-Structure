#include<iostream>
using namespace std;

// Stack class implemented using array
class Stack{
    int *arr;      // Pointer to dynamically allocated array for stack elements
    int top = -1;  // Index of the top element in the stack, -1 means stack is empty
    int size;      // Maximum size of the stack

public:
    bool flag;     // Flag to indicate whether the stack is empty (1 for empty, 0 for not empty)

    // Constructor to initialize the stack with a given size
    Stack(int s){
        size = s;             // Set the stack size
        top = -1;             // Initialize top as -1 (stack is empty)
        arr = new int[s];     // Dynamically allocate array for the stack
        flag = 1;             // Set flag to 1 (stack is empty)
    }

    // Push operation: adds an element to the top of the stack
    void push(int value){
        if(top == size - 1){  // Check if the stack is full
            cout << "Stack Overflow" << endl;
            return;
        }
        else{
            top++;                 // Move top to the next position
            arr[top] = value;      // Insert the new element at the top
            cout << "Pushed " << value << " to Stack" << endl;
            flag = 0;              // Set flag to 0 (stack is not empty)
        }
    }

    // Pop operation: removes the top element from the stack
    void pop(){
        if(top == -1){             // Check if the stack is empty
            cout << "Stack Underflow" << endl;
            return;
        }
        else{
            cout << "Popped " << arr[top] << " from Stack" << endl;
            top--;                 // Move top down (element "removed")
            if(top == -1)
                flag = 1;          // If stack is now empty, set flag to 1
        }
    }

    // Peek operation: returns the top element without removing it
    int peek(){
        if(top == -1){             // If stack is empty
            cout << "Stack is empty" << endl;
            return -1;             // Error value
        }
        else{
            return arr[top];       // Return top element
        }
    }

    // isEmpty operation: checks if the stack is empty
    bool isEmpty(){
        return top == -1;          // Returns true if stack is empty
    }

    // isSize operation: returns the current number of elements in the stack
    int isSize(){
        return top + 1;            // Stack size is (top + 1)
    }
};

int main(){
    Stack s(5); // Create a stack of size 5

    // Demonstration: push and peek
    s.push(-1); // Push -1 onto the stack

    int value = s.peek(); // Get the top element

    // Use the flag to check if the stack is empty or not
    if(s.flag == 0){
        cout << "Top element is: " << value << endl;
    }
    else{
        cout << "Stack is empty" << endl;
    }

    // Uncomment the below lines to test other operations:
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.pop();
    // cout << s.peek() << endl;
    // cout << s.isEmpty() << endl;
    // cout << s.isSize() << endl;

    return 0;
}
