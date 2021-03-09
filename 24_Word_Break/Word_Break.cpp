#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    set<string> work_set(wordDict.begin(), wordDict.end());
    queue<int> q;
    vector<bool> visited(s.size(), false);
    q.push(0);

    while (q.empty() == false)
    {
        int start = q.front();
        q.pop();

        if (visited[start] == true)
            continue;

        for (int end = start + 1; end <= s.size(); ++end)
        {
            if (work_set.find(s.substr(start, end - start)) != work_set.end())
            {
                q.push(end);

                if (end == s.size())
                    return true;
            }
        }
        visited[start] = true;
    }
    return false;
}

int main()
{

    vector<string> wordDict{"leet", "code"};
    string s = "leetcode";
    bool ans = true;
    bool output = wordBreak(s, wordDict);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}