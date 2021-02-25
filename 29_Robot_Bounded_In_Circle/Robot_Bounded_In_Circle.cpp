#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRobotBounded(string instructions)
{

    int x = 0, y = 0, i = 0;
    vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto cmd : instructions)
    {
        if (cmd == 'R')
            i = (i + 1) % 4;
        else if (cmd == 'L')
            i = (i + 3) % 4;
        else
        {
            x += d[i][0];
            y += d[i][1];
        }
    }
    return (x == 0 && y == 0) || (i != 0);
}

int main()
{
    string instructions = "GGLLGG";
    bool ans = true;
    bool output = isRobotBounded(instructions);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}