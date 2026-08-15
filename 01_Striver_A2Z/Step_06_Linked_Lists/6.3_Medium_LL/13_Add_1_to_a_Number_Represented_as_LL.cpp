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

    int addHelper(Node *temp)
    {

        if (temp == nullptr)
            return 1;

        int carry = addHelper(temp->next);

        int sum = temp->data + carry;
        temp->data = sum % 10;

        return sum / 10;
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

    // 1. ITERATIVE: Reverse, Add, Reverse
    // Time Complexity: O(3N) | Space Complexity: O(1)
    Node *addOneIterative(Node *head)
    {
        head = reverseList(head);

        Node *temp = head;
        int carry = 1;

        while (temp != nullptr)
        {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;

            if (carry == 0)
                break; // Optimization: stop early if no carry

            // If we are at the tail and still have a carry, append a new node
            if (temp->next == nullptr && carry == 1)
            {
                temp->next = new Node(1);
                carry = 0;
                break;
            }
            temp = temp->next;
        }

        return reverseList(head);
    }

    // 2. OPTIMAL: Recursive Backtracking
    // Time Complexity: O(N) | Space Complexity: O(N) due to call stack
    Node *addOneRecursive(Node *head)
    {
        int carry = addHelper(head);

        // If there's an overflow out of the most significant digit (e.g. 999 -> 1000)
        if (carry == 1)
        {
            Node *newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 5, 9};
    vector<int> arr2 = {9, 9, 9};

    Node *head1 = obj.convertArrToLL(arr1);
    cout << "Original 1 : ";
    obj.printLL(head1);
    head1 = obj.addOneRecursive(head1);
    cout << "Add 1      : ";
    obj.printLL(head1);
    cout << "\n";

    // Test Case 2
    Node *head2 = obj.convertArrToLL(arr2);
    cout << "Original 2 : ";
    obj.printLL(head2);
    head2 = obj.addOneRecursive(head2);
    cout << "Add 1      : ";
    obj.printLL(head2);

    return 0;
}