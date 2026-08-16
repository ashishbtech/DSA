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

    // OPTIMAL: Node-by-Node Grade School Addition
    // Time Complexity: O(max(N, M)) | Space Complexity: O(max(N, M)) for the new list
    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        // Stack-allocated dummy node to anchor the result list
        Node dummy(-1);
        Node *temp = &dummy;

        int carry = 0;

        // Loop while there are nodes left in EITHER list, OR a carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;

            // Add l1's value if it exists
            if (l1 != nullptr)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            // Add l2's value if it exists
            if (l2 != nullptr)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            // Calculate the digit to place in the new node (sum % 10)
            // Calculate the carry for the next iteration (sum / 10)
            Node *newNode = new Node(sum % 10);
            carry = sum / 10;

            // Attach the new node to our result chain
            temp->next = newNode;
            temp = temp->next;
        }

        // Return the actual head of the resulting list
        return dummy.next;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    Node *l1 = obj.convertArrToLL(arr1);
    Node *l2 = obj.convertArrToLL(arr2);

    cout << "List 1 (342) : ";
    obj.printLL(l1);
    cout << "List 2 (465) : ";
    obj.printLL(l2);

    Node *result = obj.addTwoNumbers(l1, l2);

    cout << "Result (807) : ";
    obj.printLL(result);

    return 0;
}
