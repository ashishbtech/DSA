#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Simulating Priority Queue with a Vector
// Time Complexity: O(N) per pop | Space Complexity: O(N)
class PriorityQueueBrute
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
        int maxIdx = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[maxIdx])
            {
                maxIdx = i;
            }
        }
        arr.erase(arr.begin() + maxIdx);
    }

    int top()
    {
        if (arr.empty())
            return -1;
        int maxVal = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            maxVal = max(maxVal, arr[i]);
        }
        return maxVal;
    }
};

// OPTIMAL: Simulating Priority Queue using a Max Binary Heap
// Time Complexity: O(log N) per operation | Space Complexity: O(N)
class PriorityQueueOptimal
{
private:
    vector<int> heap;

    // Restore the max-heap property from bottom to top
    void heapifyUp(int index)
    {
        int parent = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parent])
        {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Restore the max-heap property from top to bottom
    void heapifyDown(int index)
    {
        int size = heap.size();

        while (true)
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            // Check if left child is larger than current largest
            if (leftChild < size && heap[leftChild] > heap[largest])
            {
                largest = leftChild;
            }

            // Check if right child is larger than current largest
            if (rightChild < size && heap[rightChild] > heap[largest])
            {
                largest = rightChild;
            }

            // If the parent is no longer the largest, swap and continue sinking
            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                // The heap property is satisfied
                break;
            }
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        // Fix the tree by swimming the new element up
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            return;

        // Swap the root (max element) with the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Fix the tree by sinking the new root down
        if (!heap.empty())
        {
            heapifyDown(0);
        }
    }

    int top()
    {
        if (heap.empty())
            return -1;
        // The maximum element is always safely sitting at the root
        return heap[0];
    }
};

int main()
{
    cout << "Testing Optimal Priority Queue (Max Heap):\n";
    PriorityQueueOptimal pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Top element: " << pq.top() << "\n"; // Expected: 40

    cout << "Popping top element...\n";
    pq.pop();

    cout << "New top element: " << pq.top() << "\n"; // Expected: 30

    return 0;
}