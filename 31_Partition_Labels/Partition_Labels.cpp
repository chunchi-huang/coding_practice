#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> partitionLabels(string S) {

    map<char,int> m;
    
    for (int i = 0; i < S.length(); ++i)
        m[S[i]] = i;

    int maxValue = 0, loc = 0;
    vector<int> partitions;

    for (int i = 0; i < S.length(); ++i) {

        maxValue = maxValue > m[S[i]] ? maxValue:m[S[i]];

        if (maxValue == i) {
            partitions.push_back(i-loc+1);
            loc = i + 1;
        }
    }
    return partitions;
}

int main() {
    string S = "ababcbacadefegdehijhklij";
    vector<int> output = partitionLabels(S);

    for (auto i:output)
        cout << i << " ";
    cout << endl;
}