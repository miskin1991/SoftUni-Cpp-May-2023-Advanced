#include <iostream>
#include <sstream>
#include <queue>
#include <stack>


int main()
{
    using namespace std;

    // variable declarations
    string input;    
    int bulletPrice = 0, sizeGunBarrel = 0, totalShots = 0, intelligence = 0;
    int currentLock = 0, currentShoots = 0;
    stack<int> bullets;
    queue<int> locks;
    
    // process inputs
    getline(cin, input);
    bulletPrice = atoi(input.c_str());
    getline(cin, input);
    sizeGunBarrel = atoi(input.c_str());
    const int sizeGunBarrelAux = sizeGunBarrel;
    getline(cin, input);
    {
        stringstream buffer(input.c_str());
        while(buffer >> input)
            bullets.push(atoi(input.c_str()));
    }
    getline(cin, input);
    {
        stringstream buffer(input.c_str());
        while(buffer >> input)
            locks.push(atoi(input.c_str()));
    }
    getline(cin, input);
    intelligence = atoi(input.c_str());

    // operations
    while (locks.size() && bullets.size())
    {
        if (!sizeGunBarrel)
        {
            cout << "Reloading" << endl;
            sizeGunBarrel = sizeGunBarrelAux;
        }

        currentLock = locks.front();
        currentShoots = bullets.top();
        bullets.pop();
        sizeGunBarrel--;

        if (currentShoots <= currentLock)
        {
            cout << "Bang!" << endl;
            locks.pop();
        }
        else
            cout << "Ping!" << endl;

        totalShots++;
    }

    // outputing result
    if (bullets.size() || locks.empty())
        cout << bullets.size() << " bullets left. Earned $" << intelligence - totalShots*bulletPrice << endl;
    else
        cout << "Couldn't get through. Locks left: " << locks.size() << endl;

    return 0;
}