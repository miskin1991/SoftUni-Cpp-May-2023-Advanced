#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    map<double, int> numbers;
    double value;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> value)
    {
        auto it { numbers.find(value) };
        if (it != numbers.end()) {
            it->second++;
        }
        else {
            numbers.insert(pair<double,int>(value, 1));
        }
    }
    
    for (auto& number : numbers) {
        cout << number.first << " -> " << number.second << endl;
    }

    return 0;
}