#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1 = nullptr, Node *prev1 = nullptr)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution
{
public:
    Node *convertArrToDLL(vector<int> &arr)
    {
        if (arr.empty())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *prevNode = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr, prevNode);
            prevNode->next = temp;
            prevNode = temp;
        }
        return head;
    }

    void printLL(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // 1. BRUTE FORCE: Using a Stack to overwrite node data
    // Time Complexity: O(2N) | Space Complexity: O(N) auxiliary
    Node *reverseDLLBrute(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

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
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    // 2. OPTIMAL: In-place pointer swap (No data copying)
    // Time Complexity: O(N) | Space Complexity: O(1) auxiliary
    Node *reverseDLLOptimal(Node *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        Node *current = head;
        Node *lastSwapped = nullptr;

        while (current != nullptr)
        {
            // Swap current's next and prev pointers
            lastSwapped = current->prev;
            current->prev = current->next;
            current->next = lastSwapped;

            // Move to the next node in the original list
            // (Which is now stored in current->prev due to the swap!)
            current = current->prev;
        }

        // After the loop, 'current' is nullptr, and 'lastSwapped' is pointing
        // to the second-to-last node of the original list.
        // Therefore, the new head is lastSwapped->prev.
        return lastSwapped->prev;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {10, 20, 30, 40};

    Node *head1 = obj.convertArrToDLL(arr1);
    cout << "Original DLL (Arr1) : ";
    obj.printLL(head1);
    head1 = obj.reverseDLLBrute(head1);
    cout << "Brute Force Reverse : ";
    obj.printLL(head1);

    cout << "\n";

    Node *head2 = obj.convertArrToDLL(arr2);
    cout << "Original DLL (Arr2) : ";
    obj.printLL(head2);
    head2 = obj.reverseDLLOptimal(head2);
    cout << "Optimal Swap Reverse: ";
    obj.printLL(head2);

    return 0;
}