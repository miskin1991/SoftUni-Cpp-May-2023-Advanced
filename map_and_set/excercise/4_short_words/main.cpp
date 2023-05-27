#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<string> words;
    string input;
    getline(cin, input);
    stringstream buffer(input);
    while(buffer >> input)
    {
        for (char& letter : input)
        {
            letter = std::tolower(letter);
        }
        words.insert(input);
    }
    
    input.clear();
    for(auto word : words) {
        if(word.size() < 5)
            input.append(word).append(", ");
    }
    input.erase(input.size() - 2);
    cout << input << endl;

    return 0;
}