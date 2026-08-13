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

    // 1. BRUTE FORCE: Count occurrences and overwrite data
    // Time Complexity: O(2N) | Space Complexity: O(1)
    Node *sort012Brute(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        int count0 = 0, count1 = 0, count2 = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == 0)
                count0++;
            else if (temp->data == 1)
                count1++;
            else
                count2++;
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr)
        {
            if (count0 > 0)
            {
                temp->data = 0;
                count0--;
            }
            else if (count1 > 0)
            {
                temp->data = 1;
                count1--;
            }
            else
            {
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }

        return head;
    }

    // 2. OPTIMAL: Segregate using 3 Dummy Nodes and link them
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *sort012Optimal(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // Create dummy nodes to anchor the three separate chains
        Node zeroHead(-1);
        Node oneHead(-1);
        Node twoHead(-1);

        // Pointers to build the chains
        Node *zero = &zeroHead;
        Node *one = &oneHead;
        Node *two = &twoHead;

        // Step 1: Traverse and segregate nodes based on value
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Step 2: Link the three chains together safely

        // Link the end of the 0s chain to the 1s chain (or 2s chain if there are no 1s)
        zero->next = (oneHead.next != nullptr) ? oneHead.next : twoHead.next;

        // Link the end of the 1s chain to the 2s chain
        one->next = twoHead.next;

        // Terminate the 2s chain to prevent cycles
        two->next = nullptr;

        // Return the actual head of the 0s chain (skipping the dummy)
        return zeroHead.next;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 0, 2, 1, 0, 2, 1};

    Node *head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    head = obj.sort012Optimal(head);

    cout << "Sorted List   : ";
    obj.printLL(head);

    return 0;
}