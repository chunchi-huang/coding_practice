#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> map;
    int res = 0, start = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (map.find(s[i]) != map.end())
        {
            res = max(res, i - start);
            start = max(start, 1 + map[s[i]]);
        }
        map[s[i]] = i;
    }

    res = max(res, (int)s.size() - start);

    return res;
}

int main()
{
    string str = "pwwkew";
    int goal = 3;

    if (lengthOfLongestSubstring(str) == goal)
        cout << "Correct!" << endl;
    else
        cout << "Wrong!" << endl;
}
