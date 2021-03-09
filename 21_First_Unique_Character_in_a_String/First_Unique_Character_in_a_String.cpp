#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> map;
    for (auto e : s)
        map[e]++;

    for (int i = 0; i < s.size(); ++i)
        if (map[s[i]] == 1)
            return i;

    return -1;
}

int main()
{
    string s = "loveleetcode";
    int ans = 2;
    int output =  firstUniqChar(s);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}