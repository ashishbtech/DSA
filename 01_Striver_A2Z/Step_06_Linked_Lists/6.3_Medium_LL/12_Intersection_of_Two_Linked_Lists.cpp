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
    // 1. BETTER APPROACH: Store nodes of List A in a Hash Set
    // Time Complexity: O(N + M) | Space Complexity: O(N)
    Node *getIntersectionNodeHashing(Node *headA, Node *headB)
    {
        unordered_set<Node *> visitedNodes;

        Node *tempA = headA;

        while (tempA != nullptr)
        {
            visitedNodes.insert(tempA);
            tempA = tempA->next;
        }

        Node *tempB = headB;

        while (tempB != nullptr)
        {
            if (visitedNodes.find(tempB) != visitedNodes.end())
            {
                return tempB;
            }
            tempB = tempB->next;
        }

        return nullptr;
    }

    // 2. OPTIMAL APPROACH: The Magic Pointer Swap
    // Time Complexity: O(N + M) | Space Complexity: O(1)
    Node *getIntersectionNodeOptimal(Node *headA, Node *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        Node *tempA = headA;
        Node *tempB = headB;

        while (tempA != tempB)
        {

            if (tempA == nullptr)
            {
                tempA = headB;
            }
            else
            {
                tempA = tempA->next;
            }

            if (tempB == nullptr)
            {
                tempB = headA;
            }
            else
            {
                tempB = tempB->next;
            }
        }

        return tempA;
    }
};

int main()
{
    Solution obj;

    Node *intersection = new Node(7, new Node(8));

    Node *headA = new Node(1, new Node(2, new Node(3, intersection)));
    Node *headB = new Node(4, new Node(5, intersection));

    Node *ans = obj.getIntersectionNodeOptimal(headA, headB);

    if (ans != nullptr)
    {
        cout << "Intersection found at node with data: " << ans->data << "\n";
    }
    else
    {
        cout << "No intersection found.\n";
    }

    return 0;
}