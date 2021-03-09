#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {

    int missing = nums.size();

    for (int i = 0; i < nums.size(); ++i) 
        missing ^= i^nums[i];
    
    return missing;
}

int main() {
    vector<int> nums {3,0,1};
    int ans = 2;
    int output = missingNumber(nums);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}