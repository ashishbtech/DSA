#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to sink a node down to maintain Max Heap property
    void heapifyDown(vector<int> &arr, int n, int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapifyDown(arr, n, largest);
        }
    }

public:
    // BRUTE FORCE: Treat array as empty and push elements one by one (Heapify Up)
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    void convertMaxHeapBrute(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int current = i;
            int parent = (current - 1) / 2;

            while (current > 0 && arr[current] > arr[parent])
            {
                swap(arr[current], arr[parent]);
                current = parent;
                parent = (current - 1) / 2;
            }
        }
    }

    // OPTIMAL: Floyd's Build Heap Algorithm (Heapify Down from bottom non-leaves)
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    void convertMaxHeapOptimal(vector<int> &arr)
    {
        int n = arr.size();

        // Start from the last non-leaf node and move backwards to the root
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapifyDown(arr, n, i);
        }
    }
};

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    Solution obj;

    vector<int> arr1 = {3, 4, 8, 11, 13, 10, 9};
    cout << "Original Min Heap: ";
    printArray(arr1);

    vector<int> arrBrute = arr1;
    obj.convertMaxHeapBrute(arrBrute);
    cout << "Max Heap (Brute Force): ";
    printArray(arrBrute);

    obj.convertMaxHeapOptimal(arr1);
    cout << "Max Heap (Optimal): ";
    printArray(arr1);

    return 0;
}