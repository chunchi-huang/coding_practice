#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

void printVector(vector<int> vec)
{
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;

    for (auto num : nums)
        umap[num]++;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for (auto e : umap)
    {
        pq.emplace(make_pair(e.second, e.first));

        if (pq.size() > k)
            pq.pop();
    }

    vector<int> res;

    while (pq.size())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> output = topKFrequent(nums,k);
    
    printVector(output);
}