#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // OPTIMAL: XOR all elements
    // Time Complexity: O(N) | Space Complexity: O(1)
    int singleNumber(vector<int> &nums)
    {
        int xorResult = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            xorResult = xorResult ^ nums[i];
        }

        return xorResult;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};

    cout << "The single number in {2, 2, 1} is: " << obj.singleNumber(nums1) << "\n";
    cout << "The single number in {4, 1, 2, 1, 2} is: " << obj.singleNumber(nums2) << "\n";

    return 0;
}