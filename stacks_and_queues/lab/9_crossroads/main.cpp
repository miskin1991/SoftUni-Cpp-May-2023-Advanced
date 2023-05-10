#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{
    string input;

    int greenT = 0, greenTCopy = 0;
    getline(cin, input);
    greenT = atoi(input.c_str());
    greenTCopy = greenT;
    int safeT = 0;
    getline(cin, input);
    safeT = atoi(input.c_str());

    int totalCars = 0;

    queue<string> cars;

    while (true)
    {
        getline(cin, input);

        if (input == "end")
        {
            break;
        }
        else if ( input == "green")
        {
            while(greenT && cars.size())
            {
                input = cars.front();
                int remain = greenT + safeT;
                if(input.length() <= greenT)
                {
                    cars.pop();
                    greenT -= input.length();
                    totalCars++;
                }
                else if (input.length() <= remain )
                {
                    cars.pop();
                    totalCars++;
                    break;
                }
                else
                {
                    cout << input << " was hit at " << input[remain] << endl;
                    return -1;
                }
            }
            greenT = greenTCopy;
        }
        else
        {
            cars.push(input);
        }
    }

    cout << "Everyone is safe\n" << totalCars << " total cars passed the crossroads" << endl;
    return 0;
}