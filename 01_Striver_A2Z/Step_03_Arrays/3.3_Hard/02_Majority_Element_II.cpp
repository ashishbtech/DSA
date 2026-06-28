#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: Check count of every unique element manually
    // Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
    vector<int> majorityBrute(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            // Check if arr[i] is already picked to avoid duplicates in answer
            if (ans.size() == 0 || ans[0] != arr[i])
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == arr[i])
                        cnt++;
                }
                if (cnt > n / 3)
                    ans.push_back(arr[i]);
            }
            if (ans.size() == 2)
                break; // Math limit: max 2 answers possible
        }
        return ans;
    }

    // 2. BETTER: Hash Map frequency tracking
    // Time Complexity: O(N) | Space Complexity: O(N)
    vector<int> majorityBetter(vector<int> &arr)
    {
        int n = arr.size();
        map<int, int> mpp;
        vector<int> ans;
        int mini = (n / 3) + 1;

        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
            if (mpp[arr[i]] == mini)
            {
                ans.push_back(arr[i]);
            }
            if (ans.size() == 2)
                break;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // 3. OPTIMAL: Extended Boyer-Moore Voting Algorithm (2 Candidates)
    // Time Complexity: O(2N) ≈ O(N) | Space Complexity: O(1)
    vector<int> majorityOptimal(vector<int> &arr)
    {
        int n = arr.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Phase 1: Find up to 2 potential candidates
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && el2 != arr[i])
            {
                cnt1 = 1;
                el1 = arr[i];
            }
            else if (cnt2 == 0 && el1 != arr[i])
            {
                cnt2 = 1;
                el2 = arr[i];
            }
            else if (arr[i] == el1)
            {
                cnt1++;
            }
            else if (arr[i] == el2)
            {
                cnt2++;
            }
            else
            {
                // Current number matches neither candidate -> mutual cancellation
                cnt1--;
                cnt2--;
            }
        }

        // Phase 2: Verify the candidates actually exceed the > N/3 threshold
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int num : arr)
        {
            if (num == el1)
                cnt1++;
            else if (num == el2)
                cnt2++;
        }

        int mini = n / 3 + 1;
        if (cnt1 >= mini)
            ans.push_back(el1);
        if (cnt2 >= mini)
            ans.push_back(el2);

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {11, 33, 33, 11, 33, 11}; // N=6, limit > 2. Ans: [11, 33]

    vector<int> r1 = obj.majorityBrute(arr);
    cout << "1. Brute Output   : [ ";
    for (int x : r1)
        cout << x << " ";
    cout << "]\n";

    vector<int> r2 = obj.majorityBetter(arr);
    cout << "2. Better Output  : [ ";
    for (int x : r2)
        cout << x << " ";
    cout << "]\n";

    vector<int> r3 = obj.majorityOptimal(arr);
    cout << "3. Optimal Output : [ ";
    for (int x : r3)
        cout << x << " ";
    cout << "]\n";

    return 0;
}