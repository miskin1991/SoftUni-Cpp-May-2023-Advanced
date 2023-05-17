#include <iostream>
#include <sstream>
#include <list>
#include <set>
#include <algorithm>

void RemoveCar(std::string const& plate, std::list<std::string>& cars)
{
    using namespace std;
    auto it { std::find(cars.begin(), cars.end(), plate) };
    if (it != cars.end())
        cars.erase(it);
    return;
}

int main()
{
    using namespace std;
    string input, action, plate;
    list<string> cars;
    set<string> uniqueCars;

    while (true)
    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> action >> plate;
        // remove ',' char if exists
        for (char& letter : action)
        {
            if (ispunct(letter))
                action.erase(action.find(letter));
        }
        // set action to lowercase
        for (char& letter : action)
        {
            letter = std::tolower(letter);
        }

        if (action == "end")
            break;
        else
        {
            if (action == "in")
            {
                if(uniqueCars.empty())
                {
                    uniqueCars.insert(plate);
                    cars.push_back(plate);
                }
                else
                {
                    auto it { uniqueCars.find(plate) };
                    if (it == uniqueCars.end())
                    {
                        uniqueCars.insert(plate);
                        cars.push_back(plate);
                    }
                }

            }
            else
            {
                auto it { uniqueCars.find(plate) };
                if (it != uniqueCars.end())
                {
                    uniqueCars.erase(it);
                    RemoveCar(plate, cars);
                }
            }
        }
    }

    if (cars.empty())
    {
        cout << "Parking Lot is Empty" << endl;
    }
    else
    {
        for (string& car : cars)
            cout << car << endl;
    }

    return 0;
}