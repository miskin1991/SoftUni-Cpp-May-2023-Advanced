#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    int carsToPass = 0, passedCars = 0;
    string input;
    queue<string> cars;

    getline(cin, input);
    carsToPass = atoi(input.c_str());

    while (true)
    {
        getline(cin, input);

        if (input == "end")
        {
            cout << passedCars << " cars passed the crossroad." << endl;
            break;
        }
        else if ( input == "green")
        {
            for (int i = 0; i < carsToPass; i++)
            {
                input = cars.front();
                cars.pop();
                cout << input << " passed!" << endl;
                passedCars++;
                if (cars.empty())
                    break;
            }
        }
        else
        {
            cars.push(input);
        }
    }

    return 0;
}