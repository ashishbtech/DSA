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
    Node *createListWithCycle()
    {
        Node *head = new Node(1);
        Node *node2 = new Node(2);
        Node *node3 = new Node(3);
        Node *node4 = new Node(4);
        Node *node5 = new Node(5);

        head->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;

        node5->next = node3;

        return head;
    }

    // 1. BRUTE FORCE: Store visited nodes and their timestamps
    // Time Complexity: O(N) | Space Complexity: O(N)
    int lengthOfLoopBrute(Node *head)
    {
        unordered_map<Node *, int> visitedTimer;
        Node *temp = head;
        int timer = 1;

        while (temp != nullptr)
        {

            if (visitedTimer.find(temp) != visitedTimer.end())
            {
                return timer - visitedTimer[temp];
            }

            visitedTimer[temp] = timer;
            timer++;
            temp = temp->next;
        }

        return 0;
    }

    // 2. OPTIMAL: Floyd's Algorithm (Hold one pointer, lap the other)
    // Time Complexity: O(N) | Space Complexity: O(1)
    int lengthOfLoopOptimal(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {

                int count = 1;
                fast = fast->next;

                while (fast != slow)
                {
                    count++;
                    fast = fast->next;
                }

                return count;
            }
        }

        return 0;
    }
};

int main()
{
    Solution obj;

    Node *cycleList = obj.createListWithCycle();

    cout << "Brute Force : Loop Length is " << obj.lengthOfLoopBrute(cycleList) << "\n";
    cout << "Optimal     : Loop Length is " << obj.lengthOfLoopOptimal(cycleList) << "\n";

    return 0;
}

