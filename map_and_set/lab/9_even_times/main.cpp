#include <iostream>
#include <set>
#include <sstream>

int main()
{
    using namespace std;
    set<int> numbers {};
    int inputs, number, repeated;
    bool found { false };

    cin >> inputs;
    while(inputs--)
    {
        cin >> number;
        auto status { numbers.insert(number) };
        if (!status.second && !found)
        {
            found = true;
            repeated = number;
        }
    }

    if (found)
        cout << repeated << endl;

    return 0;
}