#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();

    if (n == 0)
        return 0;

    vector<int> left_max(n, 0), right_max(n, 0);

    left_max[0] = height[0];

    for (int i = 1; i < n; ++i)
        left_max[i] = max(height[i], left_max[i - 1]);

    right_max[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; --i)
        right_max[i] = max(height[i], right_max[i + 1]);

    int ans = 0;

    for (int i = 1; i < n - 1; ++i)
        ans += min(left_max[i], right_max[i]) - height[i];

    return ans;
}

int trap2(vector<int> &height)
{
    int n = height.size();

    if (n == 0)
        return 0;

    int left = 0, right = n - 1, left_max = 0, right_max = 0;
    int ans = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            height[left] >= left_max ? (left_max = height[left]) : (ans += left_max - height[left]);
            ++left;
        }
        else
        {
            height[right] >= right_max ? (right_max = height[right]) : (ans += right_max - height[right]);
            --right;
        }
    }
    return ans;
}

int main()
{
    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = 6;
    int output = trap(height);
    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
    output = trap2(height);
    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }

    vector<int> height2 {4,2,0,3,2,5};
    int ans2 = 9;
    int output2 = trap(height2);
    if (output2 == ans2)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
    output2 = trap2(height2);
    if (output2 == ans2)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}