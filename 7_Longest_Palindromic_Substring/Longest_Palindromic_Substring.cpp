#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s)
{

    if (s.size() == 0 || s.size() == 1)
        return s;

    int n = s.size();
    vector<vector<bool>> P(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
    {
        P[i][i] = true;
        if (i == n - 1)
            break;
        P[i][i + 1] = (s[i] == s[i + 1]);
    }

    //DP
    for (int i = n - 3; i >= 0; --i)
    {
        for (int j = i + 2; j < n; ++j)
        {
            P[i][j] = (P[i + 1][j - 1] && s[i] == s[j]);
        }
    }

    int maxLen = 0;
    string ans = "";

    //Calcualte the ans
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (P[i][j] == true && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                ans = s.substr(i, maxLen);
            }
        }
    }
    return ans;
}

int main() {
    string input = "abcbaaaa";
    string ans = "abcba";

    string output = longestPalindrome(input);

    if (output == ans)
        cout << "Correct! The answer is " << ans << "." <<endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "but the output is " << output << endl;
    }
}