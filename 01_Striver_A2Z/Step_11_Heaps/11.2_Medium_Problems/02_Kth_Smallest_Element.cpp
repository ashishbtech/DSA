#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Sort the array ascending
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    int kthSmallestBrute(vector<int> &arr, int k)
    {
        // Sort in ascending order
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    // BETTER: Min Heap of size N
    // Time Complexity: O(N + K log N) | Space Complexity: O(N)
    int kthSmallestBetter(vector<int> &arr, int k)
    {

        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        for (int i = 0; i < k - 1; i++)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }

    // OPTIMAL: Max Heap restricted to size K
    // Time Complexity: O(N log K) | Space Complexity: O(K)
    int kthSmallestOptimal(vector<int> &arr, int k)
    {

        priority_queue<int> maxHeap;

        for (int num : arr)
        {
            maxHeap.push(num);

            // If the VIP list exceeds K, kick out the largest element
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        // The Kth smallest element is at the top of the K-sized Max Heap
        return maxHeap.top();
    }
};

int main()
{
    Solution obj;

    vector<int> arr1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    cout << "Array: [7, 10, 4, 3, 20, 15] | K = 3\n";
    cout << "Brute Force: " << obj.kthSmallestBrute(arr1, k1) << "\n";
    cout << "Optimal: " << obj.kthSmallestOptimal(arr1, k1) << "\n";

    cout << "---\n";

    vector<int> arr2 = {7, 10, 4, 20, 15};
    int k2 = 4;
    cout << "Array: [7, 10, 4, 20, 15] | K = 4\n";
    cout << "Optimal: " << obj.kthSmallestOptimal(arr2, k2) << "\n";

    return 0;
}