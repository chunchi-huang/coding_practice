#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
}

vector<int> prisonAfterNDays(vector<int> &cells, int n)
{
    n = n % 14 == 0 ? 14 : n % 14;

    vector<int> prev = cells;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < cells.size() - 1; ++j)
        {
            cells[j] = prev[j - 1] == prev[j + 1];
        }
        cells[0] = cells[cells.size() - 1] = 0;
        prev = cells;
    }

    return cells;
}

int main()
{
    vector<int> cells {0,1,0,1,1,0,0,1};
    int n = 7;
    vector<int> output = prisonAfterNDays(cells,n);

    printVector(output);
}