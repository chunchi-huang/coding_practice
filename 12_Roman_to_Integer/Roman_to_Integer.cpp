#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char,int> map {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (i+1 < s.size() && map[s[i]] < map[s[i+1]])
            ans -= map[s[i]];
        else
            ans += map[s[i]];
    }

    return ans;
}

int main() {

    string s = "LVIII";
    int ans = 58;
    int output = romanToInt(s);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }

}