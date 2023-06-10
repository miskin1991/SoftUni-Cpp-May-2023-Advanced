#include <iostream>
#include <sstream>
#include <map>

using namespace std;

bool InRange(map<int,int>& ranges, int value) {

    size_t middle { ranges.size() / 2 };
    map<int, int>::iterator it { std::next(ranges.begin(), middle) };

    if( it->first >= value) {
        for (auto elementIt { ranges.begin() }; elementIt != std::next(it); elementIt++)
        {
            if( elementIt->first <= value && value <= elementIt->second) {
                return true;
            }
        }
    } else {
        for (auto elementIt { it }; elementIt != ranges.end(); elementIt++)
        {
            if( elementIt->first <= value && value <= elementIt->second) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string input;
    map<int,int> ranges {};
    int start, end, value;

    while(true) {
        getline(cin, input);

        if(input[0] == '.') {
            break;
        }

        stringstream buffer(input);
        buffer >> start >> end;

        ranges[start] = end;
    }

    if (ranges.size() > 10000)
        return 0;

    int execCounter = 0;
    while(true) {
        getline(cin, input);

        if(input[0] == '.') {
            break;
        }

        stringstream buffer(input);
        buffer >> value;

        if(InRange(ranges, value)) {
            cout << "in" << endl;
        } else {
            cout << "out" << endl;
        }

        execCounter++;

        if(execCounter > 100000) {
            return 0;
        }
    }

    return 0;
}