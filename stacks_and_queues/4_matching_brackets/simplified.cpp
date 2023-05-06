#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    stack<int> stack {};

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            stack.push(i);
        }
        else if (input[i] == ')')
        {
            cout << input.substr(stack.top(), i - stack.top() + 1) << endl;
            stack.pop();
        }
        else 
        {
            continue;
        }
    }

    return 0;
}