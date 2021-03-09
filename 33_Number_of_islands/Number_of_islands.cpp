#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c)
{
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';

    if (r - 1 >= 0 && grid[r - 1][c] == '1')
        dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1')
        dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')
        dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1')
        dfs(grid, r, c + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int nr = grid.size();
    if (nr == 0)
        return 0;
    int nc = grid[0].size();
    int num = 0;

    for (int r = 0; r < nr; ++r)
    {
        for (int c = 0; c < nc; ++c)
        {
            if (grid[r][c] == '1')
            {
                num++;
                dfs(grid, r, c);
            }
        }
    }
    return num;
}

int main()
{
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    int ans = 1;
    int output = numIslands(grid);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}