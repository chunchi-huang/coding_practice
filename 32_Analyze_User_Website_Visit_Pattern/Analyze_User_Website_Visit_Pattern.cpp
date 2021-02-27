#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website)
{
    unordered_map<string, map<int, string>> umap;
    unordered_map<string, int> cnt;
    string res = "";
    int max_cnt = 0;

    for (int i = 0; i < username.size(); ++i)
        umap[username[i]][timestamp[i]] = website[i];

    for (auto u : umap)
    {
        unordered_set<string> seqs;

        for (auto it = begin(u.second); it != end(u.second); ++it)
            for (auto it2 = next(it); it2 != end(u.second); ++it2)
                for (auto it3 = next(it2); it3 != end(u.second); ++it3)
                    seqs.insert(it->second + "#" + it2->second + "$" + it3->second);

        for (auto s : seqs)
            cnt[s]++;
    }

    for (auto c : cnt)
    {
        if (c.second >= max_cnt)
        {
            res = res == "" || c.second > max_cnt ? c.first : min(res, c.first);
            max_cnt = c.second;
        }
    }

    auto p1 = res.find("#"), p2 = res.find("$");

    return {res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1), res.substr(p2 + 1, res.size() - 2)};
}

int main() {
    vector<string> username {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10};
    vector<string> website = {"home","about","career","home","cart","maps","home","home","about","career"};

    vector<string> ans = mostVisitedPattern(username, timestamp, website);

    for (auto a:ans)
        cout << a << " ";
    cout << endl;
}