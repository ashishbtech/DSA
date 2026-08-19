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

    // OPTIMAL: Adjacent Block Skipping
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *removeDuplicatesOptimal(Node *head)
    {
        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            Node *nextNode = temp->next;

            while (nextNode != nullptr && nextNode->data == temp->data)
            {
                Node *duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }

            temp->next = nextNode;

            if (nextNode != nullptr)
            {
                nextNode->prev = temp;
            }

            temp = temp->next;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 1, 1, 2, 3, 3, 4};
    vector<int> arr2 = {2, 2, 2, 2};

    Node *head1 = obj.convertArrToDLL(arr1);
    cout << "Original List 1 : ";
    obj.printLL(head1);
    head1 = obj.removeDuplicatesOptimal(head1);
    cout << "After Removal   : ";
    obj.printLL(head1);

    cout << "\n";

    Node *head2 = obj.convertArrToDLL(arr2);
    cout << "Original List 2 : ";
    obj.printLL(head2);
    head2 = obj.removeDuplicatesOptimal(head2);
    cout << "After Removal   : ";
    obj.printLL(head2);

    return 0;
}