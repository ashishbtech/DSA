#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // BRUTE FORCE: Sort the array
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    int findKthLargestBrute(vector<int> &nums, int k)
    {
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }

    // BETTER: Max Heap of size N
    // Time Complexity: O(N + K log N) | Space Complexity: O(N)
    int findKthLargestBetter(vector<int> &nums, int k)
    {
        // C++ default priority_queue is a Max Heap
        priority_queue<int> maxHeap(nums.begin(), nums.end()); // O(N) build

        // Pop K-1 times to reach the Kth largest
        for (int i = 0; i < k - 1; i++)
        {
            maxHeap.pop();
        }

        return maxHeap.top();
    }

    // OPTIMAL: Min Heap restricted to size K
    // Time Complexity: O(N log K) | Space Complexity: O(K)
    int findKthLargestOptimal(vector<int> &nums, int k)
    {
        // Syntax for a Min Heap in C++
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);

            // If the VIP list exceeds K, kick out the smallest element
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        // The Kth largest element is at the top of the K-sized Min Heap
        return minHeap.top();
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Array: [3, 2, 1, 5, 6, 4] | K = 2\n";
    cout << "Brute Force: " << obj.findKthLargestBrute(nums1, k1) << "\n";
    cout << "Optimal: " << obj.findKthLargestOptimal(nums1, k1) << "\n";

    cout << "---\n";

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Array: [3, 2, 3, 1, 2, 4, 5, 5, 6] | K = 4\n";
    cout << "Optimal: " << obj.findKthLargestOptimal(nums2, k2) << "\n";

    return 0;
}