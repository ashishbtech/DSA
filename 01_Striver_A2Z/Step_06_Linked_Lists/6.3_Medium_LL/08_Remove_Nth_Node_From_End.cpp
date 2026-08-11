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

    // 1. BRUTE FORCE: Two Passes (Count length, then delete)
    // Time Complexity: O(2N) | Space Complexity: O(1)
    Node *removeNthFromEndBrute(Node *head, int n)
    {
        if (head == nullptr)
            return nullptr;

        // Pass 1: Count length
        int L = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            L++;
            temp = temp->next;
        }

        if (L == n)
        {
            Node *newHead = head->next;
            delete head;
            return newHead;
        }

        int res = L - n;
        temp = head;
        while (temp != nullptr)
        {
            res--;
            if (res == 0)
            {
                break;
            }
            temp = temp->next;
        }

        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }

    // 2. OPTIMAL: One Pass using Fast and Slow Pointers
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *removeNthFromEndOptimal(Node *head, int n)
    {
        Node *fast = head;
        Node *slow = head;

        // Step 1: Move fast pointer N steps ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // If fast falls off the edge, N was exactly the length of the list (delete head)
        if (fast == nullptr)
        {
            Node *newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 2: Move both pointers until fast is at the last node
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: slow is now pointing to the node right before the target
        Node *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2};

    Node *head1 = obj.convertArrToLL(arr1);
    cout << "Original List 1       : ";
    obj.printLL(head1);
    head1 = obj.removeNthFromEndOptimal(head1, 2);
    cout << "After Removing 2nd End: ";
    obj.printLL(head1);

    cout << "\n";

    // Edge case: Remove head
    Node *head2 = obj.convertArrToLL(arr2);
    cout << "Original List 2       : ";
    obj.printLL(head2);
    head2 = obj.removeNthFromEndOptimal(head2, 2);
    cout << "After Removing 2nd End: ";
    obj.printLL(head2);

    return 0;
}