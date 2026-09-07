#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int topIndex;
    int capacity;

public:
    // Constructor to initialize the stack
    Stack(int size = 1000)
    {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push an element to the top of the stack
    // Time Complexity: O(1) | Space Complexity: O(1)
    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    // Remove and return the top element
    // Time Complexity: O(1) | Space Complexity: O(1)
    int pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        int x = arr[topIndex];
        topIndex--;
        return x;
    }

    // Return the top element without removing it
    // Time Complexity: O(1) | Space Complexity: O(1)
    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Return the current number of elements in the stack
    // Time Complexity: O(1) | Space Complexity: O(1)
    int size()
    {
        return topIndex + 1;
    }

    // Check if the stack is empty
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool isEmpty()
    {
        return topIndex == -1;
    }
};

int main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << "\n";
    cout << st.top() << "\n";
    cout << st.size() << "\n";
    cout << st.isEmpty() << "\n";

    return 0;
}