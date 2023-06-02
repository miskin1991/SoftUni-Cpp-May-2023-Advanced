#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

bool FindLetter(string& word, char& letter) {  
    for(char& c : word) {
        if (tolower(c) == tolower(letter)) {
            return true;
        }
    }
    return false;
}

int main() {
    string input;
    getline(cin, input);

    for(char& letter : input) {
        if (!isalpha(letter)) {
            letter = ' ';
        }
    }

    stringstream sstr(input);
    vector<string> words;

    while(sstr >> input) 
        words.push_back(input);

    vector<char> letters;
    while(true) {
        char letter;
        cin >> letter; cin.ignore();
        if (letter == '.')
            break;
        letters.push_back(letter);
    }

    for(char letter : letters) {
        set<string> foundWords;
        bool found = false;
        for (string word : words) {
            if(FindLetter(word, letter)) {
                foundWords.insert(word);
            }
        }
        if(foundWords.empty())
            cout << "---";
        else {
            for(const string& word : foundWords) {
                cout << word << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

/*
You are given a text in English. Let's define a word as any sequence of alphabetical characters. Each of those characters we'll call a letter, but we will consider the uppercase and lowercase variant of a character in a word as the same letter.
a
Y
h
.
*/