#include <iostream>
#include <sstream>
#include <queue>

/*
3
1 5
10 3
3 4
Output: 1

8
10 1
10 1
10 1
6 6
6 6
6 15
10 5
6 1
Output: 0


*/

bool CanReach(std::queue<int> capacities, std::queue<int> distances)
{
    int curCapacity, nextDistance, reservoir = 0;

    while(capacities.size())
    {
        curCapacity = capacities.front();
        nextDistance = distances.front();

        reservoir += curCapacity;
        if (nextDistance <= reservoir)
        {
            reservoir -= nextDistance;
            capacities.pop();
            distances.pop();
        }
        else
            return false;
    }

    return true;
}

int main()
{
    using namespace std;

    int gasStations;
    int curCapacity, nextDistance;
    queue<int> gasStationsCapacities;
    queue<int> distancesToNext;

    cin >> gasStations; cin.ignore();

    for (int i = 0; i < gasStations; i++)
    {
        string buffer;
        getline(cin, buffer);
        stringstream myStream(buffer);
        myStream >> curCapacity >> nextDistance;
        gasStationsCapacities.push(curCapacity);
        distancesToNext.push(nextDistance);
    }

    int i = 0;
    while (i < gasStationsCapacities.size())
    {
        bool canReach { CanReach(gasStationsCapacities, distancesToNext)};

        if (canReach)
            break;

        curCapacity = gasStationsCapacities.front();
        gasStationsCapacities.pop();
        gasStationsCapacities.push(curCapacity);
        nextDistance = distancesToNext.front();
        distancesToNext.pop();
        distancesToNext.push(nextDistance);
        i++;
    }

    cout << i << endl;

    return 0;
}