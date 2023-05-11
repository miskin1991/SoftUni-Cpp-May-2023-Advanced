#include <iostream>
#include <sstream>
#include <stack>

/*
{[()]} -> YES
{[(])} -> NO
{{[[(())]]}} -> YES
*/

int main()
{
    using namespace std;

    string input;
    getline(cin, input);
    stack<char> symbols;

    for(char& symbol : input)
    {
        char opening = 0;
        switch (symbol)
        {
            case '{':
            case '[':
            case '(':
                symbols.push(symbol);
                break;
            case '}':
                opening = '{';
                break;
            case ']':
                opening = '[';
                break;
            case ')':
                opening = '(';
                break;
        }

        if (opening)
        {
            if (symbols.empty() || symbols.top() != opening)
            {
                cout << "NO" << endl;
                return 0;
            }
            symbols.pop();

        }
        
    }

    cout << "YES" << endl;

    return 0;
}