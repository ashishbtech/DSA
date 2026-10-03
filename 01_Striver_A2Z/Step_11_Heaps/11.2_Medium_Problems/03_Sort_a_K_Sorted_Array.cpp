#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Ignore K and sort normally
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    void sortKSortedBrute(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
    }

    // OPTIMAL: Min Heap sliding window
    // Time Complexity: O(N log K) | Space Complexity: O(K)
    void sortKSortedOptimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        // Priority queue acts as our Min Heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int insertIndex = 0;

        // 1. Push the first K + 1 elements into the Min Heap
        // We use min(n, k + 1) to avoid out of bounds if k >= n
        for (int i = 0; i < min(n, k + 1); i++)
        {
            minHeap.push(arr[i]);
        }

        // 2. Process the remaining elements
        for (int i = k + 1; i < n; i++)
        {
            // The top of the heap is guaranteed to be the next smallest element
            arr[insertIndex++] = minHeap.top();
            minHeap.pop();

            // Push the new element into the window
            minHeap.push(arr[i]);
        }

        // 3. Empty the remaining elements from the heap
        while (!minHeap.empty())
        {
            arr[insertIndex++] = minHeap.top();
            minHeap.pop();
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

    vector<int> arr1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;
    cout << "Array: [6, 5, 3, 2, 8, 10, 9] | K = 3\n";

    vector<int> bruteArr = arr1;
    obj.sortKSortedBrute(bruteArr);
    cout << "Brute Force: ";
    printArray(bruteArr);

    vector<int> optimalArr = arr1;
    obj.sortKSortedOptimal(optimalArr, k1);
    cout << "Optimal:     ";
    printArray(optimalArr);

    cout << "---\n";

    vector<int> arr2 = {10, 9, 8, 7, 4, 70, 60, 50};
    int k2 = 4;
    cout << "Array: [10, 9, 8, 7, 4, 70, 60, 50] | K = 4\n";
    obj.sortKSortedOptimal(arr2, k2);
    cout << "Optimal:     ";
    printArray(arr2);

    return 0;
}