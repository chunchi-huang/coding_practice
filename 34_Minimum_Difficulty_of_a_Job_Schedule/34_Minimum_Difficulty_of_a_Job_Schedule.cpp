#include <iostream>
#include <vector>

using namespace std;

int minDifficulty(vector<int>& jobDifficulty, int d) {

    int n = jobDifficulty.size();

    if (n < d) return -1;

    vector<vector<int>> dp(n+1, vector<int>(d+1,INT_MAX/2));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= d; ++k) {
            int md = 0;
            for (int j = i-1; j >= k-1; --j) {
                md = max(md, jobDifficulty[j]);
                dp[i][k] = min(dp[i][k],dp[j][k-1]+md);
            }
        }
    }
    return dp[n][d];
}

int main() {

    vector<int> jobDifficulty {6,5,4,3,2,1};
    int d = 2;
    int ans = 7;
    int output = minDifficulty(jobDifficulty,d);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}