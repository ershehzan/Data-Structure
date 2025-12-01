#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {}

    bool empty() { 
        return q.empty(); 
    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() { 
        return q.front();
    }
};

int main() {
    
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30
    cout << "Pop element: " << st.pop() << endl; // 30
    cout << "Top element: " << st.top() << endl; // 20
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // No

    st.pop();
    st.pop();

    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
