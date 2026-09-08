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

class Queue
{
private:
    Node *front;
    Node *rear;
    int currentSize;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        currentSize = 0;
    }

    // Push an element to the back of the queue
    // Time Complexity: O(1) | Space Complexity: O(1) (per operation)
    void push(int x)
    {
        Node *newNode = new Node(x);
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        currentSize++;
    }

    // Remove and return the front element
    // Time Complexity: O(1) | Space Complexity: O(1)
    int pop()
    {
        if (front == nullptr)
        {
            cout << "Queue Underflow\n";
            return -1;
        }

        int poppedData = front->data;
        Node *temp = front;

        front = front->next;
        delete temp; // Free memory

        // If the queue becomes empty after popping
        if (front == nullptr)
        {
            rear = nullptr;
        }

        currentSize--;
        return poppedData;
    }

    // Return the front element without removing it
    // Time Complexity: O(1)
    int top()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }

    // Return the current number of elements
    // Time Complexity: O(1)
    int size()
    {
        return currentSize;
    }

    // Check if the queue is empty
    // Time Complexity: O(1)
    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << "\n";
    cout << q.top() << "\n";
    cout << q.size() << "\n";
    cout << q.isEmpty() << "\n";

    return 0;
}