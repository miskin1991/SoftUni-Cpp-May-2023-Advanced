#include <iostream>
#include <sstream>
#include <set>
#include <vector>



int main()
{
    using namespace std;
    int inputs = 0;
    string name, input;
    vector<string> uniqueNamesVec;
    set<string> uniqueNamesSet;

    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> inputs;
    }
    while (inputs--)
    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> name;
        auto it = uniqueNamesSet.find(name);
        if (it == uniqueNamesSet.end())
        {
            uniqueNamesSet.insert(name);
            uniqueNamesVec.push_back(name);
        }
    }

    for (string& name : uniqueNamesVec)
    {
        cout << name << endl;
    }

    return 0;
}