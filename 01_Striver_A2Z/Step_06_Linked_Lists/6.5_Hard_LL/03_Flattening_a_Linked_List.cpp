#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int data1, Node *next1 = nullptr, Node *bottom1 = nullptr)
    {
        data = data1;
        next = next1;
        bottom = bottom1;
    }
};

class Solution
{
private:
    // Helper: Merge two vertically sorted linked lists
    Node *mergeTwoLists(Node *list1, Node *list2)
    {

        Node dummy(-1);
        Node *temp = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data < list2->data)
            {
                temp->bottom = list1;
                temp = list1;
                list1 = list1->bottom;
            }
            else
            {
                temp->bottom = list2;
                temp = list2;
                list2 = list2->bottom;
            }

            temp->next = nullptr;
        }

        if (list1 != nullptr)
        {
            temp->bottom = list1;
        }
        else
        {
            temp->bottom = list2;
        }

        return dummy.bottom;
    }

public:
    // Helper: Print the flattened list using 'bottom' pointers
    void printFlattenedList(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->bottom;
        }
        cout << "NULL\n";
    }

    // OPTIMAL: Recursive Post-Order Merge
    // Time Complexity: O(Total Nodes) | Space Complexity: O(Number of horizontal nodes) for call stack
    Node *flatten(Node *head)
    {
        // Base case: if head is null or we reached the last horizontal node
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Recursively dive to the right-most node
        Node *mergedListFromRight = flatten(head->next);

        // Merge our current vertical list with the incoming sorted list from the right
        head = mergeTwoLists(head, mergedListFromRight);

        // Return the newly merged, fully sorted vertical list up the chain
        return head;
    }
};

int main()
{
    Solution obj;

    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    // Column 2: 10 -> 20
    head->next = new Node(10);
    head->next->bottom = new Node(20);

    // Column 3: 19 -> 22 -> 50
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    // Column 4: 28 -> 35 -> 40
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);

    cout << "Flattening the complex 2D list...\n";
    Node *flattenedHead = obj.flatten(head);

    cout << "Flattened Result: ";
    obj.printFlattenedList(flattenedHead);

    return 0;
}