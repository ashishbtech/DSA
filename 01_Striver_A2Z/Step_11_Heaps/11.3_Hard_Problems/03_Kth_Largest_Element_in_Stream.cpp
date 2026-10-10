#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH (For conceptual understanding, will TLE on large streams)
class KthLargestBrute
{
private:
    int k;
    vector<int> stream;

public:
    KthLargestBrute(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            stream.push_back(num);
        }
    }

    // Time Complexity: O(N log N) per call
    int add(int val)
    {
        stream.push_back(val);
        // Sort descending
        sort(stream.begin(), stream.end(), greater<int>());
        return stream[k - 1];
    }
};

// OPTIMAL APPROACH: Min Heap of size K
class KthLargestOptimal
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Time Complexity: O(N log K) for initialization
    KthLargestOptimal(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop(); // Evict the smallest element
            }
        }
    }

    // Time Complexity: O(log K) per call
    int add(int val)
    {
        minHeap.push(val);

        // If we exceed K elements, kick out the smallest
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }

        // The Kth largest is sitting at the top of the Min Heap
        return minHeap.top();
    }
};

int main()
{
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};

    cout << "Initializing stream with K = 3, nums = [4, 5, 8, 2]\n";
    KthLargestOptimal kthLargest(k, nums);

    cout << "Adding 3... Kth largest is: " << kthLargest.add(3) << "\n";

    cout << "Adding 5... Kth largest is: " << kthLargest.add(5) << "\n";

    cout << "Adding 10... Kth largest is: " << kthLargest.add(10) << "\n";

    cout << "Adding 9... Kth largest is: " << kthLargest.add(9) << "\n";

    cout << "Adding 4... Kth largest is: " << kthLargest.add(4) << "\n";

    return 0;
}