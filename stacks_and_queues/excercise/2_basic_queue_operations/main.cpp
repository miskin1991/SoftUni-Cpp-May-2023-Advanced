#include <iostream>
#include <sstream>
#include <queue>
#include <stack>


int main()
{
    using namespace std;
    string input;
    int totalNumbers, popNumbers, searchNumber;
    queue<int> numbers;

    cin >> totalNumbers >> popNumbers >> searchNumber;

    for (int i = 0; i < totalNumbers; i++)
    {
        int number;
        cin >> number;
        numbers.push(number);
    }

    for (int i = 0; i < popNumbers; i++)
        numbers.pop();

    if (numbers.empty())
    {
        cout << "0" << endl;
        return 0;
    }
    
    int minimum = INT32_MAX;
    while(numbers.size())
    {
        int number = numbers.front();
        numbers.pop();
        if (number == searchNumber)
        {
            cout << "true" << endl;
            return 0;
        }
        if (number < minimum)
            minimum = number;
    }

    cout << minimum << endl;

    return 0;
}