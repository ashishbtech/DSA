#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

class Solution
{
private:
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

public:
    Node *convertArrToLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            mover->next = new Node(arr[i]);
            mover = mover->next;
        }
        return head;
    }

    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // 1. BRUTE FORCE: Extract values to an array
    // Time Complexity: O(N) | Space Complexity: O(N)
    bool isPalindromeBrute(Node *head)
    {
        vector<int> values;
        Node *temp = head;

        while (temp != nullptr)
        {
            values.push_back(temp->data);
            temp = temp->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right)
        {
            if (values[left] != values[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    // 1.5 BRUTE FORCE ALTERNATIVE: Using a Stack (LIFO)
    // Time Complexity: O(2N) | Space Complexity: O(N)
    bool isPalindromeStackBrute(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        stack<int> st;
        Node *temp = head;

        while (temp != nullptr)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr)
        {

            if (temp->data != st.top())
            {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }

    // 2. OPTIMAL: Find middle, reverse second half, compare, and restore
    // Time Complexity: O(N) | Space Complexity: O(1)
    bool isPalindromeOptimal(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalfHead = reverseList(slow->next);

        Node *first = head;
        Node *second = secondHalfHead;
        bool isPalindrome = true;

        while (second != nullptr)
        {
            if (first->data != second->data)
            {
                isPalindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        slow->next = reverseList(secondHalfHead);

        return isPalindrome;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 2, 1};
    vector<int> arr2 = {1, 2, 3, 4, 5};

    Node *list1 = obj.convertArrToLL(arr1);
    Node *list2 = obj.convertArrToLL(arr2);

    cout << "List 1: ";
    obj.printLL(list1);
    cout << "Is Palindrome? " << (obj.isPalindromeStackBrute(list1) ? "True" : "False") << "\n\n";

    cout << "List 2: ";
    obj.printLL(list2);
    cout << "Is Palindrome? " << (obj.isPalindromeOptimal(list2) ? "True" : "False") << "\n";

    return 0;
}