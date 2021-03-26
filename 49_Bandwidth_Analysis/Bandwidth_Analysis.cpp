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

void bandwidthAnalysis2(vector<videoStream> streams) {

    unordered_map<int,int> delta;
    vector<int> ans;

    int max_time = 0, bandwidth = 0;

    for (auto stream:streams) {
        delta[stream.start] += stream.bandwidth;
        delta[stream.start + stream.duration] += -1*stream.bandwidth;
        max_time = max((stream.start + stream.duration), max_time);
    }

    for (int i = 0; i < max_time; ++i ) {
        bandwidth += delta[i]; 
        cout << bandwidth << " ";
    }
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
    bandwidthAnalysis2(streams);
}
