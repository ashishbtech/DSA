#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper Function: Inserts an element into its correct position in a SORTED stack
    void insertSorted(stack<int> &s, int elem)
    {
        // Base Case: If stack is empty, or the element belongs at the very top
        if (s.empty() || elem > s.top())
        {
            s.push(elem);
            return;
        }

        // The element is smaller than the top, so we must move the top out of the way
        int topVal = s.top();
        s.pop();

        // Recursively try to insert the element in the remaining stack
        insertSorted(s, elem);

        // Put the larger element back on top where it belongs
        s.push(topVal);
    }

public:
    // OPTIMAL: Pure Recursion
    // Time Complexity: O(N^2) worst case | Space Complexity: O(N) for Call Stack
    void sortStackOptimal(stack<int> &s)
    {
        // Base Case: An empty stack is already sorted
        if (s.empty())
        {
            return;
        }

        // Step 1: Strip the top element off and hold it in the call stack
        int topVal = s.top();
        s.pop();

        // Step 2: Recursively sort the rest of the stack
        sortStackOptimal(s);

        // Step 3: Insert the held element back into the newly sorted stack
        insertSorted(s, topVal);
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
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original Stack (Top to Bottom): ";
    obj.printStack(s);

    obj.sortStackOptimal(s);

    cout << "Sorted Stack   (Top to Bottom): ";
    obj.printStack(s);

    return 0;
}