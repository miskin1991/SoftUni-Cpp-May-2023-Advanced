#include <iostream>
#include <sstream>
#include <map>
#include <vector>


int main()
{
    using namespace std;
    
    string input;
    getline(cin, input);
    stringstream sstream(input);
    map<double, int> values;
    vector<double> order;
    double value;


    while (sstream >> value)
    {
        auto it = values.find(value);
        if (it == values.end())
        {
            values.insert(pair<double, int>(value, 1));
            order.push_back(value);
        }
        else
            it->second++;
    }

    for (double place : order)
    {
        auto it = values.find(place);
        cout << place << " - " << it->second << " times" << endl;
    }

    return 0;
}