#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{

    for (auto v : vec)
        cout << v << endl;
    cout << endl;
}
bool isCycle(vector<vector<int>> &graph, vector<int> &visited, vector<int> &res, int i)
{
    if (visited[i] == 1)
        return true;
    else if (visited[i] == 0)
    {
        visited[i] = 1;
        for (auto node : graph[i])
        {
            if (isCycle(graph, visited, res, node))
                return true;
        }
    }

    if (visited[i] != 2)
        res.push_back(i);
    visited[i] = 2;

    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<vector<int>> graph(numCourses);
    vector<int> visited(numCourses, 0);
    vector<int> res;

    //build graph
    for (auto edge : prerequisites)
        graph[edge[1]].push_back(edge[0]);

    //detect cycle and fill res
    for (int i = 0; i < numCourses; ++i)
    {
        if (isCycle(graph, visited, res, i))
            return {};
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    vector<vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;
    vector<int> output = findOrder(numCourses, prerequisites);

    printVector(output);
}
