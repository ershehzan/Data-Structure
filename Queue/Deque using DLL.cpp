#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node
{
public:
    int data;           // Value stored in the node
    Node *next, *prev;  // Pointers to the next and previous nodes

    // Constructor to initialize a node with a value
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

// Deque class using a doubly linked list
class Deque
{
    Node *front, *rear; // Pointers to the front and rear of the deque

public:
    // Constructor: initializes an empty deque
    Deque()
    {
        front = rear = NULL;
    }

    // Checks if the deque is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Adds an element to the front of the deque
    void push_front(int val)
    {
        if (isEmpty())
        {
            // If empty, both front and rear point to the new node
            front = rear = new Node(val);
        }
        else
        {
            // Insert new node at the front
            Node *temp = new Node(val);
            temp->next = front;     // Link new node to current front
            front->prev = temp;     // Link current front back to new node
            front = temp;           // Update front pointer
        }
    }

    // Adds an element to the rear of the deque
    void push_back(int x)
    {
        if (isEmpty())
        {
            // If empty, both front and rear point to the new node
            front = rear = new Node(x);
        }
        else
        {
            // Insert new node at the rear
            Node *temp = new Node(x);
            rear->next = temp;      // Link current rear to new node
            temp->prev = rear;      // Link new node back to current rear
            rear = temp;            // Update rear pointer
        }
    }
    
    // Removes an element from the front of the deque
    void pop_front(){
        if(isEmpty()){
            cout << "Deque is empty, cannot pop from front." << endl;
            return;
        }
        else if(front==rear){
            // Only one element present, deque becomes empty
            delete front;
            front=rear=NULL;
        }
        else{
            // Remove the front node and update pointers
            Node* temp = front;
            front = front->next;    // Move front pointer to next node
            delete temp;            // Delete old front node
            front->prev = NULL;     // Set new front's prev to NULL
        }
    }
   
    // Removes an element from the rear of the deque
    void pop_back(){
        if(isEmpty()){
            cout << "Deque is empty, cannot pop from front." << endl;
            return;
        }
        else if(front==rear){
            // Only one element present, deque becomes empty
            delete front;
            front=rear=NULL;
        }
        else{
            // Remove the rear node and update pointers
            Node* temp = rear;
            rear = rear->prev;      // Move rear pointer to previous node
            delete temp;            // Delete old rear node
            rear->next = NULL;      // Set new rear's next to NULL
        }
    }
    
    // Returns the front element of the deque
    int start(){
        if(isEmpty()){
            cout << "Deque is empty, no front element." << endl;
            return -1; // Indicating deque is empty
        }
        return front->data;
    }

    // Returns the rear element of the deque
    int end(){
        if(isEmpty()){
            cout << "Deque is empty, no rear element." << endl;
            return -1; // Indicating deque is empty
        }
        return rear->data;
    }

    // Displays all elements in the deque from front to rear
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq; // Create a Deque object

    // Demonstrate push operations
    dq.push_front(10); // Add 10 to the front
    dq.push_back(20);  // Add 20 to the rear
    dq.push_front(5);  // Add 5 to the front
    dq.push_back(30);  // Add 30 to the rear

    cout << "Deque after pushing elements: ";
    dq.display(); // Output: 5 10 20 30

    // Display front and rear elements
    cout << "Front element: " << dq.start() << endl; // Output: 5
    cout << "Rear element: " << dq.end() << endl;    // Output: 30

    // Demonstrate pop operation from front
    dq.pop_front(); // Remove front element (5)
    cout << "Deque after popping front element: ";
    dq.display();   // Output: 10 20 30

    return 0;
}
