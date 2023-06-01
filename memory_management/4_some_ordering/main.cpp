#include <iostream>
#include <memory>
#include <sstream>


using namespace std;

int main() {
    string input;
    getline(cin, input);

    char* myStr = new char[1000];
    char c;
    size_t myStrSize = 0;
    
    for (int i = 0; i < input.size(); i++)
        myStr[i] = input[i];
    myStrSize = input.size();

    for(size_t i = 0; i < myStrSize; i++)
        cout << static_cast<char>(::tolower(myStr[i]));
    cout << endl;
    for(size_t i = 0; i < myStrSize; i++)
        cout << static_cast<char>(::toupper(myStr[i]));
    cout << endl;



    return 0;
}