#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Array with Insertion Sort logic
class MedianFinderBrute
{
private:
    vector<int> stream;

public:
    MedianFinderBrute() {}

    // Time Complexity: O(N) due to vector insertion shifting elements
    void addNum(int num)
    {
        // Find the correct position to keep the array sorted
        auto it = lower_bound(stream.begin(), stream.end(), num);
        stream.insert(it, num);
    }

    // Time Complexity: O(1)
    double findMedian()
    {
        int n = stream.size();
        if (n % 2 == 1)
        {
            return stream[n / 2];
        }
        else
        {
            return (stream[n / 2 - 1] + stream[n / 2]) / 2.0;
        }
    }
};

// OPTIMAL: Two Heaps (Max Heap for lower half, Min Heap for upper half)
class MedianFinderOptimal
{
private:
    priority_queue<int> maxHeap;                            // Lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Upper half

public:
    MedianFinderOptimal() {}

    // Time Complexity: O(log N)
    void addNum(int num)
    {
        // 1. Push to Max Heap
        maxHeap.push(num);

        // 2. Transfer the largest of the lower half to the upper half
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 3. Balance sizes: Max Heap should always be equal or 1 element larger
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Time Complexity: O(1)
    double findMedian()
    {
        // If odd number of elements, maxHeap has the extra element
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        // If even, the median is the average of the two tops
        else
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

int main()
{
    cout << "Initializing MedianFinder...\n";
    MedianFinderOptimal medianFinder;

    cout << "Adding 1...\n";
    medianFinder.addNum(1);
    cout << "Current Median: " << medianFinder.findMedian() << "\n";

    cout << "Adding 2...\n";
    medianFinder.addNum(2);
    cout << "Current Median: " << medianFinder.findMedian() << "\n";

    cout << "Adding 3...\n";
    medianFinder.addNum(3);
    cout << "Current Median: " << medianFinder.findMedian() << "\n";

    cout << "Adding 0...\n";
    medianFinder.addNum(0);
    cout << "Current Median: " << medianFinder.findMedian() << "\n";

    cout << "Adding 5...\n";
    medianFinder.addNum(5);
    cout << "Current Median: " << medianFinder.findMedian() << "\n";

    return 0;
}