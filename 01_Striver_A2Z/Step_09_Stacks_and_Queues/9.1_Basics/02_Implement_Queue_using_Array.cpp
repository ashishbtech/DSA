#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int currSize;
    int maxSize;

public:
    // Constructor to initialize the queue
    Queue(int size = 1000)
    {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    // Push an element to the rear of the queue
    // Time Complexity: O(1) | Space Complexity: O(1)
    void push(int x)
    {
        if (currSize == maxSize)
        {
            cout << "Queue Overflow\n";
            return;
        }

        // If queue is empty, initialize pointers
        if (currSize == 0)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            // Circular increment
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = x;
        currSize++;
    }

    // Remove and return the front element
    // Time Complexity: O(1) | Space Complexity: O(1)
    int pop()
    {
        if (currSize == 0)
        {
            cout << "Queue Underflow\n";
            return -1;
        }

        int x = arr[front];

        // If it was the last element, reset pointers
        if (currSize == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // Circular increment
            front = (front + 1) % maxSize;
        }

        currSize--;
        return x;
    }

    // Return the front element without removing it
    // Time Complexity: O(1) | Space Complexity: O(1)
    int top()
    {
        if (currSize == 0)
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Return the current number of elements
    // Time Complexity: O(1) | Space Complexity: O(1)
    int size()
    {
        return currSize;
    }

    // Check if the queue is empty
    // Time Complexity: O(1) | Space Complexity: O(1)
    bool isEmpty()
    {
        return currSize == 0;
    }
};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << "\n";
    cout << q.top() << "\n";
    cout << q.size() << "\n";
    cout << q.isEmpty() << "\n";

    return 0;
}