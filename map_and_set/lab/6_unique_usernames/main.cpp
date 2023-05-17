#include <iostream>
#include <sstream>
#include <set>
#include <vector>



int main()
{
    using namespace std;
    int inputs = 0;
    string name, input;
    vector<string> uniqueUsernamesVec;
    set<string> uniqueUsernamesSet;

    cin >> inputs;    
    while (inputs--)
    {
        cin >> name;
        auto it = uniqueUsernamesSet.find(name);
        if (it == uniqueUsernamesSet.end())
        {
            uniqueUsernamesSet.insert(name);
            uniqueUsernamesVec.push_back(name);
        }
    }

    for (string& name : uniqueUsernamesVec)
    {
        cout << name << endl;
    }

    return 0;
}