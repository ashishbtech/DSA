#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper to merge two sorted halves and count cross-inversions
    long long merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long cnt = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                cnt += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    // Helper to break down the array and accumulate counts
    long long mergeSort(vector<int> &arr, int low, int high)
    {
        long long cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }

public:
    // 1. BRUTE FORCE: Nested loops checking every pair
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    long long countInversionsBrute(vector<int> &arr)
    {
        int n = arr.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                    cnt++;
            }
        }
        return cnt;
    }

    // 2. OPTIMAL: Modified Merge Sort
    // Time Complexity: O(N log N) | Space Complexity: O(N) auxiliary array
    long long countInversionsOptimal(vector<int> &arr)
    {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {5, 3, 2, 4, 1};

    vector<int> b_arr = arr;
    cout << "1. Brute Force : " << obj.countInversionsBrute(b_arr) << " inversions (O(N^2))\n";

    vector<int> o_arr = arr;
    cout << "2. Optimal     : " << obj.countInversionsOptimal(o_arr) << " inversions (O(N log N))\n";

    return 0;
}