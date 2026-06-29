#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. BRUTE FORCE: 3 nested loops + a Set to filter out duplicate triplets
    // Time Complexity: O(N^3 * log(no. of unique triplets)) | Space Complexity: O(2 * unique triplets)
    vector<vector<int>> tripletBrute(vector<int> &arr)
    {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp); // Set drops identical vectors automatically
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // 2. BETTER: 2 nested loops + Hash Set to look up the 3rd required number
    // Logic: arr[k] must equal -(arr[i] + arr[j])
    // Time Complexity: O(N^2 * log(unique)) | Space Complexity: O(N) + O(unique)
    vector<vector<int>> tripletBetter(vector<int> &arr)
    {
        int n = arr.size();
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> hashSet;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(arr[i] + arr[j]);

                if (hashSet.find(third) != hashSet.end())
                {
                    vector<int> temp = {arr[i], arr[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(arr[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // 3. OPTIMAL: Sort first, then fix pointer 'i' and Two-Pointer collapse 'j' and 'k'
    // Time Complexity: O(N log N) + O(N^2) ≈ O(N^2) | Space Complexity: O(1) auxiliary
    vector<vector<int>> tripletOptimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            // CHECKPOINT 1: Skip duplicate values for our anchor pointer 'i'
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];

                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;

                    // CHECKPOINT 2: Skip duplicates for left pointer 'j'
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    // CHECKPOINT 3: Skip duplicates for right pointer 'k'
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> r1 = obj.tripletBrute(arr);
    cout << "Brute   : " << r1.size() << " unique triplets found\n";

    vector<vector<int>> r2 = obj.tripletBetter(arr);
    cout << "Better  : " << r2.size() << " unique triplets found\n";

    vector<vector<int>> r3 = obj.tripletOptimal(arr);
    cout << "Optimal :\n";
    for (auto &trip : r3)
    {
        cout << "[ " << trip[0] << ", " << trip[1] << ", " << trip[2] << " ]\n";
    }

    return 0;
}