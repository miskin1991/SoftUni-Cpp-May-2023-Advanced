#include <iostream>
#include <sstream>
#include <map>
#include <vector>

typedef std::pair<std::string, std::vector<std::string>> CountryCityPair;
typedef std::map<std::string, std::vector<std::string>> CountryCitiesMap;

int main()
{
    using namespace std;
    int inputs = 0;
    string input;
    string continent, country, city;
    map<string, CountryCitiesMap> metadata {};
    vector<string> continentsOrder {}, countriesOrder {};

    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> inputs;
    }

    while(inputs--)
    {
        getline(cin, input);
        stringstream buffer(input);
        buffer >> continent >> country >> city;

        auto continentIt = metadata.find(continent);
        if (continentIt == metadata.end())
        {

            CountryCitiesMap newCountry { CountryCityPair(country, vector<string>(1, city))};
            metadata.insert( pair<string, CountryCitiesMap>(continent, newCountry));
            continentsOrder.push_back(continent);
            countriesOrder.push_back(country);
        }
        else
        {
            auto countryIt = continentIt->second.find(country);
            if (countryIt == continentIt->second.end())
            {
                continentIt->second.insert(CountryCityPair(country, vector<string>(1, city)));
                countriesOrder.push_back(country);
            }
            else
            {
                countryIt->second.push_back(city);
            }
        }
    }

    for (auto& continent : continentsOrder)
    {
        cout << continent << ":" << endl;
        auto continentIt = metadata.find(continent);
        for (auto& country : countriesOrder)
        {
            auto countryIt = continentIt->second.find(country);
            if (countryIt != continentIt->second.end())
            {
                cout << "  " << country << " -> ";
                for (int i = 0; i < countryIt->second.size() - 1; i++)
                {
                    cout << countryIt->second.at(i) << ", ";
                }
                cout << countryIt->second.at(countryIt->second.size() - 1) << endl;
            }
        }
    }

    return 0;
}