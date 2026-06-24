#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution
{
private:
    bool linearSearch(vector<int> &arr, int num)
    {
        for (int x : arr)
        {
            if (x == num)
                return true;
        }
        return false;
    }

public:
    // 1. BRUTE: Pick a number, linearly search for x+1, then x+2...
    // Time Complexity: O(N^2) worst case | Space Complexity: O(1)
    int longestSuccessiveElementsBrute(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            int count = 1;

            while (linearSearch(arr, x + 1))
            {
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
        return longest;
    }

    // 2. BETTER: Sort the array first, then count adjacent stepping stones
    // Time Complexity: O(N log N) | Space Complexity: O(1)
    int longestSuccessiveElementsBetter(vector<int> arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        sort(arr.begin(), arr.end());
        int lastSmaller = INT_MIN;
        int count = 0;
        int longest = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] - 1 == lastSmaller)
            {
                count += 1;
                lastSmaller = arr[i];
            }
            else if (arr[i] != lastSmaller)
            {
                count = 1;
                lastSmaller = arr[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }

    // 3. OPTIMAL: Insert all into a Hash Set. Only start counting if 'num - 1' is missing.
    // Time Complexity: Strictly O(2N) ≈ O(N) | Space Complexity: O(N) for Hash Set
    int longestSuccessiveElementsOptimal(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        int longest = 1;
        unordered_set<int> st;
        for (int num : arr)
        {
            st.insert(num);
        }

        for (auto it : st)
        {

            if (st.find(it - 1) == st.end())
            {
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end())
                {
                    x += 1;
                    count += 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << "Brute   : " << obj.longestSuccessiveElementsBrute(arr) << "\n";
    cout << "Better  : " << obj.longestSuccessiveElementsBetter(arr) << "\n";
    cout << "Optimal : " << obj.longestSuccessiveElementsOptimal(arr) << "\n";

    return 0;
}