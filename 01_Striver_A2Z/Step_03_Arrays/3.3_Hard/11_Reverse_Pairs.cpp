#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Standard merge function (no counting in here!)
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    // New helper specifically just for counting the pairs BEFORE we merge
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;
        int cnt = 0;

        for (int left = low; left <= mid; left++)
        {

            while (right <= high && arr[left] > 2LL * arr[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);

        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return cnt;
    }

public:
    // 1. BRUTE FORCE: Nested loops checking every pair
    // Time Complexity: O(N^2) | Space Complexity: O(1)
    int reversePairsBrute(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > 2LL * arr[j])
                    cnt++;
            }
        }
        return cnt;
    }

    // 2. OPTIMAL: Modified Merge Sort (Count then Merge)
    // Time Complexity: O(2N log N) -> O(N log N) | Space Complexity: O(N)
    int reversePairsOptimal(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};

    vector<int> b_arr = arr;
    cout << "1. Brute Force : " << obj.reversePairsBrute(b_arr) << " pairs (O(N^2))\n";

    vector<int> o_arr = arr;
    cout << "2. Optimal     : " << obj.reversePairsOptimal(o_arr) << " pairs (O(N log N))\n";

    return 0;
}