// Logic: The missing number can be found via the Sum formula, but the XOR approach is safer because it prevents integer overflow.
//  Finding the number that appears once when all others appear twice is solved optimally in O(N) using the property that X ^ X = 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Optimal XOR approach: O(N) Time, O(1) Space
    int findMissingNumber(vector<int> &arr, int n)
    {
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            xor2 = xor2 ^ arr[i];  // XORing array elements
            xor1 = xor1 ^ (i + 1); // XORing numbers 1 to n-1
        }
        xor1 = xor1 ^ n; // XORing the last number n
        return xor1 ^ xor2;
    }

    int maxConsecutiveOnes(vector<int> &arr)
    {
        int maxCount = 0, currentCount = 0;
        for (int num : arr)
        {
            if (num == 1)
            {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            }
            else
            {
                currentCount = 0;
            }
        }
        return maxCount;
    }

    // XOR property: bits that are the same cancel out
    int getSingleElement(vector<int> &arr)
    {
        int xorr = 0;
        for (int num : arr)
        {
            xorr = xorr ^ num;
        }
        return xorr;
    }
};

int main()
{
    Solution obj;
    vector<int> missingArr = {1, 2, 4, 5}; // n = 5, missing is 3
    cout << "Missing Number: " << obj.findMissingNumber(missingArr, 5) << endl;

    vector<int> consecutiveArr = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << "Max Consecutive Ones: " << obj.maxConsecutiveOnes(consecutiveArr) << endl;

    vector<int> singleArr = {4, 1, 2, 1, 2}; // 4 appears once
    cout << "Single Element: " << obj.getSingleElement(singleArr) << endl;

    return 0;
}