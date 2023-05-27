#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<double> numbers;
    double number;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> number)
    {
        numbers.insert(number);
    }

    int i = 0;
    for (auto it = numbers.crbegin(); it != numbers.crend(); ++it) {
        cout << *it << ' ';
        i++;
        if( i > 2) break;
    }

    return 0;
}