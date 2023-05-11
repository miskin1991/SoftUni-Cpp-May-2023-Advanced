#include <iostream>
#include <sstream>
#include <stack>

/*
5 4 8 6 3 8 7 7 9
16
Output: 5

1 7 8 2 5 4 7 8 9 6 3 2 5 4 6
20
Output: 5

*/
int main()
{
    using namespace std;

    int clothes, rackCapacity;
    stack<int> boxes;

    string buffer;
    getline(cin, buffer);
    stringstream myStream(buffer);
    while (myStream >> clothes)
        boxes.push(clothes);

    cin >> rackCapacity;

    int currentCapacity = rackCapacity;
    int racks = 1;

    while (boxes.size())
    {
        int box = boxes.top();
        if (box <= currentCapacity)
        {
            currentCapacity -= box;
            boxes.pop();
        }
        else
        {
            currentCapacity = rackCapacity;
            racks++;
        }
    }

    cout << racks << endl;

    return 0;
}