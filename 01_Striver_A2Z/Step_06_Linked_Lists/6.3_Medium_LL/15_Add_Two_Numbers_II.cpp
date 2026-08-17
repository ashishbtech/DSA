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

    // OPTIMAL: Stack-based addition (Without reversing input lists)
    // Time Complexity: O(N + M) | Space Complexity: O(N + M) for stacks
    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        stack<int> s1, s2;

        // Step 1: Push all values of list 1 into stack 1
        Node *temp1 = l1;
        while (temp1 != nullptr)
        {
            s1.push(temp1->data);
            temp1 = temp1->next;
        }

        // Step 2: Push all values of list 2 into stack 2
        Node *temp2 = l2;
        while (temp2 != nullptr)
        {
            s2.push(temp2->data);
            temp2 = temp2->next;
        }

        Node *head = nullptr;
        int carry = 0;

        // Step 3: Pop and add until both stacks are empty and no carry remains
        while (!s1.empty() || !s2.empty() || carry != 0)
        {
            int sum = carry;

            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            Node *newNode = new Node(sum % 10);

            newNode->next = head;
            head = newNode;

            // Calculate carry for the next iteration
            carry = sum / 10;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {7, 2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    Node *l1 = obj.convertArrToLL(arr1);
    Node *l2 = obj.convertArrToLL(arr2);

    cout << "List 1 (7243) : ";
    obj.printLL(l1);
    cout << "List 2 (564)  : ";
    obj.printLL(l2);

    Node *result = obj.addTwoNumbers(l1, l2);

    cout << "Result (7807) : ";
    obj.printLL(result);

    return 0;
}