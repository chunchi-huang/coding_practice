#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
    for (int j = 0; j < isConnected.size(); ++j) {
        if (isConnected[i][j] == 1 && visited[j] == 0) {
            visited[j] = 1;
            dfs(isConnected, visited, j);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n,0);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            dfs(isConnected, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> isConnected {{1,1,0},{1,1,0},{0,0,1}};
    int ans = 2;
    int output = findCircleNum(isConnected);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}