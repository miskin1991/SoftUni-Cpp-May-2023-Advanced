#include <iostream>
#include <sstream>
#include <map>
#include <math.h>

using namespace std;

bool isSquare(int value)
{
    double result = sqrt(value);
    result = result - static_cast<int>(result);
    return result == 0 ? true : false;
}

int main()
{
    map<int, int, std::greater<int>> numbers;
    int number;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> number) {
        auto it { numbers.find(number) };
        if (it != numbers.end())
            it->second++;
        else
            numbers.insert(pair<int,int>(number, 1));
    }

    for (auto& number : numbers)
        if (isSquare(number.first))
            for( int i = 0; i < number.second; i++)
                cout << number.first << ' ';
    cout << endl;

    return 0;
}