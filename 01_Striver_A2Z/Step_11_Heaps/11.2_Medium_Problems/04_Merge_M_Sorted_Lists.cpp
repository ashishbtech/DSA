#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Custom comparator for the Min Heap to compare ListNode values
struct CompareNode
{
    bool operator()(ListNode *const &p1, ListNode *const &p2)
    {
        // Return true if p1 > p2 to build a MIN heap
        return p1->val > p2->val;
    }
};

class Solution
{
public:
    // BRUTE FORCE: Extract all, sort, and rebuild
    // Time Complexity: O(N log N) | Space Complexity: O(N)
    ListNode *mergeKListsBrute(vector<ListNode *> &lists)
    {
        vector<int> allValues;

        // Extract all values
        for (ListNode *head : lists)
        {
            ListNode *curr = head;
            while (curr != nullptr)
            {
                allValues.push_back(curr->val);
                curr = curr->next;
            }
        }

        // Sort the values
        sort(allValues.begin(), allValues.end());

        // Rebuild the linked list
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for (int val : allValues)
        {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }

    // OPTIMAL: Min Heap of size M
    // Time Complexity: O(N log M) | Space Complexity: O(M)
    ListNode *mergeKListsOptimal(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, CompareNode> minHeap;

        // 1. Push the head of every non-empty list into the Min Heap
        for (ListNode *head : lists)
        {
            if (head != nullptr)
            {
                minHeap.push(head);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        // 2. Process the heap until empty
        while (!minHeap.empty())
        {
            // Get the smallest node
            ListNode *smallest = minHeap.top();
            minHeap.pop();

            // Attach it to our result list
            tail->next = smallest;
            tail = tail->next;

            // If there is a next node in the list we just pulled from, push it
            if (smallest->next != nullptr)
            {
                minHeap.push(smallest->next);
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Solution obj;
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));

    vector<ListNode *> lists = {l1, l2, l3};

    cout << "Merging 3 sorted lists...\n";
    ListNode *mergedHead = obj.mergeKListsOptimal(lists);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}