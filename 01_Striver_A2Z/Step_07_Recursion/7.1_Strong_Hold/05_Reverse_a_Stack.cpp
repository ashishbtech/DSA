#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
     
    void insertAtBottom(stack<int> &s, int elem)
    {
        // Base Case 
        if (s.empty())
        {
            s.push(elem);
            return;
        }

        // Hold the current top element out of the way
        int topVal = s.top();
        s.pop();

         
        insertAtBottom(s, elem);

        // Put the held element back on top
        s.push(topVal);
    }

public:
    // OPTIMAL: Pure Recursion  
    // Time Complexity: O(N^2) | Space Complexity: O(N) for Call Stack
    void reverseStack(stack<int> &s)
    {
        // Base Case 
        if (s.empty())
        {
            return;
        }

        // Step 1: Strip the top element off and hold it in the call stack
        int topVal = s.top();
        s.pop();

        // Step 2: Recursively reverse the remaining stack
        reverseStack(s);

        // Step 3: Insert the held element at the BOTTOM of the newly reversed stack
        insertAtBottom(s, topVal);
    }

    // Helper: Print and empty the stack
    void printStack(stack<int> s)
    {
        if (s.empty())
        {
            cout << "Empty\n";
            return;
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
};

int main()
{
    Solution obj;

     
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    cout << "Original Stack (Top to Bottom): ";
    obj.printStack(s);

    obj.reverseStack(s);

    cout << "Reversed Stack (Top to Bottom): ";
    obj.printStack(s);

    return 0;
}