#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>


int main()
{
    using namespace std;
    
    string input, name;
    int inputs = 0;
    float grade;
    map<std::string, std::vector<float>> students;
    vector<string> names;
    
    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> inputs;
    }

    while(inputs--)
    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> name >> grade;

        auto it { students.find(name) };
        if (it != students.end())
        {
            it->second.push_back(grade);
        }
        else
        {
            students.insert(make_pair(name, vector<float>(1, grade)));
            names.push_back(name);
        }
    }

    for (string name : names)
    {
        cout << name << " -> ";
        auto it = students.find(name);
        float avarage = 0;
        for (float grade : it->second)
        {
            cout << setprecision(2) << fixed << grade << " ";
            avarage += grade;
        }
        avarage /= it->second.size();
        cout << "(avg: " << setprecision(2) << fixed << avarage << ")" << endl;
    }
    return 0;
}