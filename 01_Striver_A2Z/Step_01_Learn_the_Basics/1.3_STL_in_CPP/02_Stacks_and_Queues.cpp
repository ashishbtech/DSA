#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void explainStack() {
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        
        cout << "Stack Top: " << st.top() << endl; // Prints 3
        st.pop(); // Removes 3
        cout << "Stack Top after pop: " << st.top() << endl; // Prints 2
    }

    void explainQueue() {
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        
        cout << "Queue Front: " << q.front() << endl; // Prints 1
        q.pop(); // Removes 1
        cout << "Queue Front after pop: " << q.front() << endl; // Prints 2
    }
};

int main() {
    Solution obj;
    cout << "--- Stacks ---" << endl;
    obj.explainStack();
    cout << "\n--- Queues ---" << endl;
    obj.explainQueue();
    return 0;
}