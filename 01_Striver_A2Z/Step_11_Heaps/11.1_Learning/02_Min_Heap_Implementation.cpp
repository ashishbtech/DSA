#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Simulating Min Heap with a Vector
// Time Complexity: O(N) per pop | Space Complexity: O(N)
class MinHeapBrute
{
private:
    vector<int> arr;

public:
    void push(int val)
    {
        arr.push_back(val);
    }

    void pop()
    {
        if (arr.empty())
            return;
        int minIdx = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[minIdx])
            {
                minIdx = i;
            }
        }
        arr.erase(arr.begin() + minIdx);
    }

    int top()
    {
        if (arr.empty())
            return -1;
        int minVal = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            minVal = min(minVal, arr[i]);
        }
        return minVal;
    }
};

// OPTIMAL: Simulating Priority Queue using a Min Binary Heap
// Time Complexity: O(log N) per operation | Space Complexity: O(N) auxiliary
class MinHeapOptimal
{
private:
    vector<int> heap;

    // Restore the min-heap property from bottom to top
    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;

        // Swim up if the current node is SMALLER than its parent
        while (index > 0 && heap[index] < heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Restore the min-heap property from top to bottom
    void heapifyDown(int index)
    {
        int size = heap.size();

        while (true)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            // Check if left child is smaller than current smallest
            if (leftChild < size && heap[leftChild] < heap[smallest])
            {
                smallest = leftChild;
            }

            // Check if right child is smaller than current smallest
            if (rightChild < size && heap[rightChild] < heap[smallest])
            {
                smallest = rightChild;
            }

            // If the parent is no longer the smallest, swap and continue sinking
            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            return;

        // Swap root with the last element and remove it
        heap[0] = heap.back();
        heap.pop_back();

        // Sink the new root down to its correct position
        if (!heap.empty())
        {
            heapifyDown(0);
        }
    }

    int top()
    {
        if (heap.empty())
            return -1;
        // The minimum element is safely sitting at the root
        return heap[0];
    }
};

int main()
{
    cout << "Testing Optimal Min Heap:\n";
    MinHeapOptimal pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Top element: " << pq.top() << "\n";

    cout << "Popping top element...\n";
    pq.pop();

    cout << "New top element: " << pq.top() << "\n";

    return 0;
}