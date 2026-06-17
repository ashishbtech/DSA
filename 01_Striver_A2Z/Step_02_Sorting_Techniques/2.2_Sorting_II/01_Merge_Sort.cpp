// Logic: Divide the array into two halves until single elements remain, then merge them back together in sorted order.
// Time Complexity: O(N \log N), Space Complexity: O(N) due to the temporary array.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Compare and merge two halves
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Transfer sorted elements back to original array
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

public:
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return; // Base case
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);      // Sort left half
        mergeSort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);    // Merge them
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int n = arr.size();

    obj.mergeSort(arr, 0, n - 1);

    cout << "Merge Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}