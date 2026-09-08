#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {
    }

    // Push element x to the back of queue
    // Time Complexity: O(1)
    void push(int x)
    {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    // Time Complexity: Amortized O(1) | Worst Case O(N)
    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }

    // Get the front element
    // Time Complexity: Amortized O(1)
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Returns whether the queue is empty
    // Time Complexity: O(1)
    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << "\n";
    cout << q.peek() << "\n";
    cout << q.empty() << "\n";

    return 0;
}