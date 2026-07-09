#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE (Space Optimized): Simulate the merge using two pointers
    // Time Complexity: O(N1 + N2) | Space Complexity: O(1)
    double findMedianBrute(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;

        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        int count = 0;
        int ind1el = -1, ind2el = -1;

        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                if (count == ind1)
                    ind1el = a[i];
                if (count == ind2)
                    ind2el = a[i];
                count++;
                i++;
            }
            else
            {
                if (count == ind1)
                    ind1el = b[j];
                if (count == ind2)
                    ind2el = b[j];
                count++;
                j++;
            }
        }

        while (i < n1)
        {
            if (count == ind1)
                ind1el = a[i];
            if (count == ind2)
                ind2el = a[i];
            count++;
            i++;
        }

        while (j < n2)
        {
            if (count == ind1)
                ind1el = b[j];
            if (count == ind2)
                ind2el = b[j];
            count++;
            j++;
        }

        if (n % 2 == 1)
        {
            return (double)ind2el;
        }
        return (double)((double)(ind1el + ind2el)) / 2.0;
    }

    // 2. OPTIMAL: Binary Search on the smaller array to find the partition
    // Time Complexity: O(log(min(N1, N2))) | Space Complexity: O(1)
    double findMedianOptimal(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();

        if (n1 > n2)
            return findMedianOptimal(b, a);

        int n = n1 + n2;

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {1, 3, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};

    cout << "Brute Force : " << obj.findMedianBrute(a, b) << "\n";
    cout << "Optimal     : " << obj.findMedianOptimal(a, b) << "\n";

    return 0;
}