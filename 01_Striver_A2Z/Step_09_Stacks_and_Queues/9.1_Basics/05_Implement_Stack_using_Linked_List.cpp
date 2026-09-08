#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *topNode;
    int currentSize;

public:
    Stack()
    {
        topNode = nullptr;
        currentSize = 0;
    }

    // Push an element onto the stack
    // Time Complexity: O(1) | Space Complexity: O(1) (per operation)
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        currentSize++;
    }

    // Remove the top element and return it
    // Time Complexity: O(1) | Space Complexity: O(1)
    int pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        int poppedData = topNode->data;
        Node *temp = topNode;

        topNode = topNode->next;
        delete temp; // Free memory to prevent memory leaks

        currentSize--;
        return poppedData;
    }

    // Return the top element
    // Time Complexity: O(1)
    int top()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Return the size of the stack
    // Time Complexity: O(1)
    int size()
    {
        return currentSize;
    }

    // Check if the stack is empty
    // Time Complexity: O(1)
    bool isEmpty()
    {
        return topNode == nullptr;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << "\n";
    cout << st.top() << "\n";
    cout << st.size() << "\n";
    cout << st.isEmpty() << "\n";

    return 0;
}