#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    if (nums.size() == 1) return nums[0];

    int subMax = nums[0], totalMax = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        subMax = max(nums[i], subMax + nums[i]);
        totalMax = max(subMax, totalMax);
    }

    return totalMax;
}

int main()
{
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    int ans = 6;

    int output = maxSubArray(nums);

    if (output == ans)
        cout << "Correct! The answer is " << output << "." << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "but the output is " << output << endl;
    }
}