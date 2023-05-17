#include <iostream>
#include <set>
#include <sstream>

int main()
{
    using namespace std;
    set<string> periodicTable;
    int inputs = 0;
    string element, elements;

    {
        getline(cin, element);
        stringstream buffer(element);
        buffer >> inputs;
    }

    while (inputs--)
    {
        getline(cin, elements);
        stringstream buffer(elements);
        while (buffer >> element)
        {
            periodicTable.insert(element);
        }
    }
    
    for (auto element : periodicTable)
        cout << element << ' ';

    return 0;
}