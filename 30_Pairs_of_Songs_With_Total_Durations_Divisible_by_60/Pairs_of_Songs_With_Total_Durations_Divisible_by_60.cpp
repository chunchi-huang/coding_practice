#include <iostream>
#include <vector>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {

    vector<int> remainders(60,0);
    int num = 0;

    for (auto t:time) {
        if (t%60 == 0)
            num += remainders[0];
        else
            num += remainders[60-t%60];
        
        remainders[t%60]++;
    }
    return num;
}
int main() {

    vector<int> time = {30,20,150,100,40};
    int ans = 3;
    int output = numPairsDivisibleBy60(time);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}
