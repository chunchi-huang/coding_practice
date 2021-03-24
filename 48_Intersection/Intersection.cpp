#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

queue<int> queue_north;
queue<int> queue_south;
queue<int> queue_east;
queue<int> queue_west;
int direction = 1; // direction: 1: North, 2: East, 3: South, 4: West

void Arrival(vector<pair<int, int>> traffic)
{
    if (traffic.size() == 0)
        return;

    direction = traffic[0].second;

    for (int i = 0; i < traffic.size(); ++i)
    {
        if (traffic[i].second == 1)
            queue_north.push(traffic[i].first);
        else if (traffic[i].second == 2)
            queue_east.push(traffic[i].first);
        else if (traffic[i].second == 3)
            queue_south.push(traffic[i].first);
        else if (traffic[i].second == 4)
            queue_west.push(traffic[i].first);
        else
            cout << "Wrong direction:" << traffic[i].second << endl;
    }
}

vector<int> Depature()
{
    vector<int> ans;
    int car1 = 0, car2 = 0;

    if (direction % 2 == 1)
    {
        if (queue_north.size() == 0 && queue_south.size() == 0)
        {
            if (queue_west.size() > 0)
            {
                car1 = queue_west.front();
                queue_west.pop();
                ans.push_back(car1);
            }

            if (queue_east.size() > 0)
            {
                car2 = queue_east.front();
                queue_east.pop();
                ans.push_back(car2);
            }
        }
        else
        {
            if (queue_north.size() > 0)
            {
                car1 = queue_north.front();
                queue_north.pop();
                ans.push_back(car1);
            }

            if (queue_south.size() > 0)
            {
                car2 = queue_south.front();
                queue_south.pop();
                ans.push_back(car2);
            }
        }
    }
    else
    {
        if (queue_west.size() == 0 && queue_east.size() == 0)
        {
            if (queue_west.size() > 0)
            {
                car1 = queue_west.front();
                queue_west.pop();
                ans.push_back(car1);
            }

            if (queue_east.size() > 0)
            {
                car2 = queue_east.front();
                queue_east.pop();
                ans.push_back(car2);
            }
        }
        else
        {

            if (queue_west.size() > 0)
            {
                car1 = queue_west.front();
                queue_west.pop();
                ans.push_back(car1);
            }

            if (queue_east.size() > 0)
            {
                car2 = queue_east.front();
                queue_east.pop();
                ans.push_back(car2);
            }
        }
    }

    direction++;

    if (direction > 4)
        direction = 1;

    for (auto car : ans)
        cout << car << " ";
    cout << endl;

    return ans;
}

int main()
{
    // direction: 1: North, 2: East, 3: South, 4: West
    vector<pair<int, int>> traffic{{1, 1}, {2, 4}, {3, 4}, {4, 2}, {5, 3}}; // vector<pair<car_id, direction>>
    Arrival(traffic);
    Depature();
    Depature();
    Depature();
}