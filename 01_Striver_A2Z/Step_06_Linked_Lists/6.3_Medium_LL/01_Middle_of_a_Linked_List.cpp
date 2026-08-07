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

    // 1. BRUTE FORCE: Count total nodes, then find the middle
    // Time Complexity: O(N + N/2) | Space Complexity: O(1)
    Node *middleNodeBrute(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        int mid = (count / 2) + 1;
        temp = head;

        while (temp != nullptr)
        {
            mid--;
            if (mid == 0)
            {
                break;
            }
            temp = temp->next;
        }

        return temp;
    }

    // 2. OPTIMAL: Tortoise and Hare (Slow and Fast Pointers)
    // Time Complexity: O(N/2) | Space Complexity: O(1)
    Node *middleNodeOptimal(Node *head)
    {
        // Initialize both pointers at the starting line
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Tortoise takes 1 step
            fast = fast->next->next; // Hare takes 2 steps
        }

        // When the hare finishes, the tortoise is at the middle!
        return slow;
    }
};

int main()
{
    Solution obj;
    vector<int> arrOdd = {1, 2, 3, 4, 5};
    vector<int> arrEven = {1, 2, 3, 4, 5, 6};

    Node *headOdd = obj.convertArrToLL(arrOdd);
    Node *headEven = obj.convertArrToLL(arrEven);

    Node *midOdd = obj.middleNodeBrute(headOdd);
    cout << "Middle of {1, 2, 3, 4, 5}    : " << midOdd->data << "\n";

    Node *midEven = obj.middleNodeOptimal(headEven);
    cout << "Middle of {1, 2, 3, 4, 5, 6} : " << midEven->data << "\n";

    return 0;
}