#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printVector(vector<string> vec)
{
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
}

static bool comp(pair<int, string> &a, pair<int, string> &b)
{
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> umap;
    vector<pair<int, string>> vp;
    vector<string> res;

    for (auto word : words)
        umap[word]++;

    for (auto e : umap)
        vp.push_back(make_pair(e.second, e.first));

    sort(vp.begin(), vp.end(), comp);

    for (int i = 0; i < k; ++i)
        res.push_back(vp[i].second);

    return res;
}

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    vector<string> ans = topKFrequent(words, k);

    printVector(ans);
}