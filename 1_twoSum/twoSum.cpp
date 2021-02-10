#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (map.find(nums[i]) != map.end())
            return {map[nums[i]], i};
        else
            map[target - nums[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << "," << result[1] << endl;
}