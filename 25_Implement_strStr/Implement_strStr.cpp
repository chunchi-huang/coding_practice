#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{

    if (needle == "")
        return 0;

    int h = haystack.size(), n = needle.size();

    for (int i = 0; i < h - n + 1; ++i)
    {

        if (i + n <= h && haystack.substr(i, n) == needle)
            return i;
    }

    return -1;
}

int main() {
    string haystack = "hello", needle = "ll";
    int ans = 2;
    int output = strStr(haystack, needle);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}
