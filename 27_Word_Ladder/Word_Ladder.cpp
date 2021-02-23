#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> word_set(wordList.begin(), wordList.end());
    if (word_set.count(endWord) == 0)
        return 0;
    queue<string> q;
    q.push(beginWord);
    int level = 0;

    while (q.empty() == false)
    {
        int n = q.size();
        level++;

        for (int i = 0; i < n; ++i)
        {
            string word = q.front();
            q.pop();

            if (word == endWord)
                return level;

            for (int j = 0; j < word.size(); ++j)
            {
                char tmp = word[j];
                for (int k = 0; k < 26; ++k)
                {
                    word[j] = 'a' + k;
                    if (word_set.find(word) != word_set.end())
                    {
                        q.push(word);
                        word_set.erase(word);
                    }
                }
                word[j] = tmp;
            }
        }
    }
    return 0;
}

int main()
{
    vector<string> wordList {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit", endWord = "cog";
    int ans = 5;
    int output = ladderLength(beginWord, endWord,wordList);

    if (output == ans)  
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}