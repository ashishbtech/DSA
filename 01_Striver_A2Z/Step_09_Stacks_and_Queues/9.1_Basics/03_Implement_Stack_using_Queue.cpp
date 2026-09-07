#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    // OPTIMAL: Rotate the queue upon insertion
    // Time Complexity: O(N) | Space Complexity: O(N) for storing elements
    void push(int x)
    {
        int s = q.size();
        q.push(x);

        // Re-push all previous elements to the back of the queue
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Time Complexity: O(1)
    int pop()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    // Time Complexity: O(1)
    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    // Time Complexity: O(1)
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << "\n";
    cout << st.top() << "\n";
    cout << st.empty() << "\n";

    return 0;
}