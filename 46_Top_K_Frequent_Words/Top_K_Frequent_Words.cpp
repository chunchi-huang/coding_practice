#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

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

struct Comp
{
    bool operator()(pair<int, string> &a, pair<int, string> &b)
    {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
                                    //descreasing(less)   // increasing(greater)
    }
};

vector<string> topKFrequent2(vector<string> &words, int k)
{
    unordered_map<string, int> umap;
    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
    vector<string> res;

    for (auto word : words)
        umap[word]++;

    for (auto e : umap)
    {
        pq.push(make_pair(e.second, e.first));

        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    vector<string> ans = topKFrequent(words, k);

    printVector(ans);

    vector<string> ans2 = topKFrequent2(words, k);

    printVector(ans2);
}