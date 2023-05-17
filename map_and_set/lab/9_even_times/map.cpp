#include <iostream>
#include <map>
#include <sstream>

int main()
{
    using namespace std;
    int inputs = 0;
    int number = 0;
    bool found = false;
    map<int,int> numbers;

    cin >> inputs;
    while(inputs--)
    {
        cin >> number;
        auto it = numbers.find(number);
        if (it == numbers.end())
        {
            numbers.insert(pair<int,int>(number, 1));
        }
        else
        {
            it->second++;
        }
    }

    for (const auto& number : numbers)
    {
        if (number.second % 2 == 0)
        {
            cout << number.first << endl;
            break;
        }
    }

    return 0;
}