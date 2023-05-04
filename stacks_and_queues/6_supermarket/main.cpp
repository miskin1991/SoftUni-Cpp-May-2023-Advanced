#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    queue<string> notPaidQueue;
    queue<string> paidQueue;
    string input;

    while(true)
    {
        cin >> input;

        if (input == "Paid")
        {
            while(notPaidQueue.size())
            {
                paidQueue.push(notPaidQueue.front());
                notPaidQueue.pop();
            }
        }
        else if (input == "End")
        {
            while(paidQueue.size())
            {
                cout << paidQueue.front() << endl;
                paidQueue.pop();
            }
            cout << notPaidQueue.size() << " people remaining" << endl;
            break;
        }
        else
        {
            notPaidQueue.push(input);
        }
    }

    return 0;
}