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

    // OPTIMAL: Ring connection and precise severing
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *rotateRightOptimal(Node *head, int k)
    {
        // Edge cases: Empty list, single node, or no rotations
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }

        // Step 1: Find the length and the tail node
        int len = 1;
        Node *tail = head;
        while (tail->next != nullptr)
        {
            len++;
            tail = tail->next;
        }

        // Step 2: Modulo arithmetic to handle k > len
        k = k % len;
        if (k == 0)
            return head;

        // Step 3: Connect tail to head to form a circular list
        tail->next = head;

        // Step 4: Find the node that will be the new tail (len - k)
        Node *newTail = head;
        for (int i = 1; i < len - k; i++)
        {
            newTail = newTail->next;
        }

        // Step 5: Secure the new head and break the circle
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 2;

    vector<int> arr2 = {0, 1, 2};
    int k2 = 4;

    Node *head1 = obj.convertArrToLL(arr1);
    cout << "Original 1 : ";
    obj.printLL(head1);
    head1 = obj.rotateRightOptimal(head1, k1);
    cout << "Rotate k=2 : ";
    obj.printLL(head1);

    cout << "\n";

    Node *head2 = obj.convertArrToLL(arr2);
    cout << "Original 2 : ";
    obj.printLL(head2);
    head2 = obj.rotateRightOptimal(head2, k2);
    cout << "Rotate k=4 : ";
    obj.printLL(head2);

    return 0;
}