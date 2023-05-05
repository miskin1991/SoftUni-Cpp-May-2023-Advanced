#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    string input, player;
    getline(cin, input);
    stringstream myStream(input);
    queue<string> names;

    while(myStream >> input)
        names.push(input);

    int times = 0;

    cin >> times;

    while(names.size() > 1)
    {
        for(int i = 1; i < times; i++)
        {
            player = names.front();
            names.pop();
            names.push(player);
        }
        player = names.front();
        names.pop();
        cout << "Removed " << player << endl;
    }

    
    cout << "Last is " << names.front() << endl;

    return 0;
}