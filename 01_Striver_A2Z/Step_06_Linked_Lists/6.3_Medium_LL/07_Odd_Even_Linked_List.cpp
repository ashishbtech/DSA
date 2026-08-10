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

    // 1. BRUTE FORCE: Extract values to an array and overwrite
    // Time Complexity: O(N) | Space Complexity: O(N)
    Node *oddEvenListBrute(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> arr;
        Node *temp = head;

        while (temp != nullptr && temp != nullptr)
        {
            arr.push_back(temp->data);
            if (temp->next == nullptr)
                break;
            temp = temp->next->next;
        }

        temp = head->next;
        while (temp != nullptr && temp != nullptr)
        {
            arr.push_back(temp->data);
            if (temp->next == nullptr)
                break;
            temp = temp->next->next;
        }

        temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            temp->data = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }

    // 2. OPTIMAL: In-place pointer cross-wiring
    // Time Complexity: O(N) | Space Complexity: O(1)
    Node *oddEvenListOptimal(Node *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = head->next;

        while (even != nullptr && even->next != nullptr)
        {

            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 1, 3, 5, 6, 4, 7};

    Node *head1 = obj.convertArrToLL(arr1);
    cout << "Original List 1 : ";
    obj.printLL(head1);
    head1 = obj.oddEvenListOptimal(head1);
    cout << "Odd-Even List 1 : ";
    obj.printLL(head1);

    cout << "\n";

    Node *head2 = obj.convertArrToLL(arr2);
    cout << "Original List 2 : ";
    obj.printLL(head2);
    head2 = obj.oddEvenListOptimal(head2);
    cout << "Odd-Even List 2 : ";
    obj.printLL(head2);

    return 0;
}