#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if the color is safe for the current node
    bool isSafe(int node, int colorArray[], vector<int> adj[], int col)
    {
        // Check all adjacent nodes
        for (auto neighbor : adj[node])
        {
            if (colorArray[neighbor] == col)
            {
                return false; // A neighbor already has this color
            }
        }
        return true;
    }

    bool solve(int node, int colorArray[], int m, int N, vector<int> adj[])
    {
        // Base case: If all nodes have been safely colored
        if (node == N)
        {
            return true;
        }

        // Try every color from 1 to m
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, colorArray, adj, i))
            {

                // Pick the color
                colorArray[node] = i;

                // Recurse to the next node
                // SHORT-CIRCUIT: If coloring the rest of the graph succeeds, stop and return true
                if (solve(node + 1, colorArray, m, N, adj))
                {
                    return true;
                }

                // Backtrack: Remove the color to try the next one
                colorArray[node] = 0;
            }
        }

        // If no color from 1 to m works for this node, this path is a dead end
        return false;
    }

public:
    // OPTIMAL: DFS Backtracking with Adjacency List
    // Time Complexity: O(M^N) worst case | Space Complexity: O(N) Call Stack + O(N+E) Graph
    bool graphColoring(vector<int> adj[], int m, int n)
    {
        int colorArray[n] = {0};
        return solve(0, colorArray, m, n, adj);
    }
};

int main()
{
    Solution obj;
    int N = 4;
    int M = 3;
    int E = 5;

    // Edges of the graph
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};

    // Build the adjacency list
    vector<int> adj[N];
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    if (obj.graphColoring(adj, M, N))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}