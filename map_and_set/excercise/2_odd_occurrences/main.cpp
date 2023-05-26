#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string, int> words;
    vector<string> wordsOrdered;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> input)
    {
        for (char& letter : input)
        {
            letter = std::tolower(letter);
        }
        auto it { words.find(input) };
        if (it != words.end()) {
            it->second++;
        }
        else {
            words.insert(pair<string,int>(input, 1));
            wordsOrdered.push_back(input);
        }
    }
    
    input.clear();
    for(size_t i { 0 }; i < wordsOrdered.size(); i++) {
        auto& count { words[wordsOrdered.at(i)] };
        if (count % 2) {
            input.append(wordsOrdered.at(i)).append(", ");
        }
    }
    input.erase(input.size() - 2);
    cout << input << endl;

    return 0;
}