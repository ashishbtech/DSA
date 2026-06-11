#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Reverse Array using Recursion (Single Pointer)
    void reverseArray(int i, vector<int> &arr)
    {
        int n = arr.size();
        if (i >= n / 2)
            return; // Base Case: crossed the middle

        swap(arr[i], arr[n - i - 1]);
        reverseArray(i + 1, arr);
    }

    // Check Palindrome using Recursion
    bool isPalindrome(int i, string &s)
    {
        int n = s.length();
        if (i >= n / 2)
            return true; // Checked entire string successfully

        if (s[i] != s[n - i - 1])
            return false;

        return isPalindrome(i + 1, s);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5};
    obj.reverseArray(0, arr);
    cout << "Reversed Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    string s = "MADAM";
    cout << "Is '" << s << "' Palindrome? " << (obj.isPalindrome(0, s) ? "Yes" : "No") << endl;

    return 0;
}