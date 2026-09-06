#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: XOR and Bit Masking (Bucketing)
    // Time Complexity: O(N) | Space Complexity: O(1)
    vector<int> twoOddNum(vector<int> &arr)
    {
        long long xorResult = 0;

        // Step 1: XOR all numbers to get A ^ B
        for (int i = 0; i < arr.size(); i++)
        {
            xorResult = xorResult ^ arr[i];
        }

        // Step 2: Find the rightmost set bit mask
        long long rightmostSetBit = (xorResult & (xorResult - 1)) ^ xorResult;

        int bucket1 = 0;
        int bucket2 = 0;

        // Step 3: Divide numbers into two buckets and XOR them
        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[i] & rightmostSetBit) != 0)
            {
                // The bit is set (1)
                bucket1 ^= arr[i];
            }
            else
            {
                // The bit is not set (0)
                bucket2 ^= arr[i];
            }
        }

        // output in descending order
        if (bucket1 < bucket2)
        {
            swap(bucket1, bucket2);
        }

        return {bucket1, bucket2};
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4, 2, 4, 5, 2, 3};

    vector<int> ans = obj.twoOddNum(arr);

    cout << "The two odd occurring numbers are: " << ans[0] << " and " << ans[1] << "\n";

    return 0;
}