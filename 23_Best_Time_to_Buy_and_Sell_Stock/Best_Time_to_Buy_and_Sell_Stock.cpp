#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    if (prices.size() < 2) return 0;
    
    int p = 0, low = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] < low)
            low = prices[i];
        else
            p = max(p, prices[i] - low);
    }
    return p;
}

int main() {
    vector<int> prices {7,1,5,3,6,4};
    int ans = 5;
    int output = maxProfit(prices);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}