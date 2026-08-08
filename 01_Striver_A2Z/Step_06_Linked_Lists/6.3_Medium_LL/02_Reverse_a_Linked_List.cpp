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

    // 1. BRUTE FORCE: Data replacement via Stack
    // Time Complexity: O(2N) | Space Complexity: O(N)
    Node *reverseListBrute(Node *head)
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

    // 2. OPTIMAL ITERATIVE: In-place pointer reversal
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *reverseListIterative(Node *head)
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

    // 3. OPTIMAL RECURSIVE: Backtracking pointer reversal
    // Time Complexity: O(N) | Space Complexity: O(N) for call stack
    Node *reverseListRecursive(Node *head)
    {

        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *newHead = reverseListRecursive(head->next);

        Node *front = head->next;
        front->next = head;

        head->next = nullptr;

        return newHead;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = obj.convertArrToLL(arr);
    cout << "Original List : ";
    obj.printLL(head);

    head = obj.reverseListIterative(head);
    cout << "Iterative Rev : ";
    obj.printLL(head);

    head = obj.reverseListRecursive(head);
    cout << "Recursive Rev : ";
    obj.printLL(head);

    return 0;
}