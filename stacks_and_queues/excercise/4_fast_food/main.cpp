#include <iostream>
#include <sstream>
#include <queue>

/*
348
20 54 30 16 7 9
Output:
54
Orders complete 

499
57 45 62 70 33 90 88 76
Output:
90
Orders left: 76
*/

int main()
{
    using namespace std;

    queue<int> orders;
    int portions, maximum = INT32_MIN;

    cin >> portions; cin.ignore();
    string buffer;
    getline(cin, buffer);
    
    stringstream stream(buffer);
    int curOrder;
    while (stream >> curOrder)
    {
        orders.push(curOrder);
        curOrder > maximum ? maximum = curOrder : maximum; 
    }

    while (orders.size())
    {
        curOrder = orders.front();
        if (curOrder > portions)
            break;
        else
        {
            orders.pop();
            portions -= curOrder;
        }
    }

    cout << maximum << endl;
    if (orders.empty())
        cout << "Orders complete" << endl;
    else
    {
        cout << "Orders left: ";
        while (orders.size())
        {
            cout << orders.front() << " ";
            orders.pop();
        }
        cout << endl;
    }

    return 0;
}