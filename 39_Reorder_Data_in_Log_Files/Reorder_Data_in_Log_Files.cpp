#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vec) {

    for (auto v:vec) 
        cout << v << endl;
    cout << endl;
}

bool compare(string str1, string str2)
{
    int pos1 = str1.find(" "), pos2 = str2.find(" ");
    string s1 = str1.substr(pos1 + 1), s2 = str2.substr(pos2 + 1);

    if (s1 == s2)
    {
        if (str1.compare(str2) <= 0)
            return true;
        return false;
    }

    if (s1.compare(s2) <= 0)
        return true;
    return false;
}

vector<string> reorderLogFiles(vector<string> &logs)
{

    vector<string> letters, digits, ans;

    for (auto log : logs)
    {
        int pos = log.find(" ");
        if (isdigit(log[pos + 1]))
            digits.push_back(log);
        else
            letters.push_back(log);
    }

    sort(letters.begin(), letters.end(), compare);
    ans.insert(ans.end(), letters.begin(), letters.end());
    ans.insert(ans.end(), digits.begin(), digits.end());

    return ans;
}

int main()
{
    vector<string> logs1 {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> output1 = reorderLogFiles(logs1);
    printVector(output1);
    
    vector<string> logs2 {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    vector<string> output2 = reorderLogFiles(logs2);
    printVector(output2);

}