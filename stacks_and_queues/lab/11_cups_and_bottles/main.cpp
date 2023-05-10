#include <iostream>
#include <sstream>
#include <queue>
#include <stack>


int main()
{
    using namespace std;
    string input;
    stack<int> remainingBottles {};
    queue<int> remainingCups {};
    int currentBottle = 0, wastedLitterOfWatter  = 0;

    {
        getline(cin, input);
        stringstream stream(input);
        while (stream >> input)
            remainingCups.push(atoi(input.c_str()));
    }
    {
        getline(cin, input);
        stringstream stream(input);
        while (stream >> input)
            remainingBottles.push(atoi(input.c_str()));
    }

    while (remainingCups.size() && remainingBottles.size())
    {
        int& currentCup = remainingCups.front();
        currentBottle = remainingBottles.top();
        remainingBottles.pop();

        if (currentCup <= currentBottle)
        {
            wastedLitterOfWatter += currentBottle - currentCup;
            remainingCups.pop();
        }
        else
        {
            currentCup -= currentBottle;
        }
    }

    if (remainingBottles.empty())
    {
        cout << "Cups:";
        while(remainingCups.size())
        {
            cout << ' ' << remainingCups.front();
            remainingCups.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Bottles:" ;
        while (remainingBottles.size())
        {
            cout << ' ' << remainingBottles.top();
            remainingBottles.pop();
        }
        cout << endl;
    }
    
    cout << "Wasted litters of water: " << wastedLitterOfWatter << endl;

    return 0;
}