#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct videoStream
{
    int start;
    int duration;
    int bandwidth;
};

void bandwidthAnalysis(vector<videoStream> streams) {

    unordered_map<int,int> umap;

    for (auto stream:streams) {
        int count = stream.duration;
        for (int i = 0; i < count; ++i) {
            umap[stream.start+i] += stream.bandwidth;
        }
    }

    for (int i = 0; i < umap.size(); ++i)
        cout << umap[i] << " ";
    cout << endl;
}

int main()
{
    vector<videoStream> streams = {
        {1, 2, 10},
        {1, 8, 20},
        {0, 2, 10},
        {2, 1, 20},
        {3, 5, 15},
        {7, 1, 40}};

    bandwidthAnalysis(streams);
}
