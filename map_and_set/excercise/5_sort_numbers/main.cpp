#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<int> numbers;
    int number;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> number) {
        numbers.insert(number);
    }
    
    string supportStr { " <= " };
    input.clear();
    for(auto number : numbers) {
        input.append(to_string(number)).append(supportStr);
    }
    input.erase(input.size() - supportStr.size());
    cout << input << endl;

    return 0;
}