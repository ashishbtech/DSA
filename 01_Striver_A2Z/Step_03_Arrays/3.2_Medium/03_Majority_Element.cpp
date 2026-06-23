#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // 1. BRUTE: Check count of every element manually
    // Time: O(N^2) | Space: O(1)
    int majorityBrute(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                    cnt++;
            }
            if (cnt > n / 2)
                return arr[i];
        }
        return -1;
    }

    // 2. BETTER: Hash frequency
    // Time: O(N) | Space: O(N)
    int majorityBetter(vector<int> &arr)
    {
        unordered_map<int, int> mpp;
        int n = arr.size();
        for (int num : arr)
        {
            mpp[num]++;
            if (mpp[num] > n / 2)
                return num;
        }
        return -1;
    }

    // 3. OPTIMAL: Boyer-Moore Voting Algorithm
    // Time: O(N) | Space: O(1)
    int majorityOptimal(vector<int> &arr)
    {
        int cnt = 0;
        int el = 0;

        for (int num : arr)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = num;
            }
            else if (num == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return el;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    cout << "Brute   : " << obj.majorityBrute(arr) << "\n";
    cout << "Better  : " << obj.majorityBetter(arr) << "\n";
    cout << "Optimal : " << obj.majorityOptimal(arr) << "\n";

    return 0;
}