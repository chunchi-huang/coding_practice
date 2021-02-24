#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> word_set(wordList.begin(), wordList.end());

    if (word_set.count(endWord) == 0)
        return {};

    vector<vector<string>> res;
    queue<vector<string>> q;
    q.push({beginWord});

    bool found = false;

    while (!q.empty())
    {

        if (found)
            break;

        int n = q.size();
        unordered_set<string> visited;

        for (int i = 0; i < n; ++i)
        {
            vector<string> path = q.front();
            q.pop();
            string word = path.back();

            if (word == endWord)
            {
                res.push_back(path);
                found = true;
            }

            for (int j = 0; j < word.size(); ++j)
            {
                char tmp = word[j];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[j] = c;
                    if (word_set.find(word) != word_set.end())
                    {
                        visited.insert(word);
                        vector<string> new_path = path;
                        new_path.push_back(word);
                        q.push(new_path);
                    }
                }
                word[j] = tmp;
            }
        }

        for (auto v : visited)
            word_set.erase(v);
    }
    return res;
}

int main()
{
    vector<string> wordList {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";

    vector<vector<string>> output = findLadders(beginWord, endWord, wordList);

    for (auto row : output) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

}