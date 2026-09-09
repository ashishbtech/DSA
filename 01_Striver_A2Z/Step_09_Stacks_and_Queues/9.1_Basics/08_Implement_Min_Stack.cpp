#include <bits/stdc++.h>
using namespace std;

// BETTER APPROACH: Storing pairs {value, minimum_so_far}
class MinStackBetter
{
    stack<pair<int, int>> st;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// OPTIMAL APPROACH: Mathematical encoding using O(1) auxiliary space
class MinStackOptimal
{
    stack<long long> st;
    long long mini;

public:
    MinStackOptimal()
    {
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                // Push modified value: 2*val - previous_mini
                st.push(2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long topVal = st.top();
        st.pop();

        // If topVal < mini, it means we are popping the current minimum
        if (topVal < mini)
        {
            // Rollback the minimum to the previous minimum
            mini = 2 * mini - topVal;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long topVal = st.top();

        // If topVal < mini, it's a modified flag, actual value is mini
        if (topVal < mini)
        {
            return mini;
        }
        return topVal;
    }

    int getMin()
    {
        return mini;
    }
};

int main()
{
    MinStackOptimal minSt;

    minSt.push(-2);
    minSt.push(0);
    minSt.push(-3);

    cout << minSt.getMin() << "\n";
    minSt.pop();
    cout << minSt.top() << "\n";
    cout << minSt.getMin() << "\n";

    return 0;
}