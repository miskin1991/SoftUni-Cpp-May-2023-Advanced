#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;


int main()
{
    map<string, int> resources;
    vector<string> resourcesOrder;
    string input;

    do {
        cin >> input;
        
        string command(input);
        for (char& letter : command)
            letter = ::tolower(letter);

        if (command == "stop")
            break;
        
        const auto& it = resources.find(input);

        int value = 0;
        cin >> value;
        if (it != resources.end()) {
            it->second += value; 
        } else {
            resources.insert(pair<string, int>(input, value));
            resourcesOrder.push_back(input);
        }

    } while (true);

    for (auto& resource : resourcesOrder)
        cout << resources.find(resource)->first << " -> " << resources.find(resource)->second << endl;

    return 0;
}