#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num)
{
    vector<int> nums{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> strs{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string ans;

    while (num)
    {
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int x = num / nums[i];
            num -= x * nums[i];
            for (int j = 0; j < x; ++j)
            {
                ans += strs[i];
            }
        }
    }
    return ans;
}

int main()
{
    int num = 1994;
    string ans = "MCMXCIV";
    string output = intToRoman(num);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}