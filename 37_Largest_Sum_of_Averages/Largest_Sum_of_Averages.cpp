#include <iostream>
#include <vector>

using namespace std;

double largestSumOfAverages(vector<int> &A, int K)
{
    int n = A.size();

    vector<vector<double>> dp(K + 1, vector<double>(n + 1, 0.0));
    vector<double> sums(n + 1, 0.0);

    for (int i = 1; i <= n; ++i)
    {
        sums[i] = sums[i - 1] + A[i - 1];
        dp[1][i] = sums[i] / i;
    }

    for (int k = 2; k <= K; ++k)
        for (int i = k; i <= n; ++i)
            for (int j = k - 1; j < i; ++j)
                dp[k][i] = max(dp[k][i], dp[k - 1][j] + (sums[i] - sums[j]) / (i - j));

    return dp[K][n];
}

int main()
{
    vector<int> A {9,1,2,3,9};
    int K = 3;
    double ans = 20;
    double output = largestSumOfAverages(A,K);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}