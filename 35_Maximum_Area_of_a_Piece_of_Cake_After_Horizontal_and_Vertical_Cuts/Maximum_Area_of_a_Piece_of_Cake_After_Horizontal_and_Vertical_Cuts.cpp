#include <iostream>
#include <vector>

using namespace std;

int maxArea(int h, int w, vector<int> &hCuts, vector<int> &vCuts)
{
    hCuts.push_back(0);
    hCuts.push_back(h);

    vCuts.push_back(0);
    vCuts.push_back(w);

    sort(hCuts.begin(), hCuts.end());
    sort(vCuts.begin(), vCuts.end());

    int max_h = 0, max_w = 0;

    for (int i = 1; i < hCuts.size(); ++i)
        max_h = max(max_h, hCuts[i] - hCuts[i - 1]);

    for (int j = 1; j < vCuts.size(); ++j)
        max_w = max(max_w, vCuts[j] - vCuts[j - 1]);

    int ans = ((long)max_h * (long)max_w) % (1000000007);

    return ans;
}
int main()
{
    vector<int> horizontalCuts {1,2,4};
    vector<int> verticalCuts {1,3};
    int h = 5, w = 4;
    int ans = 4;
    int output = maxArea(h,w,horizontalCuts, verticalCuts);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}