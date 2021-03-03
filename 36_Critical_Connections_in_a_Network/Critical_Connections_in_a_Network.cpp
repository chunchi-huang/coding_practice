#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    vector<vector<int>> graph, res;
    vector<int> visited, low;
    int timestamp = 0;
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        buildGraph(n, connections);
        dfs(0,0);
        return res;
    }
    
    void buildGraph(int n, vector<vector<int>>& connections) {
        
        graph = vector<vector<int>>(n);
        visited = vector<int>(n);
        low = vector<int>(n);
        
        for (auto conn:connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    
    void dfs(int curr, int prev) {
        
        if (visited[curr] > 0) return;
        
        visited[curr] = low[curr] = ++timestamp;
        
        for (auto next:graph[curr]) {
            
            if (next == prev) continue;
            
            dfs(next,curr);
            
            if (low[next] > visited[curr])
                res.push_back({curr,next});
            
            low[curr] = min(low[curr], low[next]);
        }
    }
};

bool compare2LevelVector(vector<vector<int>> A, vector<vector<int>> B) {

    if (A.size()!=B.size() || A[0].size()!= B[0].size()) return false;

    for (int i = 0; i < A.size(); ++i) 
        for (int j = 0; j < A[0]. size(); ++j) 
            if (A[i][j] != B[i][j])
                return false;
        
    return true;
}

void print2LevelVector(vector<vector<int>> vec) {

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {

    int n = 4;
    vector<vector<int>> connections {{0,1},{1,2},{2,0},{1,3}};
    
    Solution solution;
    vector<vector<int>> output = solution.criticalConnections(n, connections);
    vector<vector<int>> ans {{1,3}};


    if (compare2LevelVector(output,ans) == false) {
        cout << "Wrong! Your result is: " << endl; 
        print2LevelVector(output);
        cout << "But the ans should be: " << endl;
        print2LevelVector(ans);
    } else {
        cout << "Correct! The ans is: " << endl;
        print2LevelVector(ans);
    }
}