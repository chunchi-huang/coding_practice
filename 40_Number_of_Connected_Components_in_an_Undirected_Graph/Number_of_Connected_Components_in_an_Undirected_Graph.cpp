#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &map, vector<bool> &visited, int p)
{
    for (auto neighbor : map[p])
    {
        if (visited[neighbor] == false)
        {
            visited[neighbor] = true;
            dfs(map, visited, neighbor);
        }
    }
}

int countComponents(int n, vector<vector<int>> &edges)
{

    vector<vector<int>> map(n);
    vector<bool> visited(n, false);
    int count = 0;

    // build graph
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        map[u].push_back(v);
        map[v].push_back(u);
    }

    //traverse the map
    for (auto node : map)
    {
        if (node.empty()) // A node without any connection
            count++;
        else
        {
            int p = node[0];
            if (visited[p] == false)
            {
                dfs(map, visited, p);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int n = 5;
    int ans = 2;
    int output = countComponents(n, edges);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}