#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{

    int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
    vector<int> dp(cols + 1, 0);
    int maxL = 0, prev = 0;

    for (int r = 1; r <= rows; ++r)
    {
        for (int c = 1; c <= cols; ++c)
        {
            int temp = dp[c];
            if (matrix[r - 1][c - 1] == '1')
            {
                dp[c] = min(min(dp[c - 1], dp[c]), prev) + 1;
                maxL = max(maxL, dp[c]);
            }
            else
                dp[c] = 0;
            prev = temp;
        }
    }

    return maxL * maxL;
}

int main()
{
    vector<vector<char>> matrix {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int ans = 4;
    int output = maximalSquare(matrix);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}